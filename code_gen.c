#include <stdio.h>
#include "lex.h"

char    *factor     ( void );
char    *term       ( void );
char    *expression ( void );
char    *relation   ( void );

extern char *newname( void       );
extern void freename( char *name );




statements()
{
    /*  statements -> expression SEMI  |  expression SEMI statements  */

    char *tempvar;

    while( !match(EOI) )
    {
        //tempvar = expression();
        tempvar = relation();

        if( match( SEMI ) )
            advance();
        else
            fprintf( stderr, "%d: Inserting missing semicolon\n", yylineno );

        freename( tempvar );
    }
}








char    *relation()
{
    /* relation -> expression relation'
     * relation' -> (EQUAL | LT | GT) expression relation'' |  epsilon
     */

    char  *tempvar, *tempvar2;
    int equal;
    int lt;

tempvar = expression();
while( ( equal = match( EQUAL ) ) || ( lt = match( LT )) || match( GT ) )
{
    advance();
    tempvar2 = expression();
        if( equal )
        printf("    %s = %s == %s\n", tempvar, tempvar, tempvar2 );
        else if( lt )
        printf("    %s = %s < %s\n", tempvar, tempvar, tempvar2 );
        else
        printf("    %s = %s > %s\n", tempvar, tempvar, tempvar2 );
        freename( tempvar2 );
    }

    return tempvar;
}



char    *expression()
{
    /* expression -> term expression'
     * expression' -> PLUS term expression' |  epsilon
     */

    char  *tempvar, *tempvar2;
    int plus;

    tempvar = term();
    while( ( plus = match( PLUS ) ) || match( MINUS ) )
    {
        advance();
        tempvar2 = term();
        if( plus )
        printf("    %s += %s\n", tempvar, tempvar2 );
        else
        printf("    %s -= %s\n", tempvar, tempvar2 );
        freename( tempvar2 );
    }

    return tempvar;
}

char    *term()
{
    char  *tempvar, *tempvar2 ;
    int times;
    tempvar = factor();
    while( ( times = match( TIMES )) || match( DIV ) )
    {
        advance();
        tempvar2 = factor();
        if( times )
        printf("    %s *= %s\n", tempvar, tempvar2 );
        else 
        printf("    %s /= %s\n", tempvar, tempvar2 );
        freename( tempvar2 );
    }

    return tempvar;
}

char    *factor()
{
    char *tempvar;

    if( match(NUM_OR_ID) )
    {
	/* Print the assignment instruction. The %0.*s conversion is a form of
	 * %X.Ys, where X is the field width and Y is the maximum number of
	 * characters that will be printed (even if the string is longer). I'm
	 * using the %0.*s to print the string because it's not \0 terminated.
	 * The field has a default width of 0, but it will grow the size needed
	 * to print the string. The ".*" tells printf() to take the maximum-
	 * number-of-characters count from the next argument (yyleng).
	 */

        printf("    %s = %0.*s\n", tempvar = newname(), yyleng, yytext );
        advance();
    }
    else if( match(LP) )
    {
        advance();
        //tempvar = expression();
        tempvar = relation();
        if( match(RP) )
            advance();
        else
            fprintf(stderr, "%d: Mismatched parenthesis\n", yylineno );
    }
    else
	fprintf( stderr, "%d: Number or identifier expected\n", yylineno );

    return tempvar;
}
