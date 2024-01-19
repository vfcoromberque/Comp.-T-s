// Author: Vinicius Fraga Coromberque - 00302369
// 12/11/2023

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ast.h"

extern FILE *yyin;
extern AST *getRoot();
int yyparse();
int getLineNumber();

extern int checkSemantic();

int main(int argc, char **argv)
{
    int tok;

    FILE *output;

    if (argc < 3)
    {
        fprintf(stderr, "Call: ./etapa4 file_name file_name\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    if (yyin == 0)
    {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        exit(2);
    }

    output = fopen(argv[2], "w+");
    if (output == 0)
    {
        fprintf(stderr, "Cannot open file %s\n", argv[2]);
        exit(2);
    }

    hashInit();

    yyparse();

    // printf("Main done %d linhas\n", getLineNumber());

    // hashPrint();

    checkSemantic();
    fprintf(stderr, "No Semantic Errors.\n");

    astPrintCode(getRoot(), output);

    exit(0);
}