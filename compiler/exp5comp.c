#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100

typedef struct {
    char name[50];
    int value;
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

void insertSymbol(const char *name, int value) {
    if (symbolCount < MAX_SYMBOLS) {
        strcpy(symbolTable[symbolCount].name, name);
        symbolTable[symbolCount].value = value;
        symbolCount++;
        printf("Inserted: %s\n", name);
    } else {
        printf("Symbol table full. Cannot insert.\n");
    }
}

void deleteSymbol(const char *name) {
    int i;
    for (i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Deleted: %s\n", name);
            for (int j = i; j < symbolCount - 1; j++) {
                strcpy(symbolTable[j].name, symbolTable[j + 1].name);
                symbolTable[j].value = symbolTable[j + 1].value;
            }
            symbolCount--;
            return;
        }
    }
    printf("Symbol '%s' not found.\n", name);
}

void displaySymbolTable() {
    printf("Symbol Table:\n");
    printf("Name\tValue\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%s\t%d\n", symbolTable[i].name, symbolTable[i].value);
    }
}

int main() {
    insertSymbol("x", 10);
    insertSymbol("y", 20);
    insertSymbol("z", 30);

    displaySymbolTable();

    deleteSymbol("y");

    displaySymbolTable();

    return 0;
}

