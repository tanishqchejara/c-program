%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 256
int char_count[MAX_CHARACTERS] = {0};
%}

%%

. { char_count[(int)yytext[0]]++; }
\n { /* Ignore newline characters */ }

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int c;
    yyin = file;
    yylex();

    fclose(file);

    printf("Character Counts:\n");
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (char_count[i] > 0) {
            printf("'%c': %d\n", (char)i, char_count[i]);
        }
    }

    return 0;
}

