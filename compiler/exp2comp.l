%{
#include <stdio.h>
int keyword_count = 0;
%}

%%

int|float|char|void  { keyword_count++; }
[a-zA-Z][a-zA-Z0-9]* { /* Ignore identifiers */ }
.                     { /* Ignore other characters */ }

%%

int yywrap() {
    printf("Total number of keywords: %d\n", keyword_count);
    return 1;
}

int main() {
    yylex();
    return 0;
}

