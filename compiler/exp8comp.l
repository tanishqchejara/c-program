%{
#include <stdio.h>
int vowel_count = 0;
int consonant_count = 0;
%}

%option noyywrap

%%

[a-zA-Z] {
    if (yytext[0] == 'a' || yytext[0] == 'e' || yytext[0] == 'i' || yytext[0] == 'o' || yytext[0] == 'u' || yytext[0] == 'A' || yytext[0] == 'E' || yytext[0] == 'I' || yytext[0] == 'O' || yytext[0] == 'U') {
        vowel_count++;
    } else {
        consonant_count++;
    }
}

. ;  // Ignore everything else

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

    printf("Vowel count: %d\n", vowel_count);
    printf("Consonant count: %d\n", consonant_count);

    return 0;
}

