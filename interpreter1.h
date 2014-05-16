
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
/* Line 2053 of yacc.c  */
#line 47 "calc5.y"

	int iValue;					/* integer value */
	char* sValue;				/* string value */
	nodeType *nPtr;				/* node pointer */


/* Line 2053 of yacc.c  */
#line 134 "y.tab.h"
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
