%{
#include <stdio.h>
%}

%%

int|float|char|void  { printf("'%s' is a keyword.\n", yytext); }
[a-zA-Z][a-zA-Z0-9]* { printf("'%s' is not a keyword.\n", yytext); }
.                     { printf("Invalid input.\n"); }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}

