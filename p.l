%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p.tab.h"
#include "ts.h"

int nb_ligne = 1;
int colonne = 1;
int col = 1;
int yyleng;
extern YYSTYPE yylval;

%}
chiffres [0-9]
INT {chiffres}+
REEL {chiffres}+"."{chiffres}+
CSTINT (\([+-]?{INT}\))|{INT}
CSTREEL (\([+-]?{REEL}\))|{REEL}
lettres [a-zA-Z]
IDF {lettres}({lettres}|{chiffres})*
CST [0-9]+
STRING \'[^\']*\'
CMT_SIMPLE "//".*
CMT_MULTI "/*"([^*]|\*+[^*/])*\*+"/"

%%
"PROGRAMME"   { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return PROGRAMME; }
"begin"       { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return begin; }
"VAR"         { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return VAR; }
"END"         { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return END; }
"CONST"       { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return CONST; }
"INTEGER"     { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return INTEGER; }
"FLOAT"       { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return FLOAT; }
"IF"          { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return IF; }
"ELSE"        { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return ELSE; }
"FOR"         { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return FOR; }
"WHILE"       { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return WHILE; }
"READLN"      { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return READLN; }
"WRITELN"     { lookup(yytext,"Mot cle"," ",0,1); colonne += yyleng; return WRITELN; }

"+"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return ADD; }
"-"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return SOUS; }
"*"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return MULTI; }
"/"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return DIV; }
"="           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return AFF; }
"&&"          { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return AND; }
"||"          { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return OR; }
"!"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return NOT; }
">"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return SUP; }
"<"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return INF; }
">="          { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return SUP_EGALE; }
"<="          { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return INF_EGALE; }
"=="          { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return EGALE; }
"!="          { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return DIFFERENT; }
","           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return VERGULE; }
":"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return DP; }
";"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return PVG; }
"'"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return AP; }
"{"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return ACC_OUV; }
"}"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return ACC_FER; }
"("           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return PAR_G; }
")"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return PAR_D; }
"["           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return CROCHET_G; }
"]"           { lookup(yytext,"Separateur"," ",0,2); colonne += yyleng; return CROCHET_D; }

{IDF}         {lookup(yytext, "IDF", "", 0, 0);
                 col += yyleng;
                if(yyleng <= 7) {             
                    yylval.str = strdup(yytext);
                    return IDF;
                }
                else printf("Erreur lexicale: identificateur trop long '%s' à la ligne %d, colonne %d\n", yytext, nb_ligne, col);
             }

{STRING}      {
                lookup(yytext, "CST", "STRING", 0, 0);
                yylval.str = strdup(yytext);
                col += yyleng;
                return string;
             }


{CSTINT}      {
                colonne += yyleng;
                int temp = (yytext[0] == '(') ? atoi(yytext+1) : atoi(yytext);
                if(temp <= 32767 && temp >= -32768) {
                    lookup(yytext, "CST", "INTEGER", temp, 0);
                    yylval.entier = temp;
                    return INT;
                }
                else printf("Erreur lexicale à la ligne %d, colonne %d: Entier hors limites\n", nb_ligne, col);
             }

{CSTREEL}     {
                colonne += yyleng;
                float temp = (yytext[0] == '(') ? atof(yytext+1) : atof(yytext);
                lookup(yytext, "CST", "FLOAT", temp, 0);
                yylval.reel = temp;
                return cstReel;
             }

{CMT_SIMPLE}  { /* ignore single-line comments */ }
{CMT_MULTI}   { 
    char* str = yytext;
    char* ptrChar = strchr(str,'\n');
    while (ptrChar != NULL) {
        nb_ligne++;
        ptrChar = strchr(ptrChar+1,'\n');
    }
}

[ \t]+        { colonne += yyleng; col += yyleng; }
\n            { nb_ligne++; colonne = 1; }

. {
    printf("Erreur lexicale a la ligne %d, colonne %d: caractere inconnu '%s'\n", nb_ligne, colonne, yytext);
    return 1;
}
%%



