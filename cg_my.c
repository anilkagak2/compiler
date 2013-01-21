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
    /* statements →     id := relation
	            | if relation then statements
	            | while relation do statements
	            | begin opt_stmts end
    */
//    printf("in statements : ------- %s\n",yytext);

    //while( !match(EOI) ){

        if( match( BEGIN ) ){
            printf("begin\n");
            advance();
            opt_stmts();

            if ( match (END)) {
                printf("end\n");
                advance();
            }
            else
            fprintf(stderr, "%d: syntax error : missing end\n",yylineno );
        }

        else if (match (IF)) {
            advance ();
            char *tempvar = relation ();

            if (match (THEN)) {
                advance ();
                printf ("   if %s then\n", tempvar);
                statements ();
            }
            else {
                fprintf (stderr,"%d: missing then\n",yylineno);
            }

            freename (tempvar);
        }
 
        else if (match (WHILE)) {
            advance ();
            char *tempvar = relation ();

            if (match (DO)) {
                advance ();
                printf ("   while %s do\n", tempvar);
                statements ();
            }
            else {
                fprintf (stderr,"%d: missing do\n",yylineno);
            }

            freename (tempvar);
        }
 
        else if (match (ID)) {
            char id[1024];
            strncpy(id,yytext,yyleng);
            id[yyleng] = '\0';
            advance ();
    
            if(match(ASSIGN)){
                advance();
                char *tempvar = relation ();
                printf("    %s = %s\n",id,tempvar);
                freename(tempvar);
            }else{

                printf("%d:missing ASSIGN opertor\n",yylineno);
            }

        }


        else if( match( EOI ) ) return;
        //Enter other else ifs such as 'if then', 'while-do' here 
        else{
            printf("Please check the grammar.\n");
        }
        //}

}

opt_stmts(){
    //    printf("in opt_statements : ------ %s\n",yytext);
    // example : "begin end"
    if( !match( END ) ){  
        //    printf("opt_list : not END \n"); 
        stmt_list();
    }
}

stmt_list(){
    //    printf("in statements_list : ------ %s\n",yytext);
    statements();
    while( match( SEMI ) )
    {
        advance();
        statements();
        //  fprintf(stdout," statement list ");
    } 

}


/*
   statements()
   {
   */   /*  statements -> expression SEMI  |  expression SEMI statements  */

/*    char *tempvar;

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
}*/








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

    //if( match(NUM_OR_ID) )
    if( match(NUM) || match(ID) )
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
