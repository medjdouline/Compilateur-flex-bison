%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "p.tab.h"

// fonctions utilisées
int yyerror(char * msg);  // Gestion des erreurs syntaxiques
int yylex(void);         // Analyse lexicale
int yywrap();            // finalisation de l'analyse
extern int nb_ligne;     // Compteur pour déterminer la ligne où se situe l'erreur
extern int colonne;   // Compteur pour déterminer la colonne où se situe l'erreur

int i,t;
char idfType[20];
int inStruct;
int isElse;
char for_vars[50][50];  // Pile pour stocker les variables de boucle
int for_depth = 0;

// Ajout des variables manquantes pour la boucle FOR
char for_var[50];      // Variable de contrôle de la boucle
int for_init;          // Valeur initiale
int for_limit;         // Valeur limite
char pas[20];         // Pas d'incrémentation

char sauvIdf[50][50];
char sauvType[20][50];
int sauvTaille[50];
char sauvTypeAff[20];
int isAffect;
char saveCst[25];
int qc;
#define MAX_STACK 100
int stack[MAX_STACK];  // Pile pour sauvegarder les positions
int stack_top = 0; 

void push(int value) {
    if (stack_top < MAX_STACK) {
        stack[stack_top++] = value;
    }
}

int pop() {
    if (stack_top > 0) {
        return stack[--stack_top];
    }
    return -1;
}

%}
%{
int yylex();
%}
%union 
{ 
    int entier; 
    float reel;
    char* str;
    struct {
        char* value;
        char* type;
    } exp;
}

// Définition des tokens
%token PROGRAMME VAR begin END 
%token INTEGER FLOAT CONST
%token IF ELSE FOR WHILE READLN WRITELN
%token <str> IDF 
%token <str> string 
%token <entier> INT 
%token <reel> cstReel
%token ADD SOUS MULTI DIV AFF AND OR NOT
%token ACC_OUV ACC_FER PAR_G PAR_D CROCHET_G CROCHET_D
%token SUP INF SUP_EGALE INF_EGALE EGALE DIFFERENT
%token PVG VERGULE AP DP
%token CMT_SIMPLE CMT_MULTI 


%type <exp> IDAFF
%type <exp> expression
%type <str> condition
%type <str> compaison

// priorités des opérateurs
%left OR
%left AND
%left ADD SOUS
%left MULTI DIV
%left SUP SUP_EGALE EGALE DIFFERENT INF_EGALE INF
%right AFF
%nonassoc NOT


// début de l'analyse syntaxique
%start S

%%
// règles de grammaire

// programme global
S: PROGRAMME IDF VAR ACC_OUV DEC ACC_FER begin CODE END
    {   insererTYPE($2, "PROGRAM ID");
        printf("syntaxe correcte\n");  // indique que la syntaxe est correcte
        return 0;
    }
;

// Déclaration de variables
DEC:
    DEC_VARS           
    |   /* vide */     // (vide)
;

// Liste des déclarations de variables
DEC_VARS:
    DEC_VAR            // une seule déclaration
    | DEC_VARS DEC_VAR // plusieurs déclarations
;

DEC_VAR:
    SIMPLE_DEC         
    | TABLEAU_DEC      // tableau
    | CST_DEC          // constante
;

SIMPLE_DEC:
    TYPE LISTE_VAR PVG // déclaration d'une seule ou une suite de var ex int a,b,c;
;


// types de variables (int/float)
TYPE:
    INTEGER  {
        if(inStruct){
            int s;
            for(s=t; s<=i; s++){
                sprintf(sauvType[s], "INTEGER");
                t = s;
            }
            t++;
        }
        else{
            sprintf(idfType, "INTEGER");
        }
    }          
    | FLOAT  {
        if(inStruct){
            int s = t;
            for(s=t; s<=i; s++){
                sprintf(sauvType[s], "FLOAT");
                t = s;
            }
            t++;
        }
        else{
            sprintf(idfType, "FLOAT");
        }
    }          
;

// Déclaration constante
CST_DEC:
    CONST IDF AFF INT PVG {
                if(doubleDeclaration($2) != 0) printf("\nErreur semantique ,ligne %d , colonne %d , %s : Constante deja declaree.\n", nb_ligne, colonne, $2);
                else{ 
                     insererTYPE($2, "INTEGER");
                     char temp[50];
                     sprintf(temp, "%d", $4);
                     setConst($2, temp);
                }
            }
    |CONST IDF AFF cstReel PVG {
                if(doubleDeclaration($2) != 0) printf("\nErreur semantique ,ligne %d , colonne %d , %s: Constante deja declaree.\n", nb_ligne, colonne, $2);
                else{ 
                     insererTYPE($2, "FLOAT");
                     char temp[50];
                     sprintf(temp, "%f", $4);
                     setConst($2, temp);
                }
            }
;

LISTE_VAR:
    IDF {
        if(inStruct){
            sauvTaille[i] = 0;
            sprintf(sauvIdf[i], "%s", $1);
            i++;
        }
        else{
            if(doubleDeclaration($1) != 0) printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable deja declaree.\n", nb_ligne, colonne, $1);
            else{ 
                insererTYPE($1, idfType);
                if(isStruct(idfType)){
                    insertStruct($1, idfType);
                }
            }
        }
}               // Une seule variable
    | LISTE_VAR VERGULE IDF  {
        if(inStruct){
            sauvTaille[i] = 0;
            sprintf(sauvIdf[i], "%s", $3);
            i++;
        }
        else{
            if(doubleDeclaration($3) != 0) printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable deja declaree.\n", nb_ligne, colonne, $3);
            else{ 
                insererTYPE($3, idfType);
                if(isStruct(idfType)){
                    insertStruct($3, idfType);
                }
            }
        }
} // Plusieurs variables
;

// Déclaration tableau
TABLEAU_DEC:
    TYPE IDF CROCHET_G INT CROCHET_D PVG  {
        if(inStruct){
            char temp[50];
            sauvTaille[i] = $4;
            sprintf(temp, "%s", sauvType[i]);
            sprintf(sauvType[i], "ARRAY OF %s", temp);
            sprintf(sauvIdf[i], "%s", $2);
            i++;
        }
        else{
            if(doubleDeclaration($2) != 0) printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable deja declaree.\n", nb_ligne, colonne, $2);
            else if($4 <= 0) printf("\nErreur semantique ,ligne %d, colonne %d : Taille tableau negative.\n", nb_ligne, colonne);
            else{ 
                char temp[50];
                sprintf(temp, "ARRAY OF %s", idfType);
                insererTYPE($2, temp);
                setArraySize($2, $4);

                if(isStruct(idfType)){
                    insertStruct($2, idfType);
                }
            }
        }
    }
;

// Expressions
expression:
    expression ADD expression {
              char temp[50];
            sprintf(temp, "T%d", qc); // Générer un nouveau nom temporaire
            
            // Vérifier la compatibilité des types
            if(!isCompatible($1.type, $3.type)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans l'addition \n", 
                       nb_ligne, colonne, $1.type, $3.type);
            }
            quadr("+", $1.value, $3.value, temp);
            $$.value = strdup(temp);
            // Le type résultant est FLOAT si l'un des opérandes est FLOAT
            if(strcmp($1.type, "FLOAT") == 0 || strcmp($3.type, "FLOAT") == 0) {
                $$.type = strdup("FLOAT");
            } else {
                $$.type = strdup("INTEGER");
            }
         }
    | expression SOUS expression {
            char temp[50];
            sprintf(temp, "T%d", qc);
            
            if(!isCompatible($1.type, $3.type)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans la soustraction \n", 
                       nb_ligne, colonne, $1.type, $3.type);
            }
            quadr("-", $1.value, $3.value, temp);
            $$.value = strdup(temp);
            if(strcmp($1.type, "FLOAT") == 0 || strcmp($3.type, "FLOAT") == 0) {
                $$.type = strdup("FLOAT");
            } else {
                $$.type = strdup("INTEGER");
            }
         }
    | expression MULTI expression {
            char temp[50];
sprintf(temp, "T%d", qc);
            
            if(!isCompatible($1.type, $3.type)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans la multiplication \n", 
                       nb_ligne, colonne, $1.type, $3.type);
            }
            quadr("*", $1.value, $3.value, temp);
            $$.value = strdup(temp);
            if(strcmp($1.type, "FLOAT") == 0 || strcmp($3.type, "FLOAT") == 0) {
                $$.type = strdup("FLOAT");
            } else {
                $$.type = strdup("INTEGER");
            }
         }
    | expression DIV expression {
     char temp[50];
     sprintf(temp, "T%d", qc);

     // Vérifier à la fois "0" et "0.0"
     if (strcmp($3.value, "0") == 0 || strcmp($3.value, "0.0") == 0) {
         printf("\nErreur semantique, ligne %d, colonne %d: Division par zero.\n", nb_ligne, colonne);
         $$.type = strdup("ERROR");
     } 
         // Vérification de la compatibilité des types
         if (!isCompatible($1.type, $3.type)) {
             printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans la division \n", 
                    nb_ligne, colonne);
             $$.type = strdup("ERROR");
         } 
             quadr("/", $1.value, $3.value, temp);
             $$.value = strdup(temp);
             $$.type = strdup("FLOAT"); // Division always results in FLOAT


}
    | IDF CROCHET_G INT CROCHET_D {
    if(doubleDeclaration($1) == 0) {
        printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable non declaree.\n", nb_ligne, colonne, $1);
        $$.type = strdup("ERROR");
        $$.value = strdup("");
    }
    else {
        if(!isArray($1)) {
            printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable n'est pas un tableau.\n", nb_ligne, colonne, $1);
            $$.type = strdup("ERROR");
            $$.value = strdup("");
        }
        else if(isOutOfRange($1, $3)) {
            printf("\nErreur semantique ,ligne %d, colonne %d: Index out of range.\n", nb_ligne, colonne);
            $$.type = strdup("ERROR");
            $$.value = strdup("");
        }
        else {
            char temp[50];
            sprintf(temp, "%s[%d]", $1, $3);
            $$.value = strdup(temp);
            sprintf(temp, "%d", arrayElementType($1));
            $$.type = strdup(temp);
        }
    }
}
    | IDF CROCHET_G IDF CROCHET_D{
            if(doubleDeclaration($1) == 0) {
                printf("\nErreur semantique, ligne %d, colonne %d: Variable %s non declaree\n", 
                       nb_ligne, colonne, $1);
                $$.type = strdup("ERROR");
            } else {
                if(!isArray($1)) {
                    printf("\nErreur semantique, ligne %d, colonne %d: %s n'est pas un tableau\n", 
                           nb_ligne, colonne, $1);
                    $$.type = strdup("ERROR");
                } else if(isOutOfRange($1, $3)) {
                    printf("\nErreur semantique, ligne %d, colonne %d: Index hors limites\n", 
                           nb_ligne, colonne);
                    $$.type = strdup("ERROR");
                } else {
                    char temp[50];
                    sprintf(temp, "%s[%d]", $1, $3);
                    $$.value = strdup(temp);
                    sprintf(temp, "%d", arrayElementType($1));
                    $$.type = strdup(temp);
                }
            }
         }
    | PAR_G expression PAR_D {
            $$.value = $2.value;
            $$.type = $2.type;
         }
    | INT {
            char temp[50];
            sprintf(temp, "%d", $1);
            $$.value = strdup(temp);
            $$.type = strdup("INTEGER");
          strcpy(saveCst, temp);
         }
    | cstReel {
            char temp[50];
            sprintf(temp, "%f", $1);
            $$.value = strdup(temp);
            $$.type = strdup("FLOAT");
          // Copie de la chaîne convertie dans saveCst
          strcpy(saveCst, temp);
         }
    | IDF   {
            if(doubleDeclaration($1) == 0) {
                printf("\nErreur semantique, ligne %d, colonne %d: Variable %s non declaree\n", 
                       nb_ligne, colonne, $1);
                $$.type = strdup("ERROR");
            } else {
                $$.value = strdup($1);
                char temp[50];
                sprintf(temp, "%d", getType($1));
                $$.type = strdup(temp);
            }
            
         }
;


compaison:
    expression SUP expression {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr(">", $1.value, $3.value, temp);
        $$ = strdup(temp);
        
    }       
    | expression INF expression {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("<", $1.value, $3.value, temp);
        $$ = strdup(temp);
        
    }      
    | expression SUP_EGALE expression {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr(">=", $1.value, $3.value, temp);
        $$ = strdup(temp);
       
    }
    | expression INF_EGALE expression {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("<=", $1.value, $3.value, temp);
        $$ = strdup(temp);
        
    }
    | expression EGALE expression {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("==", $1.value, $3.value, temp);
        $$ = strdup(temp);
        
    }     
    | expression DIFFERENT expression {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("!=", $1.value, $3.value, temp);
        $$ = strdup(temp);
       
    }
;

CODE:
    INSTRUCTION         // Une 
    | CODE INSTRUCTION  // ou plusieurs instructions
;



// Condition
condition: 
    condition AND condition {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("&&", $1, $3, temp);
        $$ = strdup(temp);
        
    }      
    | condition OR condition {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("||", $1, $3, temp);
        $$ = strdup(temp);
        
    }     
    | NOT condition {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("!", $2, "", temp);
        $$ = strdup(temp);
       
    }
    | PAR_G condition PAR_D {
        $$ = strdup($2);  // Pas besoin de nouveau quadruplet, juste transmettre le résultat
    }
    | compaison {
        $$ = strdup($1);  // Le résultat de la comparaison est déjà dans un temporaire
    }              
;
AFFECTATION:
    IDAFF AFF expression PVG {
        if(strcmp($1.type, "ERROR") != 0 && strcmp($3.type, "ERROR") != 0) {
            if(!isCompatible($1.type, $3.type)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans l'affectation \n", 
                       nb_ligne, colonne);
            }
        }
        isAffect = 0;
        quadr("=", $3.value, "", $1.value); // Utiliser la valeur de l'expression
    }
;
INSTRUCTION:
    AFFECTATION       
    | IFINST          
    | FORINST      
    | WHILEINST     
    | READ_WRITE              
;
IDAFF:
    IDF {
            if(doubleDeclaration($1) == 0) {
                printf("\nErreur semantique, ligne %d, colonne %d: Variable %s non declaree\n", 
                       nb_ligne, colonne, $1);
                $$.type = strdup("ERROR");
            } else if(isConst($1)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Tentative de modification de la constante %s\n", 
                       nb_ligne, colonne, $1);
                $$.type = strdup("ERROR");
            } else {
                $$.value = strdup($1);
                char temp[50];
                sprintf(temp, "%d", getType($1));
                $$.type = strdup(temp);
                sprintf(sauvTypeAff, "%s", getType($1));
                isAffect = 1;
            }
         }
    |IDF CROCHET_G INT CROCHET_D {
            if(doubleDeclaration($1) == 0) {
                printf("\nErreur semantique, ligne %d, colonne %d: Variable %s non declaree\n", 
                       nb_ligne, colonne, $1);
                $$.type = strdup("ERROR");
            } else {
                if(!isArray($1)) {
                    printf("\nErreur semantique, ligne %d, colonne %d: %s n'est pas un tableau\n", 
                           nb_ligne, colonne, $1);
                    $$.type = strdup("ERROR");
                } else if(isOutOfRange($1, $3)) {
                    printf("\nErreur semantique, ligne %d, colonne %d: Index hors limites\n", 
                           nb_ligne, colonne);
                    $$.type = strdup("ERROR");
                } else {
                    char temp[50];
                    sprintf(temp, "%s[%d]", $1, $3);
                    $$.value = strdup(temp);
                    sprintf(temp, "%d", arrayElementType($1));
                    $$.type = strdup(temp);
                    sprintf(sauvTypeAff, "%s", arrayElementType($1));
                    isAffect = 1;
                }
            }
         }
; 

IFINST: IFINST_1 PAR_D ACC_OUV CODE ACC_FER {
            char temp[50];
            sprintf(temp, "%d", qc);
            int x = pop();
            ajour_quad(x, 3, temp);
}
      | IFINST_2 ELSE ACC_OUV CODE ACC_FER {
            char temp[50];
            sprintf(temp, "%d", qc);
            int x = pop();
            ajour_quad(x, 3, temp);
}
;

IFINST_1: IF PAR_G condition {
            
            quadr("BZ", "", $3, ""); // Saut si la condition est fausse
            push(qc-1);
}
;

IFINST_2: IFINST_1 PAR_D ACC_OUV CODE ACC_FER {
            char temp[50];
            
            quadr("BR", "", "", "");
            int x = pop();
            push(qc-1);
            sprintf(temp, "%d", qc);
            
            
            ajour_quad(x, 3, temp);
}
;


FORINST:
    FOR PAR_G IDF DP INT DP INT DP expression PAR_D {
        if(doubleDeclaration($3) == 0) {
            printf("\nErreur semantique %d:%d - %s: Variable non declaree.\n", nb_ligne, colonne, $3);
        } else {
            // Sauvegarder la variable de boucle courante
            strcpy(for_vars[for_depth], $3);
            for_depth++;
            
            // 1. Initialisation de la variable
            char start[20];
            sprintf(start, "%d", $5);
            quadr("=", start, "", for_vars[for_depth-1]);
            
            // 2. Position de début pour le test
            int debut_test = qc;
            
            // 3. Test par rapport à la limite
            char temp_cond[20];
            sprintf(temp_cond, "T%d", qc);
            quadr("<=", for_vars[for_depth-1], $9.value, temp_cond);
            
            // 4. Saut conditionnel
            quadr("BZ", "", temp_cond, "");
            int pos_bz = qc - 1;
            
            // Sauvegarder les positions importantes
            push(pos_bz);
            push(debut_test);
        }
    } ACC_OUV CODE ACC_FER {
            // Récupérer les positions sauvegardées
            int debut_test = pop();
            int pos_bz = pop();
            
            // 5. Incrémentation
            char pas[20];
            sprintf(pas, "%d", $7);
            char temp_incr[20];
            sprintf(temp_incr, "T%d", qc);
            
            // Utiliser la variable de la bonne profondeur
            quadr("+", for_vars[for_depth-1], pas, temp_incr);
            quadr("=", temp_incr, "", for_vars[for_depth-1]);
            
            // 6. Saut vers le test
            char temp[20];
            sprintf(temp, "%d", debut_test);
            quadr("BR", "", "", temp);
            
            // 7. Mise à jour du BZ
            char qc_str[20];
            sprintf(qc_str, "%d", qc);
            ajour_quad(pos_bz, 3, qc_str);
            
            // Décrémenter la profondeur en sortant de la boucle
            for_depth--;
    }
;



WHILEINST: WHILEINST_2 PAR_D ACC_OUV CODE ACC_FER {
            int saut_condition = pop(); // Récupère l'adresse du saut conditionnel
            int x = pop();  // Récupère l'adresse du début de la boucle
           
            
            char temp[50];
            sprintf(temp, "%d", x);
            quadr("BR", "", "", temp);

            sprintf(temp, "%d", qc);
            ajour_quad(saut_condition, 3, temp);

}
;

WHILEINST_1: WHILE PAR_G{
            push(qc);

}

WHILEINST_2: WHILEINST_1 condition{
            quadr("BZ", "", $2, "");
            push(qc-1);
}




READ_WRITE:
    WRITELN PAR_G string PAR_D PVG 
    | READLN PAR_G IDF PAR_D PVG   
;

%%

int main()
{
  nb_ligne = 1; 
  colonne = 1;
  i = 0;
  t = 0;
  init();
  yyparse();
  afficher();
afficher_qdr();
  return 0;
}

int yywrap(){}

// Fonction d'erreur
int yyerror(char * msg) {
    printf("Erreur syntaxique ,ligne %d, colonne %d\n", nb_ligne, colonne);
    return 0;
}
