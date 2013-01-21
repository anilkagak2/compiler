#define EOI		    0	/* End of input			*/
#define SEMI	    1	/* ; 				*/
#define PLUS 		2	/* + 				*/
#define TIMES		3	/* * 				*/
#define LP		    4	/* (				*/
#define RP		    5	/* )				*/
#define NUM_OR_ID	6	/* Decimal Number or Identifier */
#define MINUS       7
#define DIV         8
#define EQUAL       9
#define LT          10
#define GT          11

#define BEGIN       12
#define END         13
#define IF          14
#define THEN        15
#define WHILE       16
#define DO          17
#define ASSIGN      18

extern char *yytext;		/* in lex.c			*/
extern int yyleng;
extern yylineno;
