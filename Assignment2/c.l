%{
#include "lex.h"
/*typedef struct sym_holder {
    char *id;
    int num;
} sym_holder;

sym_holder yylval;
*/
%}
 
digit         [0-9]
letter        [a-zA-Z]
 
%%
"+"                  { return PLUS;       }
"-"                  { return MINUS;      }
"*"                  { return TIMES;      }
"("                  { return LP;     }
")"                  { return RP;     }
";"                  { return SEMI;  }
"="                  { return ASSIGN;        }
"<"                  { return LT;        }
">"                  { return GT;        }
"if"                 { return IF;      }
"while"              { return WHILE;   }
{letter}({letter}|{digit})* {
                       //yylval.id = strdup(yytext);
                       return ID;      }
{digit}+             { //yylval.num = atoi(yytext);
                       return NUM;     }
[ \t\n\r]            /* skip whitespace */
.                    { printf("Unknown character [%c]\n",yytext[0]);
                       return UNKNOWN;    }
%%
 
int yywrap(void){return 1;}
