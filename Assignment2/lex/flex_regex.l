%{
#include <math.h>
%}

Digit		[0-9]
Letter		[a-zA-Z]
ID		[_a-zA-Z][_a-zA-Z0-9]*

%%
int|float|char|if|else|for|return|void|do|while	{
				printf ("<Keyword, %s>\n", yytext);
			}

#define|#include	{
				printf ("<Preprocessor, %s>\n", yytext);
			}

{Digit}+"."{Digit}+	{
				printf ("<Float, %f>\n", atof (yytext));
		    	}

{Digit}+	   	{
				printf ("<Integer, %d>\n", atoi (yytext));
		    	}

{ID}			{
				printf ("<Identifier, %s>\n", yytext);
			}

"+"|"-"|"*"|"/"|"=="|"<="|"!="|">="|<|>|= 	{
					printf ("<Operator, %s>\n", yytext);
				}

"{"|"}"|";"|","|"("|")"|"#"|"\""|"'"|"//"		{
					printf ("<Special Symbol, %s>\n", yytext);
				}

[ \t\n]			{
				printf ("<Whitespace, %s>\n", yytext);
			}

%%
int
main (int argc, char *argv[]) {
        ++argv, --argc;  /* skip over program name */
        if ( argc > 0 )
                yyin = fopen( argv[0], "r" );
        else
                yyin = stdin;

        yylex();
	return 1;
}
