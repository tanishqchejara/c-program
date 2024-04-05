%{
#include <stdio.h>
int space_count = 0;
int word_count = 0;
int line_count = 0;
%}

%option noyywrap

%%

[ \t]   { space_count++; }
\n      { line_count++; }
[a-zA-Z]+   { word_count++; }

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file;
    yylex();

    fclose(file);

    printf("Blank Spaces: %d\n", space_count);
    printf("Words: %d\n", word_count);
    printf("Lines: %d\n", line_count);

    return 0;
}

