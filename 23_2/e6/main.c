// Author: Vinicius Fraga Coromberque - 00302369
// 12/11/2023

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ast.h"
#include "tac.h"
#include "asm.h"

extern FILE *yyin;
int yyparse();
int getLineNumber();

extern int checkSemantic();
extern void generateAsm(tac *firstTac, AST *ast);

extern AST *getRoot();
extern tac *getTACs();

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

    hashPrint();

    checkSemantic();
    fprintf(stderr, "No Semantic Errors.\n");

    fprintf(stderr, "\nTACs:\n");
    printAllTacs(getTACs());

    astPrintCode(getRoot(), output);

    fprintf(stderr, "\nCompiling to an *.s file\n\n");
    generateAsm(getTACs(), getRoot());

    exit(0);
}