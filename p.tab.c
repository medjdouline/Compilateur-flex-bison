
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "p.y"

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


/* Line 189 of yacc.c  */
#line 52 "p.y"

int yylex();


/* Line 189 of yacc.c  */
#line 131 "p.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 56 "p.y"
 
    int entier; 
    float reel;
    char* str;
    struct {
        char* value;
        char* type;
    } exp;



/* Line 214 of yacc.c  */
#line 224 "p.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 236 "p.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    13,    15,    16,    18,    21,    23,    25,
      27,    31,    33,    35,    41,    47,    49,    53,    60,    64,
      68,    72,    76,    81,    86,    90,    92,    94,    96,   100,
     104,   108,   112,   116,   120,   122,   125,   129,   133,   136,
     140,   142,   147,   149,   151,   153,   155,   157,   159,   164,
     170,   176,   180,   186,   187,   202,   208,   211,   214,   220
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,     3,    16,     4,    28,    48,    29,     5,
      58,     6,    -1,    49,    -1,    -1,    50,    -1,    49,    50,
      -1,    51,    -1,    55,    -1,    53,    -1,    52,    54,    40,
      -1,     7,    -1,     8,    -1,     9,    16,    24,    18,    40,
      -1,     9,    16,    24,    19,    40,    -1,    16,    -1,    54,
      41,    16,    -1,    52,    16,    32,    18,    33,    40,    -1,
      56,    20,    56,    -1,    56,    21,    56,    -1,    56,    22,
      56,    -1,    56,    23,    56,    -1,    16,    32,    18,    33,
      -1,    16,    32,    16,    33,    -1,    30,    56,    31,    -1,
      18,    -1,    19,    -1,    16,    -1,    56,    34,    56,    -1,
      56,    35,    56,    -1,    56,    36,    56,    -1,    56,    37,
      56,    -1,    56,    38,    56,    -1,    56,    39,    56,    -1,
      61,    -1,    58,    61,    -1,    59,    25,    59,    -1,    59,
      26,    59,    -1,    27,    59,    -1,    30,    59,    31,    -1,
      57,    -1,    62,    24,    56,    40,    -1,    60,    -1,    63,
      -1,    66,    -1,    68,    -1,    71,    -1,    16,    -1,    16,
      32,    18,    33,    -1,    64,    31,    28,    58,    29,    -1,
      65,    11,    28,    58,    29,    -1,    10,    30,    59,    -1,
      64,    31,    28,    58,    29,    -1,    -1,    12,    30,    16,
      43,    18,    43,    18,    43,    56,    31,    67,    28,    58,
      29,    -1,    70,    31,    28,    58,    29,    -1,    13,    30,
      -1,    69,    59,    -1,    15,    30,    17,    31,    40,    -1,
      14,    30,    16,    31,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   112,   113,   118,   119,   123,   124,   125,
     129,   135,   148,   165,   174,   186,   202,   222,   250,   268,
     284,   300,   321,   347,   370,   374,   381,   389,   406,   413,
     420,   427,   434,   441,   451,   452,   459,   466,   473,   480,
     483,   488,   500,   501,   502,   503,   504,   507,   525,   552,
     558,   566,   573,   588,   588,   649,   664,   669,   678,   679
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAMME", "VAR", "begin", "END",
  "INTEGER", "FLOAT", "CONST", "IF", "ELSE", "FOR", "WHILE", "READLN",
  "WRITELN", "IDF", "string", "INT", "cstReel", "ADD", "SOUS", "MULTI",
  "DIV", "AFF", "AND", "OR", "NOT", "ACC_OUV", "ACC_FER", "PAR_G", "PAR_D",
  "CROCHET_G", "CROCHET_D", "SUP", "INF", "SUP_EGALE", "INF_EGALE",
  "EGALE", "DIFFERENT", "PVG", "VERGULE", "AP", "DP", "CMT_SIMPLE",
  "CMT_MULTI", "$accept", "S", "DEC", "DEC_VARS", "DEC_VAR", "SIMPLE_DEC",
  "TYPE", "CST_DEC", "LISTE_VAR", "TABLEAU_DEC", "expression", "compaison",
  "CODE", "condition", "AFFECTATION", "INSTRUCTION", "IDAFF", "IFINST",
  "IFINST_1", "IFINST_2", "FORINST", "$@1", "WHILEINST", "WHILEINST_1",
  "WHILEINST_2", "READ_WRITE", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      51,    52,    52,    53,    53,    54,    54,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    60,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    65,    67,    66,    68,    69,    70,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     1,     0,     1,     2,     1,     1,     1,
       3,     1,     1,     5,     5,     1,     3,     6,     3,     3,
       3,     3,     4,     4,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     2,     3,     3,     2,     3,
       1,     4,     1,     1,     1,     1,     1,     1,     4,     5,
       5,     3,     5,     0,    14,     5,     2,     2,     5,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     4,    11,    12,     0,
       0,     3,     5,     7,     0,     9,     8,     0,     0,     6,
      15,     0,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,    42,    34,     0,    43,
       0,     0,    44,    45,     0,     0,    46,     0,    16,    13,
      14,     0,     0,    56,     0,     0,     0,     2,    35,     0,
       0,     0,    27,    25,    26,     0,     0,     0,    40,    57,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,    48,     0,    41,     0,     0,     0,     0,    24,
      39,    18,    19,    20,    21,    28,    29,    30,    31,    32,
      33,    36,    37,     0,     0,    59,    58,    49,    50,    23,
      22,    55,     0,     0,     0,     0,    53,     0,     0,     0,
      54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    12,    13,    14,    15,    21,    16,
      67,    68,    35,    69,    36,    37,    38,    39,    40,    41,
      42,   137,    43,    44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
       7,    28,    46,    45,   -78,    32,     9,   -78,   -78,    53,
      33,     9,   -78,   -78,    79,   -78,   -78,   123,    98,   -78,
      91,    -3,    66,   125,   111,   -78,   118,   106,   108,   119,
     120,   121,   124,   126,   127,    -1,   -78,   -78,   128,   -78,
     129,   142,   -78,   -78,    56,   130,   -78,   131,   -78,   -78,
     -78,    56,   139,   -78,   141,   145,   140,   -78,   -78,    29,
     135,   137,   134,   -78,   -78,    56,    56,    43,   -78,    76,
     143,   132,    76,   133,   136,   138,   144,    29,     3,   125,
     125,   -12,   -78,    19,    42,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    56,    56,   125,   -78,   150,
     146,   147,   -78,    99,   -78,    77,    84,   148,   149,   -78,
     -78,   110,   110,   -78,   -78,   122,   122,   122,   122,   122,
     122,   -78,   153,    95,   151,   -78,   -78,   159,   -78,   -78,
     -78,   -78,   155,   152,    29,   105,   -78,   156,   125,   102,
     -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   -78,   163,   -78,   -78,   -78,   -78,   -78,
     -58,   -78,   -77,   -44,   -78,   -35,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -53
static const yytype_int16 yytable[] =
{
      58,    78,   105,   106,   107,    57,   108,    72,    83,    29,
       1,    30,    31,    32,    33,    34,     7,     8,     9,   103,
     123,    82,    84,    85,    86,    87,    88,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    25,    26,    85,
      86,    87,    88,   104,     3,    62,     4,    63,    64,     5,
     109,   121,   122,    89,    90,    91,    92,    93,    94,    77,
       6,   139,    18,    85,    86,    87,    88,    95,    96,    17,
      58,    58,    62,   110,    63,    64,   135,    89,    90,    91,
      92,    93,    94,    65,    27,    28,    66,    29,    58,    30,
      31,    32,    33,    34,    29,    20,    30,    31,    32,    33,
      34,    95,    96,    23,    58,    29,   127,    30,    31,    32,
      33,    34,    29,   128,    30,    31,    32,    33,    34,    85,
      86,    87,    88,    24,   131,    85,    86,    87,    88,    47,
     109,   140,    87,    88,    48,    29,   136,    30,    31,    32,
      33,    34,    85,    86,    87,    88,    49,    22,    50,    51,
      52,    53,    59,    61,    54,    73,    55,    74,    76,    56,
      60,    70,    75,    79,    71,    80,    81,   100,   124,   101,
     -52,    97,    98,   133,    19,     0,    99,   102,    95,     0,
       0,   129,   130,     0,   138,     0,   125,   126,     0,     0,
       0,     0,     0,     0,   132,   134
};

static const yytype_int16 yycheck[] =
{
      35,    59,    79,    80,    16,     6,    18,    51,    66,    10,
       3,    12,    13,    14,    15,    16,     7,     8,     9,    77,
      97,    65,    66,    20,    21,    22,    23,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    40,    41,    20,
      21,    22,    23,    40,    16,    16,     0,    18,    19,     4,
      31,    95,    96,    34,    35,    36,    37,    38,    39,    30,
      28,   138,    29,    20,    21,    22,    23,    25,    26,    16,
     105,   106,    16,    31,    18,    19,   134,    34,    35,    36,
      37,    38,    39,    27,    18,    19,    30,    10,   123,    12,
      13,    14,    15,    16,    10,    16,    12,    13,    14,    15,
      16,    25,    26,     5,   139,    10,    29,    12,    13,    14,
      15,    16,    10,    29,    12,    13,    14,    15,    16,    20,
      21,    22,    23,    32,    29,    20,    21,    22,    23,    18,
      31,    29,    22,    23,    16,    10,    31,    12,    13,    14,
      15,    16,    20,    21,    22,    23,    40,    24,    40,    30,
      30,    30,    24,    11,    30,    16,    30,    16,    18,    32,
      31,    31,    17,    28,    33,    28,    32,    31,    18,    31,
      11,    28,    40,    18,    11,    -1,    43,    33,    25,    -1,
      -1,    33,    33,    -1,    28,    -1,    40,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    47,    16,     0,     4,    28,     7,     8,     9,
      48,    49,    50,    51,    52,    53,    55,    16,    29,    50,
      16,    54,    24,     5,    32,    40,    41,    18,    19,    10,
      12,    13,    14,    15,    16,    58,    60,    61,    62,    63,
      64,    65,    66,    68,    69,    70,    71,    18,    16,    40,
      40,    30,    30,    30,    30,    30,    32,     6,    61,    24,
      31,    11,    16,    18,    19,    27,    30,    56,    57,    59,
      31,    33,    59,    16,    16,    17,    18,    30,    56,    28,
      28,    32,    59,    56,    59,    20,    21,    22,    23,    34,
      35,    36,    37,    38,    39,    25,    26,    28,    40,    43,
      31,    31,    33,    56,    40,    58,    58,    16,    18,    31,
      31,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    59,    59,    58,    18,    40,    40,    29,    29,    33,
      33,    29,    43,    18,    43,    56,    31,    67,    28,    58,
      29
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 104 "p.y"
    {   insererTYPE((yyvsp[(2) - (9)].str), "PROGRAM ID");
        printf("syntaxe correcte\n");  // indique que la syntaxe est correcte
        return 0;
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 135 "p.y"
    {
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
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 148 "p.y"
    {
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
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 165 "p.y"
    {
                if(doubleDeclaration((yyvsp[(2) - (5)].str)) != 0) printf("\nErreur semantique ,ligne %d , colonne %d , %s : Constante deja declaree.\n", nb_ligne, colonne, (yyvsp[(2) - (5)].str));
                else{ 
                     insererTYPE((yyvsp[(2) - (5)].str), "INTEGER");
                     char temp[50];
                     sprintf(temp, "%d", (yyvsp[(4) - (5)].entier));
                     setConst((yyvsp[(2) - (5)].str), temp);
                }
            ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 174 "p.y"
    {
                if(doubleDeclaration((yyvsp[(2) - (5)].str)) != 0) printf("\nErreur semantique ,ligne %d , colonne %d , %s: Constante deja declaree.\n", nb_ligne, colonne, (yyvsp[(2) - (5)].str));
                else{ 
                     insererTYPE((yyvsp[(2) - (5)].str), "FLOAT");
                     char temp[50];
                     sprintf(temp, "%f", (yyvsp[(4) - (5)].reel));
                     setConst((yyvsp[(2) - (5)].str), temp);
                }
            ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 186 "p.y"
    {
        if(inStruct){
            sauvTaille[i] = 0;
            sprintf(sauvIdf[i], "%s", (yyvsp[(1) - (1)].str));
            i++;
        }
        else{
            if(doubleDeclaration((yyvsp[(1) - (1)].str)) != 0) printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable deja declaree.\n", nb_ligne, colonne, (yyvsp[(1) - (1)].str));
            else{ 
                insererTYPE((yyvsp[(1) - (1)].str), idfType);
                if(isStruct(idfType)){
                    insertStruct((yyvsp[(1) - (1)].str), idfType);
                }
            }
        }
;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 202 "p.y"
    {
        if(inStruct){
            sauvTaille[i] = 0;
            sprintf(sauvIdf[i], "%s", (yyvsp[(3) - (3)].str));
            i++;
        }
        else{
            if(doubleDeclaration((yyvsp[(3) - (3)].str)) != 0) printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable deja declaree.\n", nb_ligne, colonne, (yyvsp[(3) - (3)].str));
            else{ 
                insererTYPE((yyvsp[(3) - (3)].str), idfType);
                if(isStruct(idfType)){
                    insertStruct((yyvsp[(3) - (3)].str), idfType);
                }
            }
        }
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 222 "p.y"
    {
        if(inStruct){
            char temp[50];
            sauvTaille[i] = (yyvsp[(4) - (6)].entier);
            sprintf(temp, "%s", sauvType[i]);
            sprintf(sauvType[i], "ARRAY OF %s", temp);
            sprintf(sauvIdf[i], "%s", (yyvsp[(2) - (6)].str));
            i++;
        }
        else{
            if(doubleDeclaration((yyvsp[(2) - (6)].str)) != 0) printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable deja declaree.\n", nb_ligne, colonne, (yyvsp[(2) - (6)].str));
            else if((yyvsp[(4) - (6)].entier) <= 0) printf("\nErreur semantique ,ligne %d, colonne %d : Taille tableau negative.\n", nb_ligne, colonne);
            else{ 
                char temp[50];
                sprintf(temp, "ARRAY OF %s", idfType);
                insererTYPE((yyvsp[(2) - (6)].str), temp);
                setArraySize((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].entier));

                if(isStruct(idfType)){
                    insertStruct((yyvsp[(2) - (6)].str), idfType);
                }
            }
        }
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 250 "p.y"
    {
              char temp[50];
            sprintf(temp, "T%d", qc); // Générer un nouveau nom temporaire
            
            // Vérifier la compatibilité des types
            if(!isCompatible((yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans l'addition \n", 
                       nb_ligne, colonne, (yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type);
            }
            quadr("+", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
            (yyval.exp).value = strdup(temp);
            // Le type résultant est FLOAT si l'un des opérandes est FLOAT
            if(strcmp((yyvsp[(1) - (3)].exp).type, "FLOAT") == 0 || strcmp((yyvsp[(3) - (3)].exp).type, "FLOAT") == 0) {
                (yyval.exp).type = strdup("FLOAT");
            } else {
                (yyval.exp).type = strdup("INTEGER");
            }
         ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 268 "p.y"
    {
            char temp[50];
            sprintf(temp, "T%d", qc);
            
            if(!isCompatible((yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans la soustraction \n", 
                       nb_ligne, colonne, (yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type);
            }
            quadr("-", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
            (yyval.exp).value = strdup(temp);
            if(strcmp((yyvsp[(1) - (3)].exp).type, "FLOAT") == 0 || strcmp((yyvsp[(3) - (3)].exp).type, "FLOAT") == 0) {
                (yyval.exp).type = strdup("FLOAT");
            } else {
                (yyval.exp).type = strdup("INTEGER");
            }
         ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 284 "p.y"
    {
            char temp[50];
sprintf(temp, "T%d", qc);
            
            if(!isCompatible((yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans la multiplication \n", 
                       nb_ligne, colonne, (yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type);
            }
            quadr("*", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
            (yyval.exp).value = strdup(temp);
            if(strcmp((yyvsp[(1) - (3)].exp).type, "FLOAT") == 0 || strcmp((yyvsp[(3) - (3)].exp).type, "FLOAT") == 0) {
                (yyval.exp).type = strdup("FLOAT");
            } else {
                (yyval.exp).type = strdup("INTEGER");
            }
         ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 300 "p.y"
    {
     char temp[50];
     sprintf(temp, "T%d", qc);

     // Vérifier à la fois "0" et "0.0"
     if (strcmp((yyvsp[(3) - (3)].exp).value, "0") == 0 || strcmp((yyvsp[(3) - (3)].exp).value, "0.0") == 0) {
         printf("\nErreur semantique, ligne %d, colonne %d: Division par zero.\n", nb_ligne, colonne);
         (yyval.exp).type = strdup("ERROR");
     } 
         // Vérification de la compatibilité des types
         if (!isCompatible((yyvsp[(1) - (3)].exp).type, (yyvsp[(3) - (3)].exp).type)) {
             printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans la division \n", 
                    nb_ligne, colonne);
             (yyval.exp).type = strdup("ERROR");
         } 
             quadr("/", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
             (yyval.exp).value = strdup(temp);
             (yyval.exp).type = strdup("FLOAT"); // Division always results in FLOAT


;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 321 "p.y"
    {
    if(doubleDeclaration((yyvsp[(1) - (4)].str)) == 0) {
        printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable non declaree.\n", nb_ligne, colonne, (yyvsp[(1) - (4)].str));
        (yyval.exp).type = strdup("ERROR");
        (yyval.exp).value = strdup("");
    }
    else {
        if(!isArray((yyvsp[(1) - (4)].str))) {
            printf("\nErreur semantique ,ligne %d, colonne %d, %s: Variable n'est pas un tableau.\n", nb_ligne, colonne, (yyvsp[(1) - (4)].str));
            (yyval.exp).type = strdup("ERROR");
            (yyval.exp).value = strdup("");
        }
        else if(isOutOfRange((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].entier))) {
            printf("\nErreur semantique ,ligne %d, colonne %d: Index out of range.\n", nb_ligne, colonne);
            (yyval.exp).type = strdup("ERROR");
            (yyval.exp).value = strdup("");
        }
        else {
            char temp[50];
            sprintf(temp, "%s[%d]", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].entier));
            (yyval.exp).value = strdup(temp);
            sprintf(temp, "%d", arrayElementType((yyvsp[(1) - (4)].str)));
            (yyval.exp).type = strdup(temp);
        }
    }
;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 347 "p.y"
    {
            if(doubleDeclaration((yyvsp[(1) - (4)].str)) == 0) {
                printf("\nErreur semantique, ligne %d, colonne %d: Variable %s non declaree\n", 
                       nb_ligne, colonne, (yyvsp[(1) - (4)].str));
                (yyval.exp).type = strdup("ERROR");
            } else {
                if(!isArray((yyvsp[(1) - (4)].str))) {
                    printf("\nErreur semantique, ligne %d, colonne %d: %s n'est pas un tableau\n", 
                           nb_ligne, colonne, (yyvsp[(1) - (4)].str));
                    (yyval.exp).type = strdup("ERROR");
                } else if(isOutOfRange((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str))) {
                    printf("\nErreur semantique, ligne %d, colonne %d: Index hors limites\n", 
                           nb_ligne, colonne);
                    (yyval.exp).type = strdup("ERROR");
                } else {
                    char temp[50];
                    sprintf(temp, "%s[%d]", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str));
                    (yyval.exp).value = strdup(temp);
                    sprintf(temp, "%d", arrayElementType((yyvsp[(1) - (4)].str)));
                    (yyval.exp).type = strdup(temp);
                }
            }
         ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 370 "p.y"
    {
            (yyval.exp).value = (yyvsp[(2) - (3)].exp).value;
            (yyval.exp).type = (yyvsp[(2) - (3)].exp).type;
         ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 374 "p.y"
    {
            char temp[50];
            sprintf(temp, "%d", (yyvsp[(1) - (1)].entier));
            (yyval.exp).value = strdup(temp);
            (yyval.exp).type = strdup("INTEGER");
          strcpy(saveCst, temp);
         ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 381 "p.y"
    {
            char temp[50];
            sprintf(temp, "%f", (yyvsp[(1) - (1)].reel));
            (yyval.exp).value = strdup(temp);
            (yyval.exp).type = strdup("FLOAT");
          // Copie de la chaîne convertie dans saveCst
          strcpy(saveCst, temp);
         ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 389 "p.y"
    {
            if(doubleDeclaration((yyvsp[(1) - (1)].str)) == 0) {
                printf("\nErreur semantique, ligne %d, colonne %d: Variable %s non declaree\n", 
                       nb_ligne, colonne, (yyvsp[(1) - (1)].str));
                (yyval.exp).type = strdup("ERROR");
            } else {
                (yyval.exp).value = strdup((yyvsp[(1) - (1)].str));
                char temp[50];
                sprintf(temp, "%d", getType((yyvsp[(1) - (1)].str)));
                (yyval.exp).type = strdup(temp);
            }
            
         ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 406 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr(">", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
        (yyval.str) = strdup(temp);
        
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 413 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("<", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
        (yyval.str) = strdup(temp);
        
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 420 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr(">=", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
        (yyval.str) = strdup(temp);
       
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 427 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("<=", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
        (yyval.str) = strdup(temp);
        
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 434 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("==", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
        (yyval.str) = strdup(temp);
        
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 441 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("!=", (yyvsp[(1) - (3)].exp).value, (yyvsp[(3) - (3)].exp).value, temp);
        (yyval.str) = strdup(temp);
       
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 459 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("&&", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp);
        (yyval.str) = strdup(temp);
        
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 466 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("||", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str), temp);
        (yyval.str) = strdup(temp);
        
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 473 "p.y"
    {
        char temp[20];
        sprintf(temp, "T%d", qc);
        quadr("!", (yyvsp[(2) - (2)].str), "", temp);
        (yyval.str) = strdup(temp);
       
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 480 "p.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (3)].str));  // Pas besoin de nouveau quadruplet, juste transmettre le résultat
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 483 "p.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));  // Le résultat de la comparaison est déjà dans un temporaire
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 488 "p.y"
    {
        if(strcmp((yyvsp[(1) - (4)].exp).type, "ERROR") != 0 && strcmp((yyvsp[(3) - (4)].exp).type, "ERROR") != 0) {
            if(!isCompatible((yyvsp[(1) - (4)].exp).type, (yyvsp[(3) - (4)].exp).type)) {
                printf("\nErreur semantique, ligne %d, colonne %d: Types incompatibles dans l'affectation \n", 
                       nb_ligne, colonne);
            }
        }
        isAffect = 0;
        quadr("=", (yyvsp[(3) - (4)].exp).value, "", (yyvsp[(1) - (4)].exp).value); // Utiliser la valeur de l'expression
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 507 "p.y"
    {
            if(doubleDeclaration((yyvsp[(1) - (1)].str)) == 0) {
                printf("\nErreur semantique, ligne %d, colonne %d: Variable %s non declaree\n", 
                       nb_ligne, colonne, (yyvsp[(1) - (1)].str));
                (yyval.exp).type = strdup("ERROR");
            } else if(isConst((yyvsp[(1) - (1)].str))) {
                printf("\nErreur semantique, ligne %d, colonne %d: Tentative de modification de la constante %s\n", 
                       nb_ligne, colonne, (yyvsp[(1) - (1)].str));
                (yyval.exp).type = strdup("ERROR");
            } else {
                (yyval.exp).value = strdup((yyvsp[(1) - (1)].str));
                char temp[50];
                sprintf(temp, "%d", getType((yyvsp[(1) - (1)].str)));
                (yyval.exp).type = strdup(temp);
                sprintf(sauvTypeAff, "%s", getType((yyvsp[(1) - (1)].str)));
                isAffect = 1;
            }
         ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 525 "p.y"
    {
            if(doubleDeclaration((yyvsp[(1) - (4)].str)) == 0) {
                printf("\nErreur semantique, ligne %d, colonne %d: Variable %s non declaree\n", 
                       nb_ligne, colonne, (yyvsp[(1) - (4)].str));
                (yyval.exp).type = strdup("ERROR");
            } else {
                if(!isArray((yyvsp[(1) - (4)].str))) {
                    printf("\nErreur semantique, ligne %d, colonne %d: %s n'est pas un tableau\n", 
                           nb_ligne, colonne, (yyvsp[(1) - (4)].str));
                    (yyval.exp).type = strdup("ERROR");
                } else if(isOutOfRange((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].entier))) {
                    printf("\nErreur semantique, ligne %d, colonne %d: Index hors limites\n", 
                           nb_ligne, colonne);
                    (yyval.exp).type = strdup("ERROR");
                } else {
                    char temp[50];
                    sprintf(temp, "%s[%d]", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].entier));
                    (yyval.exp).value = strdup(temp);
                    sprintf(temp, "%d", arrayElementType((yyvsp[(1) - (4)].str)));
                    (yyval.exp).type = strdup(temp);
                    sprintf(sauvTypeAff, "%s", arrayElementType((yyvsp[(1) - (4)].str)));
                    isAffect = 1;
                }
            }
         ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 552 "p.y"
    {
            char temp[50];
            sprintf(temp, "%d", qc);
            int x = pop();
            ajour_quad(x, 3, temp);
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 558 "p.y"
    {
            char temp[50];
            sprintf(temp, "%d", qc);
            int x = pop();
            ajour_quad(x, 3, temp);
;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 566 "p.y"
    {
            
            quadr("BZ", "", (yyvsp[(3) - (3)].str), ""); // Saut si la condition est fausse
            push(qc-1);
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 573 "p.y"
    {
            char temp[50];
            
            quadr("BR", "", "", "");
            int x = pop();
            push(qc-1);
            sprintf(temp, "%d", qc);
            
            
            ajour_quad(x, 3, temp);
;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 588 "p.y"
    {
        if(doubleDeclaration((yyvsp[(3) - (10)].str)) == 0) {
            printf("\nErreur semantique %d:%d - %s: Variable non declaree.\n", nb_ligne, colonne, (yyvsp[(3) - (10)].str));
        } else {
            // Sauvegarder la variable de boucle courante
            strcpy(for_vars[for_depth], (yyvsp[(3) - (10)].str));
            for_depth++;
            
            // 1. Initialisation de la variable
            char start[20];
            sprintf(start, "%d", (yyvsp[(5) - (10)].entier));
            quadr("=", start, "", for_vars[for_depth-1]);
            
            // 2. Position de début pour le test
            int debut_test = qc;
            
            // 3. Test par rapport à la limite
            char temp_cond[20];
            sprintf(temp_cond, "T%d", qc);
            quadr("<=", for_vars[for_depth-1], (yyvsp[(9) - (10)].exp).value, temp_cond);
            
            // 4. Saut conditionnel
            quadr("BZ", "", temp_cond, "");
            int pos_bz = qc - 1;
            
            // Sauvegarder les positions importantes
            push(pos_bz);
            push(debut_test);
        }
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 617 "p.y"
    {
            // Récupérer les positions sauvegardées
            int debut_test = pop();
            int pos_bz = pop();
            
            // 5. Incrémentation
            char pas[20];
            sprintf(pas, "%d", (yyvsp[(7) - (14)].entier));
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
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 649 "p.y"
    {
            int saut_condition = pop(); // Récupère l'adresse du saut conditionnel
            int x = pop();  // Récupère l'adresse du début de la boucle
           
            
            char temp[50];
            sprintf(temp, "%d", x);
            quadr("BR", "", "", temp);

            sprintf(temp, "%d", qc);
            ajour_quad(saut_condition, 3, temp);

;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 664 "p.y"
    {
            push(qc);

;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 669 "p.y"
    {
            quadr("BZ", "", (yyvsp[(2) - (2)].str), "");
            push(qc-1);
;}
    break;



/* Line 1455 of yacc.c  */
#line 2288 "p.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 682 "p.y"


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

