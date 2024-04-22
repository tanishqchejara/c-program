%{
/* Definition section */
#include "y.tab.h"
%}

%%
[0-9]+ {
    yylval = atoi(yytext);
    return NUMBER;
}

[a-zA-Z]+ { return ID; }
[ \t]+ ; /* For skipping whitespaces */
\n { return 0; }
. { return yytext[0]; }
%%

int yywrap() {
    return 1; /* Return 1 to indicate the end of input */
}