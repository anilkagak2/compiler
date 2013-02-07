#define EOI		0	/* End of input			*/
#define SEMI	    	1	/* ; 				*/
#define PLUS 		2	/* + 				*/
#define TIMES		3	/* * 				*/
#define LP		4	/* (				*/
#define RP		5	/* )				*/
#define NUM     	6	/* Decimal Number		*/
#define MINUS      	7	/* -				*/
#define DIV        	8	/* /				*/
#define EQUAL       	9	/* ==	here it is =		*/
#define LT          	10	/* <				*/
#define GT          	11	/* >				*/

#define BEGIN       	12	/* begin			*/
#define END         	13	/* end				*/
#define IF          	14	/* if				*/
#define THEN        	15	/* then				*/
#define WHILE       	16	/* while			*/
#define DO          	17	/* do				*/
#define ASSIGN      	18	/* assign			*/

#define ID          	19	/* Identifier			 */

extern char *yytext;		/* in lex.c			*/
extern int yyleng;
extern yylineno;
