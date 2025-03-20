
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAMME = 258,
     VAR = 259,
     begin = 260,
     END = 261,
     INTEGER = 262,
     FLOAT = 263,
     CONST = 264,
     IF = 265,
     ELSE = 266,
     FOR = 267,
     WHILE = 268,
     READLN = 269,
     WRITELN = 270,
     IDF = 271,
     string = 272,
     INT = 273,
     cstReel = 274,
     ADD = 275,
     SOUS = 276,
     MULTI = 277,
     DIV = 278,
     AFF = 279,
     AND = 280,
     OR = 281,
     NOT = 282,
     ACC_OUV = 283,
     ACC_FER = 284,
     PAR_G = 285,
     PAR_D = 286,
     CROCHET_G = 287,
     CROCHET_D = 288,
     SUP = 289,
     INF = 290,
     SUP_EGALE = 291,
     INF_EGALE = 292,
     EGALE = 293,
     DIFFERENT = 294,
     PVG = 295,
     VERGULE = 296,
     AP = 297,
     DP = 298,
     CMT_SIMPLE = 299,
     CMT_MULTI = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 56 "p.y"
 
    int entier; 
    float reel;
    char* str;
    struct {
        char* value;
        char* type;
    } exp;



/* Line 1676 of yacc.c  */
#line 109 "p.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


