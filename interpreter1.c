
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "calc5.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
//#include <cstring>
#include "JaggScript.h"

#define OP_POSTINC 111111
#define OP_PREINC 111112
#define OP_POSTDEC 111113
#define OP_PREDEC 111114


/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(char* i);
nodeType *fid(char* name);
nodeType *con(object o);
nodeType *conInt(int value);
nodeType *conStr(char* str);
void freeNode(nodeType *p);
int yylex(void);

int line = 1;

void yyerror(char *s);
//int sym[26];					/* symbol table */


char *varNames[16];
object varValues[16];
int varCount;

int handTyped = 0;

int main(int argsc, char** args)
{
	handTyped = argsc!=1;
	if (handTyped) printf("##> ");
	yyparse();
	return 0;
}


/* Line 371 of yacc.c  */
#line 113 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     IDENTIFIER = 259,
     STRING = 260,
     FUNCTION = 261,
     WHILE = 262,
     IF = 263,
     PRINT = 264,
     FOR = 265,
     DOTLENGTH = 266,
     DOTDOTDOT = 267,
     ELSE = 268,
     OP_AND = 269,
     OP_OR = 270,
     OP_MUL = 271,
     OP_DIV = 272,
     OP_MINUS = 273,
     OP_PLUS = 274,
     OP_POW = 275,
     OP_LT = 276,
     OP_GT = 277,
     OP_LTE = 278,
     OP_GTE = 279,
     OP_NEQ = 280,
     OP_EQ = 281,
     OP_LXOR = 282,
     OP_LOR = 283,
     OP_LAND = 284,
     OP_BNOT = 285,
     OP_BXOR = 286,
     OP_BOR = 287,
     OP_BAND = 288,
     OP_DECREMENT = 289,
     OP_INCREMENT = 290
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define IDENTIFIER 259
#define STRING 260
#define FUNCTION 261
#define WHILE 262
#define IF 263
#define PRINT 264
#define FOR 265
#define DOTLENGTH 266
#define DOTDOTDOT 267
#define ELSE 268
#define OP_AND 269
#define OP_OR 270
#define OP_MUL 271
#define OP_DIV 272
#define OP_MINUS 273
#define OP_PLUS 274
#define OP_POW 275
#define OP_LT 276
#define OP_GT 277
#define OP_LTE 278
#define OP_GTE 279
#define OP_NEQ 280
#define OP_EQ 281
#define OP_LXOR 282
#define OP_LOR 283
#define OP_LAND 284
#define OP_BNOT 285
#define OP_BXOR 286
#define OP_BOR 287
#define OP_BAND 288
#define OP_DECREMENT 289
#define OP_INCREMENT 290



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 47 "calc5.y"

	int iValue;					/* integer value */
	char* sValue;				/* string value */
	nodeType *nPtr;				/* node pointer */


/* Line 387 of yacc.c  */
#line 233 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 261 "y.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     9,    12,    13,    15,    18,    22,
      28,    34,    42,    48,    50,    60,    64,    68,    71,    74,
      77,    80,    82,    85,    89,    91,    93,    97,   101,   105,
     107,   111,   115,   119,   123,   127,   131,   133,   137,   141,
     143,   147,   151,   153,   157,   159,   162,   166,   170,   174,
     176,   180,   182,   184,   186,   191,   198
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    46,    51,    36,    -1,    46,
      47,    -1,    -1,    36,    -1,    51,    36,    -1,     9,    51,
      36,    -1,     6,     4,    37,    38,    48,    -1,     7,    37,
      51,    38,    47,    -1,     8,    37,    51,    38,    48,    13,
      48,    -1,     8,    37,    51,    38,    48,    -1,    48,    -1,
      10,    37,    49,    36,    51,    36,    49,    38,    47,    -1,
      39,    50,    40,    -1,     4,    41,    51,    -1,     4,    35,
      -1,    35,     4,    -1,     4,    34,    -1,    34,     4,    -1,
      47,    -1,    50,    47,    -1,     4,    37,    38,    -1,    49,
      -1,    52,    -1,    52,    27,    53,    -1,    52,    28,    53,
      -1,    52,    29,    53,    -1,    53,    -1,    54,    26,    54,
      -1,    54,    25,    54,    -1,    54,    22,    54,    -1,    54,
      21,    54,    -1,    54,    24,    54,    -1,    54,    23,    54,
      -1,    54,    -1,    54,    19,    55,    -1,    54,    18,    55,
      -1,    55,    -1,    55,    16,    56,    -1,    55,    17,    56,
      -1,    56,    -1,    57,    20,    56,    -1,    57,    -1,    30,
      58,    -1,    57,    31,    58,    -1,    57,    32,    58,    -1,
      57,    33,    58,    -1,    58,    -1,    37,    51,    38,    -1,
       3,    -1,     5,    -1,     4,    -1,    58,    42,    51,    43,
      -1,    58,    42,    51,    12,    51,    43,    -1,    58,    11,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    73,    73,    77,    87,    92,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   108,   112,   113,   114,   115,
     116,   120,   121,   125,   126,   127,   131,   132,   133,   134,
     137,   138,   139,   140,   141,   142,   143,   146,   147,   148,
     151,   152,   153,   156,   157,   160,   161,   162,   163,   164,
     168,   169,   170,   171,   172,   173,   174
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "IDENTIFIER", "STRING",
  "FUNCTION", "WHILE", "IF", "PRINT", "FOR", "DOTLENGTH", "DOTDOTDOT",
  "ELSE", "OP_AND", "OP_OR", "OP_MUL", "OP_DIV", "OP_MINUS", "OP_PLUS",
  "OP_POW", "OP_LT", "OP_GT", "OP_LTE", "OP_GTE", "OP_NEQ", "OP_EQ",
  "OP_LXOR", "OP_LOR", "OP_LAND", "OP_BNOT", "OP_BXOR", "OP_BOR",
  "OP_BAND", "OP_DECREMENT", "OP_INCREMENT", "';'", "'('", "')'", "'{'",
  "'}'", "'='", "'['", "']'", "$accept", "program", "function", "stmt",
  "block", "stmt_assign", "stmt_list", "expr", "expr_logic", "expr_compar",
  "expr_addsub", "expr_muldiv", "expr_pow", "expr_bitwise", "expr_unit", YY_NULL
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
     285,   286,   287,   288,   289,   290,    59,    40,    41,   123,
     125,    61,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    51,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      55,    55,    55,    56,    56,    57,    57,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     0,     1,     2,     3,     5,
       5,     7,     5,     1,     9,     3,     3,     2,     2,     2,
       2,     1,     2,     3,     1,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     1,     2,     3,     3,     3,     1,
       3,     1,     1,     1,     4,     6,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,     1,    51,    53,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     4,    13,
      24,     0,    25,    29,    36,    39,    42,    44,    49,    19,
      17,     0,     0,     0,     0,     0,     0,     0,    53,    45,
      20,    18,     0,    21,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,    23,    16,     0,     0,
       0,     8,     0,     0,    50,    15,    22,     7,    26,    27,
      28,    38,    37,    33,    32,    35,    34,    31,    30,    40,
      41,    43,    46,    47,    48,     0,     0,     0,     0,     0,
       0,    54,     9,    10,    12,     0,     0,     0,     0,    55,
      11,     0,     0,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    18,    19,    20,    44,    45,    22,    23,
      24,    25,    26,    27,    28
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int8 yypact[] =
{
     -36,    29,    12,   -36,   -36,    74,   -36,    46,    27,    32,
      52,    35,     6,    76,    79,   -36,    52,    12,   -36,   -36,
     -36,    42,    66,   -36,    81,   -12,   -36,    -8,    20,   -36,
     -36,    53,    52,    47,    52,    52,    54,    40,   -36,    20,
     -36,   -36,    63,   -36,    31,    88,   -36,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,     6,     6,     6,   -36,    52,   -36,   -36,    90,    91,
      92,   -36,   -28,    95,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -12,   -12,     8,     8,     8,     8,     8,     8,   -36,
     -36,   -36,    20,    20,    20,    33,    71,    12,    71,    52,
      52,   -36,   -36,   -36,   119,    97,    93,    71,    40,   -36,
     -36,    96,    12,   -36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,   -16,   -19,   -35,   -36,    -2,   -36,    65,
      64,    72,    67,   -36,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      21,    43,    73,    39,    58,    59,    29,    30,    36,     4,
      38,     6,    60,    32,    42,     4,     5,     6,     7,     8,
       9,    10,    11,    61,    62,    63,    50,    51,    76,     3,
      67,    64,    69,    70,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    16,    72,   100,    13,    14,    15,    16,
      33,    17,    92,    93,    94,     4,     5,     6,     4,    38,
       6,    12,    65,    95,    34,    13,    14,    15,    16,    35,
      17,    75,    37,   111,    13,    14,   101,   102,    46,   104,
      40,   103,    12,    41,    68,    12,    13,    14,   110,    16,
      71,    66,    16,    47,    48,    49,   113,   105,   106,    50,
      51,    74,    52,    53,    54,    55,    56,    57,    29,    30,
      17,    31,    78,    79,    80,    32,    83,    84,    85,    86,
      87,    88,    81,    82,    77,    89,    90,    91,    96,    97,
      98,    99,   107,   108,   112,     0,   109
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       2,    17,    37,    12,    16,    17,    34,    35,    10,     3,
       4,     5,    20,    41,    16,     3,     4,     5,     6,     7,
       8,     9,    10,    31,    32,    33,    18,    19,    44,     0,
      32,    11,    34,    35,     3,     4,     5,     6,     7,     8,
       9,    10,    30,    37,     4,    12,    34,    35,    36,    37,
       4,    39,    61,    62,    63,     3,     4,     5,     3,     4,
       5,    30,    42,    65,    37,    34,    35,    36,    37,    37,
      39,    40,    37,   108,    34,    35,    43,    96,    36,    98,
       4,    97,    30,     4,    37,    30,    34,    35,   107,    37,
      36,    38,    37,    27,    28,    29,   112,    99,   100,    18,
      19,    38,    21,    22,    23,    24,    25,    26,    34,    35,
      39,    37,    47,    48,    49,    41,    52,    53,    54,    55,
      56,    57,    50,    51,    36,    58,    59,    60,    38,    38,
      38,    36,    13,    36,    38,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    30,    34,    35,    36,    37,    39,    47,    48,
      49,    51,    52,    53,    54,    55,    56,    57,    58,    34,
      35,    37,    41,     4,    37,    37,    51,    37,     4,    58,
       4,     4,    51,    47,    50,    51,    36,    27,    28,    29,
      18,    19,    21,    22,    23,    24,    25,    26,    16,    17,
      20,    31,    32,    33,    11,    42,    38,    51,    37,    51,
      51,    36,     4,    49,    38,    40,    47,    36,    53,    53,
      53,    55,    55,    54,    54,    54,    54,    54,    54,    56,
      56,    56,    58,    58,    58,    51,    38,    38,    38,    36,
      12,    43,    48,    47,    48,    51,    51,    13,    36,    43,
      48,    49,    38,    47
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1787 of yacc.c  */
#line 73 "calc5.y"
    { /*exit(0);*/ }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 77 "calc5.y"
    {
		  						object value = ex((yyvsp[(2) - (3)].nPtr));
		  						
								if (handTyped)
								{
									ex(opr(PRINT, 1, con(value)));
									printf("\n##> ");
								}
								/* freeNode($2); */
							}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 87 "calc5.y"
    {
								ex((yyvsp[(2) - (2)].nPtr));
								if (handTyped) printf("\n##> ");
								/* freeNode($2); */
							}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 96 "calc5.y"
    { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 97 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 98 "calc5.y"
    { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[(2) - (3)].nPtr)); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 99 "calc5.y"
    { defFunc((yyvsp[(2) - (5)].sValue), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 100 "calc5.y"
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 101 "calc5.y"
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 102 "calc5.y"
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 103 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 104 "calc5.y"
    { (yyval.nPtr) = opr(FOR, 4, (yyvsp[(3) - (9)].nPtr), (yyvsp[(5) - (9)].nPtr), (yyvsp[(7) - (9)].nPtr), (yyvsp[(9) - (9)].nPtr)); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 108 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 112 "calc5.y"
    { (yyval.nPtr) = opr('=', 2, id((yyvsp[(1) - (3)].sValue)), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 113 "calc5.y"
    { (yyval.nPtr) = opr(OP_POSTINC, 1, id((yyvsp[(1) - (2)].sValue))); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 114 "calc5.y"
    { (yyval.nPtr) = opr(OP_PREINC , 1, id((yyvsp[(2) - (2)].sValue))); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 115 "calc5.y"
    { (yyval.nPtr) = opr(OP_POSTDEC, 1, id((yyvsp[(1) - (2)].sValue))); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 116 "calc5.y"
    { (yyval.nPtr) = opr(OP_PREDEC , 1, id((yyvsp[(2) - (2)].sValue))); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 120 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 121 "calc5.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 125 "calc5.y"
    { (yyval.nPtr) = opr(FUNCTION, 1, fid((yyvsp[(1) - (3)].sValue))); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 126 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 127 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 131 "calc5.y"
    { (yyval.nPtr) = opr(OP_LXOR , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 132 "calc5.y"
    { (yyval.nPtr) = opr(OP_LOR  , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 133 "calc5.y"
    { (yyval.nPtr) = opr(OP_LAND , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 134 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 137 "calc5.y"
    { (yyval.nPtr) = opr(OP_EQ   , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 138 "calc5.y"
    { (yyval.nPtr) = opr(OP_NEQ  , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 139 "calc5.y"
    { (yyval.nPtr) = opr(OP_GT   , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 140 "calc5.y"
    { (yyval.nPtr) = opr(OP_LT   , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 141 "calc5.y"
    { (yyval.nPtr) = opr(OP_GTE  , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 142 "calc5.y"
    { (yyval.nPtr) = opr(OP_LTE  , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 143 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 146 "calc5.y"
    { (yyval.nPtr) = opr(OP_PLUS , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 147 "calc5.y"
    { (yyval.nPtr) = opr(OP_MINUS, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 151 "calc5.y"
    { (yyval.nPtr) = opr(OP_MUL  , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 152 "calc5.y"
    { (yyval.nPtr) = opr(OP_DIV  , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 153 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 156 "calc5.y"
    { (yyval.nPtr) = opr(OP_POW  , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 160 "calc5.y"
    { (yyval.nPtr) = opr(OP_BNOT , 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 161 "calc5.y"
    { (yyval.nPtr) = opr(OP_BXOR , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 162 "calc5.y"
    { (yyval.nPtr) = opr(OP_BOR  , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 163 "calc5.y"
    { (yyval.nPtr) = opr(OP_BAND , 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 164 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 168 "calc5.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 169 "calc5.y"
    { (yyval.nPtr) = conInt((yyvsp[(1) - (1)].iValue)); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 170 "calc5.y"
    { (yyval.nPtr) = conStr((yyvsp[(1) - (1)].sValue)); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 171 "calc5.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (1)].sValue)); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 172 "calc5.y"
    { (yyval.nPtr) = opr('[', 2, (yyvsp[(1) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr)); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 173 "calc5.y"
    { (yyval.nPtr) = opr('[', 3, (yyvsp[(1) - (6)].nPtr), (yyvsp[(3) - (6)].nPtr), (yyvsp[(5) - (6)].nPtr)); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 174 "calc5.y"
    { (yyval.nPtr) = opr(DOTLENGTH, 1, (yyvsp[(1) - (2)].nPtr)); }
    break;


/* Line 1787 of yacc.c  */
#line 1877 "y.tab.c"
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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


/* Line 2050 of yacc.c  */
#line 177 "calc5.y"


nodeType *con(object o)
{
	nodeType *p;
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{
		yyerror("out of memory");
	}
	p->type = typeConVal;
	p->con.val = o;
	return p;
}

nodeType *conInt(int value)
{
	nodeType *p;
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{
		yyerror("out of memory");
	}
	object o;
	o.type = VAR_INT;
	o.valInt = value;
	p->type = typeConVal;
	p->con.val = o;
	return p;
}

nodeType *conStr(char* str)
{
	nodeType *p;
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{
		yyerror("out of memory");
	}
	object o;
	o.type = VAR_STR;
	o.valStr = str;
	p->type = typeConVal;
	p->con.val = o;
	return p;
}

nodeType *fid(char* name)
{
	return id(name);
/*	nodeType* p;
	if ((p = malloc(sizeof(nodeType))) == NULL) yyerror("out of memory");
	p->type = typeFid;
	p->id.name = name;
	int i = 0;
	while (i<funcCount)
	{
		if (strcmp(funcNames[i], name)==0)
		{
			p->id.position = i;
			break;
		}
		i++;
	}
	if (i==funcCount)
	{
		printf("Error: Non-existant function %s\n", name);
		p->id.position = -1;
	}
	return p;*/
}

nodeType *id(char* name) // Variable
{
	nodeType *p;
	if ((p = malloc(sizeof(nodeType))) == NULL) yyerror("out of memory");
	p->type = typeId;
	p->id.name = name;
	int i = 0;
	while (i<varCount)
	{
		if (strcmp(varNames[i], name)==0)
		{
			p->id.position = i;
			break;
		}
		i++;
	}
	if (i==varCount)
	{
		if (varCount==16)
		{
			printf("Error: Non-existant variable %s\n", name);
			printf("Error: Max amount of variables is currently 16.\n");
			p->id.position = -1;
		}
		else
		{
		  	varNames[varCount] = name;
			varValues[varCount].valInt = 0;
			p->id.position = varCount;
			varCount++;
		}
	}
	return p;
}

nodeType *opr(int oper, int nops, ...) // if, for, while, print, assign
{
	va_list ap;
	nodeType *p;
	int i;
	if ((p = malloc(sizeof(nodeType))) == NULL)
	{
		yyerror("out of memory");
	}
	if ((p->opr.op = malloc(nops * sizeof(nodeType))) == NULL)
	{
		yyerror("out of memory");
	}
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
	{
		p->opr.op[i] = va_arg(ap, nodeType*);
	}
	va_end(ap);
	return p;
}

void freeNode(nodeType *p)
{
	int i;
	if (!p) return;
	if (p->type == typeOpr)
	{
		for (i = 0; i < p->opr.nops; i++)
		{
			freeNode(p->opr.op[i]);
		}
		free (p->opr.op);
	}
	free (p);
}

void yyerror(char *s)
{
	if (s[0]=='s' || s[1]=='y' || s[2]=='n' || s[3]=='t' || s[4]=='a' || s[5]=='x')
	{
		printf("Syntax error on line %i\n", line);
		return;
	}
	//printf("yyerror(..) called\n");
	fprintf(stdout, "%s\n", s);
}
