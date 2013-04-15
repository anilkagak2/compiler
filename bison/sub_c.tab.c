/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "sub_c.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern char yytext[];
extern int yylineno;
extern int column;

char *Names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };   
char **Namep  = Names;   
char *newname() ;
void freename();
void count();


/* Line 268 of yacc.c  */
#line 87 "sub_c.tab.c"

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
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     STRUCT = 300,
     UNION = 301,
     ENUM = 302,
     ELLIPSIS = 303,
     CASE = 304,
     DEFAULT = 305,
     IF = 306,
     ELSE = 307,
     SWITCH = 308,
     WHILE = 309,
     DO = 310,
     FOR = 311,
     GOTO = 312,
     CONTINUE = 313,
     BREAK = 314,
     RETURN = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 16 "sub_c.y"
char id[100];


/* Line 293 of yacc.c  */
#line 187 "sub_c.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 199 "sub_c.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNRULES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    40,    29,    83,    30,     2,
      31,    32,    41,    33,    42,    34,    43,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    50,
      47,    49,    48,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    85,    46,    39,     2,     2,     2,
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
      25,    26,    27,    28,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   173,   175,   179,   181,
     187,   189,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   221,   223,   226,   230,   232,
     235,   237,   240,   242,   245,   247,   251,   253,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   297,   302,   305,   307,
     309,   311,   314,   318,   321,   323,   326,   328,   330,   334,
     336,   339,   343,   348,   354,   357,   359,   363,   365,   369,
     371,   373,   376,   378,   380,   384,   389,   393,   398,   403,
     407,   409,   412,   415,   419,   421,   424,   426,   430,   432,
     436,   439,   442,   444,   446,   450,   452,   455,   457,   459,
     462,   466,   469,   473,   477,   482,   485,   489,   493,   498,
     500,   504,   509,   511,   515,   517,   519,   521,   523,   525,
     527,   531,   536,   540,   543,   547,   551,   556,   558,   561,
     563,   566,   568,   571,   577,   585,   591,   597,   605,   612,
     620,   624,   627,   630,   633,   637,   639,   642,   644,   646,
     651,   655,   659
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     148,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    31,
     107,    32,    -1,    88,    -1,    89,    37,   107,    38,    -1,
      89,    31,    32,    -1,    89,    31,    90,    32,    -1,    89,
      43,     3,    -1,    89,     7,     3,    -1,    89,     8,    -1,
      89,     9,    -1,   105,    -1,    90,    42,   105,    -1,    89,
      -1,     8,    91,    -1,     9,    91,    -1,    92,    93,    -1,
       6,    91,    -1,     6,    31,   134,    32,    -1,    30,    -1,
      41,    -1,    33,    -1,    34,    -1,    39,    -1,    36,    -1,
      91,    -1,    31,   134,    32,    93,    -1,    93,    -1,    94,
      41,    93,    -1,    94,    35,    93,    -1,    94,    83,    93,
      -1,    94,    -1,    95,    33,    94,    -1,    95,    34,    94,
      -1,    95,    -1,    96,    10,    95,    -1,    96,    11,    95,
      -1,    96,    -1,    97,    47,    96,    -1,    97,    48,    96,
      -1,    97,    12,    96,    -1,    97,    13,    96,    -1,    97,
      -1,    98,    14,    97,    -1,    98,    15,    97,    -1,    98,
      -1,    99,    30,    98,    -1,    99,    -1,   100,    84,    99,
      -1,   100,    -1,   101,    85,   100,    -1,   101,    -1,   102,
      16,   101,    -1,   102,    -1,   103,    17,   102,    -1,   103,
      -1,   103,    86,   107,    44,   104,    -1,   104,    -1,    91,
     106,   105,    -1,    49,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,   105,    -1,   107,    42,   105,
      -1,   104,    -1,   110,    50,    -1,   110,   111,    50,    -1,
     113,    -1,   113,   110,    -1,   114,    -1,   114,   110,    -1,
     125,    -1,   125,   110,    -1,   112,    -1,   111,    42,   112,
      -1,   126,    -1,   126,    49,   137,    -1,    51,    -1,    52,
      -1,    53,    -1,    54,    -1,    55,    -1,    66,    -1,    56,
      -1,    57,    -1,    58,    -1,    59,    -1,    62,    -1,    63,
      -1,    60,    -1,    61,    -1,   115,    -1,   122,    -1,    28,
      -1,   116,     3,    45,   117,    46,    -1,   116,    45,   117,
      46,    -1,   116,     3,    -1,    67,    -1,    68,    -1,   118,
      -1,   117,   118,    -1,   119,   120,    50,    -1,   114,   119,
      -1,   114,    -1,   125,   119,    -1,   125,    -1,   121,    -1,
     120,    42,   121,    -1,   126,    -1,    44,   108,    -1,   126,
      44,   108,    -1,    69,    45,   123,    46,    -1,    69,     3,
      45,   123,    46,    -1,    69,     3,    -1,   124,    -1,   123,
      42,   124,    -1,     3,    -1,     3,    49,   108,    -1,    64,
      -1,    65,    -1,   128,   127,    -1,   127,    -1,     3,    -1,
      31,   126,    32,    -1,   127,    37,   108,    38,    -1,   127,
      37,    38,    -1,   127,    31,   130,    32,    -1,   127,    31,
     133,    32,    -1,   127,    31,    32,    -1,    41,    -1,    41,
     129,    -1,    41,   128,    -1,    41,   129,   128,    -1,   125,
      -1,   129,   125,    -1,   131,    -1,   131,    42,    70,    -1,
     132,    -1,   131,    42,   132,    -1,   110,   126,    -1,   110,
     135,    -1,   110,    -1,     3,    -1,   133,    42,     3,    -1,
     119,    -1,   119,   135,    -1,   128,    -1,   136,    -1,   128,
     136,    -1,    31,   135,    32,    -1,    37,    38,    -1,    37,
     108,    38,    -1,   136,    37,    38,    -1,   136,    37,   108,
      38,    -1,    31,    32,    -1,    31,   130,    32,    -1,   136,
      31,    32,    -1,   136,    31,   130,    32,    -1,   105,    -1,
      45,   138,    46,    -1,    45,   138,    42,    46,    -1,   137,
      -1,   138,    42,   137,    -1,   140,    -1,   141,    -1,   144,
      -1,   145,    -1,   146,    -1,   147,    -1,     3,    44,   139,
      -1,    71,   108,    44,   139,    -1,    72,    44,   139,    -1,
      45,    46,    -1,    45,   143,    46,    -1,    45,   142,    46,
      -1,    45,   142,   143,    46,    -1,   109,    -1,   142,   109,
      -1,   139,    -1,   143,   139,    -1,    50,    -1,   107,    50,
      -1,    73,    31,   107,    32,   139,    -1,    73,    31,   107,
      32,   139,    74,   139,    -1,    75,    31,   107,    32,   139,
      -1,    76,    31,   107,    32,   139,    -1,    77,   139,    76,
      31,   107,    32,    50,    -1,    78,    31,   144,   144,    32,
     139,    -1,    78,    31,   144,   144,   107,    32,   139,    -1,
      79,     3,    50,    -1,    80,    50,    -1,    81,    50,    -1,
      82,    50,    -1,    82,   107,    50,    -1,   149,    -1,   148,
     149,    -1,   150,    -1,   109,    -1,   110,   126,   142,   141,
      -1,   110,   126,   141,    -1,   126,   142,   141,    -1,   126,
     141,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    44,    45,    46,    50,    51,    52,    53,
      54,    55,    56,    57,    61,    62,    66,    67,    68,    69,
      70,    71,    75,    76,    77,    78,    79,    80,    84,    85,
      89,    90,    91,    92,    96,    97,   107,   111,   112,   113,
     117,   118,   119,   120,   121,   125,   126,   127,   131,   132,
     136,   137,   141,   142,   146,   147,   151,   152,   156,   157,
     161,   162,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   180,   181,   185,   189,   190,   194,   195,
     196,   197,   198,   199,   203,   204,   208,   209,   213,   214,
     215,   216,   217,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   236,   237,   238,   242,   243,
     247,   248,   252,   256,   257,   258,   259,   263,   264,   268,
     269,   270,   274,   275,   276,   280,   281,   285,   286,   290,
     291,   295,   296,   300,   301,   302,   303,   304,   305,   306,
     310,   311,   312,   313,   317,   318,   323,   324,   328,   329,
     333,   334,   335,   339,   340,   344,   345,   349,   350,   351,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   367,
     368,   369,   373,   374,   378,   379,   380,   381,   382,   383,
     387,   388,   389,   393,   394,   395,   396,   400,   401,   405,
     406,   410,   411,   415,   416,   417,   421,   422,   423,   424,
     428,   429,   430,   431,   432,   436,   437,   441,   442,   446,
     447,   448,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "'$'", "'&'", "'('", "')'", "'+'", "'-'", "'/'", "'!'",
  "'['", "']'", "'~'", "'#'", "'*'", "','", "'.'", "':'", "'{'", "'}'",
  "'<'", "'>'", "'='", "';'", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'%'", "'^'", "'|'",
  "'?'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    36,
      38,    40,    41,    43,    45,    47,    33,    91,    93,   126,
      35,    42,    44,    46,    58,   123,   125,    60,    62,    61,
      59,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    37,    94,   124,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   115,   115,   115,   116,   116,
     117,   117,   118,   119,   119,   119,   119,   120,   120,   121,
     121,   121,   122,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   127,   127,   127,   127,   127,
     128,   128,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   133,   133,   134,   134,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   137,
     137,   137,   138,   138,   139,   139,   139,   139,   139,   139,
     140,   140,   140,   141,   141,   141,   141,   142,   142,   143,
     143,   144,   144,   145,   145,   145,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   148,   148,   149,   149,   150,
     150,   150,   150
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,   104,     0,   140,    88,    89,    90,    91,    92,
      94,    95,    96,    97,   100,   101,    98,    99,   129,   130,
      93,   108,   109,     0,   208,     0,    78,    80,   102,     0,
     103,    82,     0,   132,     0,     0,   205,   207,     0,   144,
     142,   141,   124,     0,    76,     0,    84,    86,    79,    81,
     107,     0,    83,     0,   187,     0,   212,     0,     0,     0,
     131,     1,   206,   134,   145,   143,     0,   127,     0,   125,
       0,    77,     0,   210,     0,     0,   114,     0,   110,     0,
     116,     2,     3,     4,     0,     0,     0,    22,     0,    24,
      25,    27,    26,    23,   183,   191,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,    16,    28,
       0,    30,    34,    37,    40,    45,    48,    50,    52,    54,
      56,    58,    60,    73,     0,   189,   174,   175,     0,     0,
     176,   177,   178,   179,    86,   188,   211,   153,   139,   152,
       0,   146,   148,     0,     2,   136,    28,    75,     0,     0,
       0,     0,   122,    85,     0,   169,    87,   209,     0,   113,
     106,   111,     0,     0,   117,   119,   115,     0,     0,    20,
       0,    17,    18,     0,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   202,   203,     0,     0,    12,
      13,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    62,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   185,     0,
     184,   190,     0,     0,   150,   157,   151,   158,   137,     0,
     138,     0,   135,   123,   128,   126,   172,     0,   105,   120,
       0,   112,     0,   180,     0,     5,     0,   157,   156,     0,
       0,   182,     0,     0,     0,     0,     0,   200,   204,    11,
       8,     0,    14,     0,    10,    61,    32,    31,    33,    35,
      36,    38,    39,    43,    44,    41,    42,    46,    47,    49,
      51,    53,    55,    57,     0,    74,   186,   165,     0,     0,
     161,     0,   159,     0,     0,   147,   149,   154,     0,   170,
     118,   121,    21,    29,   181,     0,     0,     0,     0,     0,
       9,     0,     7,     0,   166,   160,   162,   167,     0,   163,
       0,   171,   173,   193,   195,   196,     0,     0,     0,    15,
      59,   168,   164,     0,     0,   198,     0,   194,   197,   199
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   107,   108,   271,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   205,
     124,   148,    54,    55,    45,    46,    26,    27,    28,    29,
      77,    78,    79,   163,   164,    30,    68,    69,    31,    32,
      33,    34,    41,   298,   141,   142,   143,   175,   299,   237,
     156,   247,   125,   126,   127,    57,   129,   130,   131,   132,
     133,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -188
static const yytype_int16 yypact[] =
{
     745,  -188,  -188,    20,    45,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,    11,  -188,    16,  1087,  1087,  -188,    19,
    -188,  1087,  1026,    65,    22,   594,  -188,  -188,   -15,  -188,
    -188,    45,    -9,    47,  -188,   -18,  -188,   984,  -188,  -188,
      53,   615,  -188,   281,  -188,    16,  -188,  1026,   787,   600,
      65,  -188,  -188,  -188,  -188,  -188,    47,    64,   156,  -188,
      20,  -188,   930,  -188,  1026,   615,   615,  1129,  -188,    41,
     615,    85,  -188,  -188,  1287,  1299,  1299,  -188,   661,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  1338,   102,   118,   153,
     164,   539,   184,   178,   181,   188,   552,  -188,   192,   354,
    1338,  -188,   -23,   191,   216,    95,   219,   198,   157,   160,
     231,   -11,  -188,  -188,    26,  -188,  -188,  -188,   361,   441,
    -188,  -188,  -188,  -188,   201,  -188,  -188,  -188,  -188,    62,
     223,   215,  -188,    63,  -188,  -188,  -188,  -188,   221,   162,
    1338,    47,  -188,  -188,   930,  -188,  -188,  -188,  1153,  -188,
    -188,  -188,  1338,    31,  -188,   222,  -188,   539,   661,  -188,
    1338,  -188,  -188,    88,    87,   236,   225,   539,  1338,  1338,
    1338,   187,   827,   220,  -188,  -188,  -188,   138,   270,  -188,
    -188,   983,  1338,   271,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  1338,  -188,  1338,  1338,  1338,
    1338,  1338,  1338,  1338,  1338,  1338,  1338,  1338,  1338,  1338,
    1338,  1338,  1338,  1338,  1338,  1338,  1338,  -188,  -188,   459,
    -188,  -188,   703,  1197,  -188,    46,  -188,    80,  -188,   862,
    -188,   272,  -188,  -188,  -188,  -188,  -188,   170,  -188,  -188,
      41,  -188,  1338,  -188,   244,  -188,   942,   113,  -188,  1338,
     539,  -188,    93,    94,   141,   246,   827,  -188,  -188,  -188,
    -188,   144,  -188,   175,  -188,  -188,  -188,  -188,  -188,   -23,
     -23,   191,   191,   216,   216,   216,   216,    95,    95,   219,
     198,   157,   160,   231,    27,  -188,  -188,  -188,   247,   248,
    -188,   240,    80,  1068,  1236,  -188,  -188,  -188,   866,  -188,
    -188,  -188,  -188,  -188,  -188,   539,   539,   539,  1338,  1248,
    -188,  1338,  -188,  1338,  -188,  -188,  -188,  -188,   249,  -188,
     245,  -188,  -188,   224,  -188,  -188,   147,   539,   150,  -188,
    -188,  -188,  -188,   539,   243,  -188,   539,  -188,  -188,  -188
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,  -188,  -188,   -56,  -188,   -68,    33,    24,     4,
      34,    74,    75,    73,    76,    77,  -188,   -58,   -57,  -188,
     -47,   -62,    10,     0,  -188,   227,  -188,   134,  -188,  -188,
     229,   -69,   -67,  -188,    50,  -188,   239,   155,    39,     8,
     -29,    -2,  -188,   -54,  -188,    68,  -188,   142,  -119,  -187,
    -138,  -188,   -55,  -188,     5,   140,   180,  -175,  -188,  -188,
    -188,  -188,   278,  -188
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      25,   147,    40,   146,   140,    60,   224,   266,   161,   159,
      24,    38,   207,   166,    42,   155,   246,    63,   208,     1,
     236,   174,    50,     1,    70,     1,    48,    49,   169,   171,
     172,    52,    71,    47,   176,    25,    66,    56,   147,    65,
     146,   173,   206,    39,     1,    24,   181,     3,   302,     1,
      67,     3,    73,     3,   146,   258,    43,     4,   139,   187,
     209,     4,   136,   134,    51,     1,    44,   135,   226,   226,
     302,   323,     3,   250,   231,   225,   227,   232,   134,   157,
      64,   251,     4,   233,   135,   162,     4,   165,   244,   161,
      80,   319,   147,   232,   146,   240,    58,   155,    75,   233,
     249,   174,    59,     4,   147,   241,   146,   214,   215,    18,
      19,   303,   253,   150,    80,    80,    80,   304,   256,    80,
     255,   173,   261,   173,   233,   315,   316,    80,     4,   167,
     226,   262,   263,   264,   272,   226,   226,   235,   135,   276,
     277,   278,   216,   217,   256,   273,   177,   234,   275,   178,
     233,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   295,
     332,   301,   257,   317,   231,   147,   320,   146,   294,   344,
     226,   183,   346,   226,   179,    76,   321,    74,   268,   226,
     311,   313,   226,   128,   147,   180,   146,    80,   151,   188,
     189,   190,   152,   146,   151,   314,    60,    80,   243,    76,
      76,    76,   308,   322,    76,   182,   309,   226,   283,   284,
     285,   286,    76,   191,   210,   211,   212,   213,   220,   192,
     235,   184,   139,   218,   219,   193,   281,   282,   185,   139,
      38,   221,   330,   279,   280,   222,   147,   223,   146,   328,
      72,   155,   287,   288,   257,   238,   139,   239,   165,   242,
     333,   334,   335,   265,   339,   340,   252,   146,   259,   260,
     267,   336,   338,   269,   274,   307,   312,   318,   326,   324,
     325,   341,   345,   342,    81,    82,    83,    84,   347,    85,
      86,   349,    76,   348,   289,   291,   290,   153,   343,   292,
     310,   293,    76,   139,   158,   149,   245,   306,   229,     2,
     254,    87,    88,    62,    89,    90,     0,    91,     0,     0,
      92,     0,    93,     0,     0,     0,    53,    94,     0,     0,
       0,    95,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    96,    97,    98,     0,    99,   100,   101,   102,
     103,   104,   105,   106,    81,    82,    83,    84,     0,    85,
      86,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,     0,     0,     2,
       0,    87,    88,     0,    89,    90,     0,    91,     0,     0,
      92,     0,    93,   204,     0,     0,    53,   228,     0,     0,
       0,    95,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    96,    97,    98,     0,    99,   100,   101,   102,
     103,   104,   105,   106,    81,    82,    83,    84,     0,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,    82,    83,    84,     0,    85,    86,     0,
       0,    87,    88,     0,    89,    90,     0,    91,     0,     0,
      92,     0,    93,     0,     0,     0,    53,   230,     0,    87,
      88,    95,    89,    90,     0,    91,     0,     0,    92,     0,
      93,     0,     0,     0,    53,   296,     0,     0,     0,    95,
       0,     0,    96,    97,    98,     0,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,    99,   100,   101,   102,   103,   104,
     105,   106,    81,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,   144,    82,    83,    84,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,    87,
      88,     0,    89,    90,     0,    91,     0,     0,    92,     0,
      93,     0,    87,    88,    53,    89,    90,     0,    91,    95,
       0,    92,     0,    93,    61,     0,     0,     1,     0,     0,
       0,     0,   186,   144,    82,    83,    84,     0,    85,    86,
      96,    97,    98,     0,    99,   100,   101,   102,   103,   104,
     105,   106,     2,     0,     0,     3,     0,     0,     0,     0,
      87,    88,     0,    89,    90,     4,    91,     0,   145,    92,
       0,    93,     0,     2,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   144,    82,    83,    84,     0,    85,
      86,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,     2,
       0,    87,    88,     0,    89,    90,     0,    91,     0,     0,
      92,     0,    93,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     2,     0,     0,   232,   297,     0,     0,     0,     0,
     233,     0,     0,     0,     4,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     2,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     2,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,    82,    83,    84,     0,    85,    86,     0,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    87,    88,     0,
      89,    90,     0,    91,     0,     0,    92,     0,    93,   144,
      82,    83,    84,     0,    85,    86,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,    87,    88,     0,    89,
      90,     0,    91,     0,     0,    92,     0,    93,     0,     0,
       0,   154,   331,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   305,   144,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,    88,     0,    89,    90,     0,    91,     0,     0,    92,
       2,    93,     0,   256,   297,   154,     0,     0,     0,   233,
       0,     0,     0,     4,     0,     0,   144,    82,    83,    84,
       0,    85,    86,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     2,    87,    88,   270,    89,    90,     0,    91,
       0,     0,    92,     0,    93,     0,     0,     0,     0,    53,
       0,     0,     0,    72,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     2,     0,     0,     0,
     327,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,     0,     0,     0,     0,
       0,     2,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   248,
     144,    82,    83,    84,     0,    85,    86,     0,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,     0,     0,     0,    87,    88,     0,
      89,    90,     0,    91,     0,   300,    92,     0,    93,   144,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,   144,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,     0,    89,
      90,     0,    91,     0,   329,    92,     0,    93,    87,    88,
     337,    89,    90,     0,    91,     0,     0,    92,     0,    93,
     144,    82,    83,    84,     0,    85,    86,     0,     0,     0,
       0,     0,   144,    82,    83,    84,     0,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    87,   168,     0,
      89,    90,     0,    91,     0,     0,    92,     0,    93,    87,
     170,     0,    89,    90,     0,    91,     0,     0,    92,     0,
      93,   144,    82,    83,    84,     0,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
       0,    89,    90,     0,    91,     0,     0,    92,     0,    93
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-188))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    59,     4,    59,    58,    34,    17,   182,    77,    76,
       0,     3,    35,    80,     3,    72,   154,    32,    41,     3,
     139,    88,     3,     3,    42,     3,    26,    27,    84,    85,
      86,    31,    50,    25,    96,    35,    45,    32,    96,    41,
      96,    88,   110,     4,     3,    35,   101,    31,   235,     3,
       3,    31,    47,    31,   110,   174,    45,    41,    58,   106,
      83,    41,    57,    55,    45,     3,    50,    57,    42,    42,
     257,    44,    31,    42,   129,    86,    50,    31,    70,    74,
      41,    50,    41,    37,    74,    44,    41,    79,   150,   158,
      51,   266,   150,    31,   150,    32,    31,   154,    45,    37,
     162,   168,    37,    41,   162,    42,   162,    12,    13,    64,
      65,    31,   167,    49,    75,    76,    77,    37,    31,    80,
      32,   168,   177,   170,    37,    32,    32,    88,    41,    44,
      42,   178,   179,   180,   191,    42,    42,   139,   128,   207,
     208,   209,    47,    48,    31,   192,    44,   139,   205,    31,
      37,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   226,
     308,   233,   174,    32,   229,   233,    32,   233,   225,    32,
      42,     3,    32,    42,    31,    51,    42,    47,    50,    42,
     252,   259,    42,    53,   252,    31,   252,   158,    42,     7,
       8,     9,    46,   259,    42,   260,   235,   168,    46,    75,
      76,    77,    42,    38,    80,    31,    46,    42,   214,   215,
     216,   217,    88,    31,    33,    34,    10,    11,    30,    37,
     232,    50,   232,    14,    15,    43,   212,   213,    50,   239,
     232,    84,   304,   210,   211,    85,   304,    16,   304,   303,
      49,   308,   218,   219,   256,    32,   256,    42,   250,    38,
     315,   316,   317,    76,   321,   323,    44,   323,    32,    44,
      50,   318,   319,     3,     3,     3,    32,    31,    38,    32,
      32,    32,   337,    38,     3,     4,     5,     6,   343,     8,
       9,   346,   158,    50,   220,   222,   221,    70,    74,   223,
     250,   224,   168,   303,    75,    66,   151,   239,   128,    28,
     168,    30,    31,    35,    33,    34,    -1,    36,    -1,    -1,
      39,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,     3,     4,     5,     6,    -1,     8,
       9,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    -1,    -1,
      39,    -1,    41,    49,    -1,    -1,    45,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    -1,    -1,
      39,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    30,
      31,    50,    33,    34,    -1,    36,    -1,    -1,    39,    -1,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      -1,    -1,    71,    72,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    -1,    36,    -1,    -1,    39,    -1,
      41,    -1,    30,    31,    45,    33,    34,    -1,    36,    50,
      -1,    39,    -1,    41,     0,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    50,     3,     4,     5,     6,    -1,     8,     9,
      71,    72,    73,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    41,    36,    -1,    38,    39,
      -1,    41,    -1,    28,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     3,     4,     5,     6,    -1,     8,
       9,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    28,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    -1,    -1,
      39,    -1,    41,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    28,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    28,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    30,    31,    -1,
      33,    34,    -1,    36,    -1,    -1,    39,    -1,    41,     3,
       4,     5,     6,    -1,     8,     9,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    36,    -1,    -1,    39,    -1,    41,    -1,    -1,
      -1,    45,    46,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    -1,    39,
      28,    41,    -1,    31,    32,    45,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    41,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    28,    30,    31,    32,    33,    34,    -1,    36,
      -1,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    28,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    46,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    -1,    36,    -1,    38,    39,    -1,    41,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    -1,    41,    30,    31,
      32,    33,    34,    -1,    36,    -1,    -1,    39,    -1,    41,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    -1,    36,    -1,    -1,    39,    -1,    41,    30,
      31,    -1,    33,    34,    -1,    36,    -1,    -1,    39,    -1,
      41,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    -1,    36,    -1,    -1,    39,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    31,    41,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,   109,   110,   113,   114,   115,   116,
     122,   125,   126,   127,   128,   148,   149,   150,   126,   125,
     128,   129,     3,    45,    50,   111,   112,   126,   110,   110,
       3,    45,   110,    45,   109,   110,   141,   142,    31,    37,
     127,     0,   149,    32,   125,   128,    45,     3,   123,   124,
      42,    50,    49,   141,   142,    45,   114,   117,   118,   119,
     125,     3,     4,     5,     6,     8,     9,    30,    31,    33,
      34,    36,    39,    41,    46,    50,    71,    72,    73,    75,
      76,    77,    78,    79,    80,    81,    82,    88,    89,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   107,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   126,   109,   141,     3,    32,   110,
     130,   131,   132,   133,     3,    38,    91,   104,   108,   123,
      49,    42,    46,   112,    45,   105,   137,   141,   117,   119,
      46,   118,    44,   120,   121,   126,   119,    44,    31,    91,
      31,    91,    91,   107,   119,   134,   108,    44,    31,    31,
      31,   139,    31,     3,    50,    50,    50,   107,     7,     8,
       9,    31,    37,    43,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    49,   106,    93,    35,    41,    83,
      33,    34,    10,    11,    12,    13,    47,    48,    14,    15,
      30,    84,    85,    16,    17,    86,    42,    50,    46,   143,
      46,   139,    31,    37,   126,   128,   135,   136,    32,    42,
      32,    42,    38,    46,   108,   124,   137,   138,    46,   108,
      42,    50,    44,   139,   134,    32,    31,   128,   135,    32,
      44,   139,   107,   107,   107,    76,   144,    50,    50,     3,
      32,    90,   105,   107,     3,   105,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    96,    96,    97,    97,    98,
      99,   100,   101,   102,   107,   105,    46,    32,   130,   135,
      38,   108,   136,    31,    37,    70,   132,     3,    42,    46,
     121,   108,    32,    93,   139,    32,    32,    32,    31,   144,
      32,    42,    38,    44,    32,    32,    38,    32,   130,    38,
     108,    46,   137,   139,   139,   139,   107,    32,   107,   105,
     104,    32,    38,    74,    32,   139,    32,   139,    50,   139
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
        case 5:

/* Line 1806 of yacc.c  */
#line 46 "sub_c.y"
    {strcpy ((yyval.id), (yyvsp[(2) - (3)].id));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 56 "sub_c.y"
    {/*strcpy ($$, $1); strcat ($$, "")*/}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 97 "sub_c.y"
    {
	  const char *t0 = newname ();
	  const char *t1 = newname ();
	  printf ("%s = %s \n", t0, (yyvsp[(1) - (3)].id));
	  printf ("%s = %s \n", t1, (yyvsp[(3) - (3)].id));
	  printf ("%s = %s + %s \n",t0, t0 , t1);
	  strcpy ((yyval.id), t0);
	  freename (t0);
	  freename (t1);
	}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 162 "sub_c.y"
    { printf("%s %s %s \n",(yyvsp[(1) - (3)].id),(yyvsp[(2) - (3)].id),(yyvsp[(3) - (3)].id)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 166 "sub_c.y"
    { strcpy ((yyval.id), "=");}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 167 "sub_c.y"
    { strcpy ((yyval.id), "*=");}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 168 "sub_c.y"
    { strcpy ((yyval.id), "/=");}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 169 "sub_c.y"
    { strcpy ((yyval.id), "%=");}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 170 "sub_c.y"
    { strcpy ((yyval.id), "+=");}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 171 "sub_c.y"
    { strcpy ((yyval.id), "-=");}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 172 "sub_c.y"
    { strcpy ((yyval.id), "<<=");}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 173 "sub_c.y"
    { strcpy ((yyval.id), ">>=");}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 174 "sub_c.y"
    { strcpy ((yyval.id), "&=");}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 175 "sub_c.y"
    { strcpy ((yyval.id), "^=");}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 176 "sub_c.y"
    { strcpy ((yyval.id), "|=");}
    break;



/* Line 1806 of yacc.c  */
#line 2106 "sub_c.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 452 "sub_c.y"

char  *newname()   
{   
	if( Namep >= &Names[ sizeof(Names)/sizeof(*Names) ] )   
	{   
		fprintf( stderr, "%d: Expression too complex\n", yylineno );   
		exit( 1 );   
	}   

	return( *Namep++ );   
}   

void freename(s)   
	char    *s;   
{   
	if( Namep > Names )   
		*--Namep = s;   
	else   
		fprintf(stderr, "%d: (Internal error) Name stack underflow\n",   
				yylineno );   
}   

yyerror(s)
	char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main () {
	return yyparse ();
}

