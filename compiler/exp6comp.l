%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

%%

^[1-9][0-9]{9}$           { printf("Valid mobile number: %s\n", yytext); }
((http|https):\/\/)?      { printf("Valid URL: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*    { printf("Valid identifier: %s\n", yytext); }
(0[1-9]|[12][0-9]|3[01])\/(0[1-9]|1[012])\/\d{4}  { printf("Valid date: %s\n", yytext); }
([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]          { printf("Valid time: %s\n", yytext); }
.                          { printf("Invalid input.\n"); }

%%

int main() {
    yylex();
    return 0;
}

