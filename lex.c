#include "lex.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 1024

char* yytext = ""; /* Lexeme (not '\0'
                      terminated)              */
int yyleng   = 0;  /* Lexeme length.           */
int yylineno = 0;  /* Input line number        */

int lex(void){

   static char input_buffer[1024];
   char        *current;

   current = yytext + yyleng; /* Skip current
                                 lexeme        */

   while(1){       /* Get the next one         */
      while(!*current ){
         /* Get new lines, skipping any leading
         * white space on the line,
         * until a nonblank line is found.
         */

         current = input_buffer;
         if(!gets(input_buffer)){
            *current = '\0' ;

            return EOI;
         }
         ++yylineno;
         while(isspace(*current))
            ++current;
      }
      for(; *current; ++current){
         /* Get the next token */
         yytext = current;
         yyleng = 1;
         switch( *current ){
           case ';':
            return SEMI;
           case '+':
            return PLUS;
           case '-':
            return MINUS;
           case '*':
            return TIMES;
           case '/':
            return DIV;
           case '=':
            return EQUAL;
           case '<':
            return LT;
           case '>':
            return GT;
           case '(':
            return LP;
           case ')':
            return RP;
           case '\n':
           case '\t':
           case ' ' :
            break;
           default:
            if(!isalnum(*current))
               fprintf(stderr, "Agvonse la8emevn eisagwgn <%c>\n", *current);
            else{
               while(isalnum(*current))
                  ++current;
               yyleng = current - yytext;
               
               char token[MAX_LEN];
               strncpy(token,yytext,yyleng);
               token[yyleng] = '\0';

               if(strcmp(token,"begin") == 0 ){
            //        printf("in BEGIN\n");
                   return BEGIN; 
               }
                else if(strcmp(token,"end") == 0 ){
             //       printf("in END\n");
                    return END; 
                }
                else if(strcmp(token,"if") == 0 ){
                    printf("in IF\n");
                    return IF; 
                }
                else if(strcmp(token,"then") == 0 ){
                    printf("in THEN\n");
                    return THEN; 
                }
                else if(strcmp(token,"while") == 0 ){
                    printf("in WHILE\n");
                    return WHILE; 
                }
                else if(strcmp(token,"do") == 0 ){
                    printf("in DO\n");
                    return DO; 
                }
                else if(strcmp(token,":=") == 0 ){
                    printf("in ASSIGN\n");
                    return ASSIGN; 
                }
               return NUM_OR_ID;
            }
            break;
         }
      }
   }
}


static int Lookahead = -1; /* Lookahead token  */

int match(int token){
   /* Return true if "token" matches the
      current lookahead symbol.                */

   if(Lookahead == -1)
      Lookahead = lex();

   return token == Lookahead;
}

void advance(void){
/* Advance the lookahead to the next
   input symbol.                               */

    Lookahead = lex();
}
