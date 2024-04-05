%{
#include <stdio.h>
int operator_count = 0;
%}

%%

[+\-*/=<>!&|^%]  { operator_count++; }
.                 { /* Ignore other characters */ }

%%

int yywrap() {
    printf("Total number of operators: %d\n", operator_count);
    return 1;
}

int main() {
    yylex();
    return 0;
}

