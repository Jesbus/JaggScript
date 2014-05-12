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
     FUNCTION = 260,
     WHILE = 261,
     IF = 262,
     PRINT = 263,
     FOR = 264,
     IFX = 265,
     ELSE = 266,
     OP_AND = 267,
     OP_OR = 268,
     OP_MUL = 269,
     OP_DIV = 270,
     OP_MINUS = 271,
     OP_PLUS = 272,
     OP_LT = 273,
     OP_GT = 274,
     OP_LTE = 275,
     OP_GTE = 276,
     OP_NEQ = 277,
     OP_EQ = 278,
     OP_LXOR = 279,
     OP_LOR = 280,
     OP_LAND = 281,
     OP_BNOT = 282,
     OP_BXOR = 283,
     OP_BOR = 284,
     OP_BAND = 285,
     OP_DECREMENT = 286,
     OP_INCREMENT = 287
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define IDENTIFIER 259
#define FUNCTION 260
#define WHILE 261
#define IF 262
#define PRINT 263
#define FOR 264
#define IFX 265
#define ELSE 266
#define OP_AND 267
#define OP_OR 268
#define OP_MUL 269
#define OP_DIV 270
#define OP_MINUS 271
#define OP_PLUS 272
#define OP_LT 273
#define OP_GT 274
#define OP_LTE 275
#define OP_GTE 276
#define OP_NEQ 277
#define OP_EQ 278
#define OP_LXOR 279
#define OP_LOR 280
#define OP_LAND 281
#define OP_BNOT 282
#define OP_BXOR 283
#define OP_BOR 284
#define OP_BAND 285
#define OP_DECREMENT 286
#define OP_INCREMENT 287



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 36 "calc5.y"

    int iValue;                 /* integer value */
    //char sIndex;                /* symbol table index */
    char* sValue;				/* string value */
    nodeType *nPtr;             /* node pointer */


/* Line 2053 of yacc.c  */
#line 129 "y.tab.h"
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
