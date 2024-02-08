// ASM
// Author: Vinicius Fraga Coromberque - 00302369
// 05/02/2023

#include "asm.h"

extern HASH_NODE *Table[HASH_SIZE];

void generateAsm(tac *firstTac, AST *ast)
{

    FILE *outputFile = fopen("asm.s", "w");

    fprintf(outputFile, "printIntStr:\n"
                        "\t.string	\"%%d\"\n\n");

    fprintf(outputFile, "printFloatStr:\n"
                        "\t.string	\"%%f\"\n\n");

    fprintf(outputFile, "printCharStr:\n"
                        "\t.string	\"%%c\"\n\n");

    int i;
    HASH_NODE *node;
    for (i = 0; i < HASH_SIZE; ++i)
        for (node = Table[i]; node; node = node->next)
        {
            if (node->type == SYMBOL_LIT_STRING)
            {
                fprintf(outputFile, "_s%d: \n", node->strCode);
                fprintf(outputFile, "\t.string\t%s\n\n", node->text);
            }
        }

    fprintf(outputFile, "\t.data \n");
    int j;
    HASH_NODE *nodeFin;
    for (j = 0; j < HASH_SIZE; ++j)
        for (nodeFin = Table[j]; nodeFin; nodeFin = nodeFin->next)
        {
            if (nodeFin->type == SYMBOL_LIT_INT)
            {
                fprintf(outputFile, "_%s: \n", nodeFin->text);
                fprintf(outputFile, "\t.long\t%s\n", nodeFin->text);
            }
            else if (nodeFin->type == SYMBOL_VAR || !strncmp(nodeFin->text, "_temp", (long unsigned)5) || nodeFin->type == SYMBOL_VECTOR)
            {
                fprintf(outputFile, "_%s: \n", nodeFin->text);
                fprintf(outputFile, "\t.long\t%d\n", 0);
            }
            else if (SYMBOL_LIT_CHAR && nodeFin->text[0] == '\'')
            {
                fprintf(outputFile, "_char%c: \n", nodeFin->text[1]);
                fprintf(outputFile, "\t.long\t%d\n", nodeFin->text[1] - '0');
            }
        }

    tac *itTac = firstTac;

    for (itTac = firstTac; itTac; itTac = itTac->next)
    {
        switch (itTac->type)
        {
        case TAC_MOVE:
            fprintf(outputFile, "##TAC_VARDEC\n");
            if (SYMBOL_LIT_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), ", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), ", itTac->op1->text);
            fprintf(outputFile, "%%eax\n");
            fprintf(outputFile, "\tmovl	%%eax, ");
            fprintf(outputFile, "_%s(%%rip)\n\n", itTac->res->text);
            break;

        case TAC_MOVEVEC:
            fprintf(outputFile, "##Assembly code \n");
            break;

        case TAC_PRINT:
            if (!itTac->res->dataType)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	_s%d, %%esi\n"
                                    "\tleaq	printStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->strCode);
            else if (itTac->res->dataType == DATATYPE_CHAR)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	_%s, %%esi\n"
                                    "\tleaq	printCharStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            else if (itTac->res->dataType == DATATYPE_FLOAT)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	_%s, %%esi\n"
                                    "\tleaq	printFloarStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            else if (itTac->res->dataType == DATATYPE_INT)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	_%s, %%esi\n"
                                    "\tleaq	printIntStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            break;

        case TAC_ADD:
            fprintf(outputFile, "##TAC_ADD\n");
            if (SYMBOL_LIT_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%eax\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op1->text);
            if (SYMBOL_LIT_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\taddl	_char%c(%%rip), %%eax\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\taddl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tmovl	%%eax, %s(%%rip)\n\n", itTac->res->text);
            break;

        case TAC_SUB:
            fprintf(outputFile, "##TAC_SUB\n");
            if (SYMBOL_LIT_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%eax\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op1->text);
            if (SYMBOL_LIT_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tsubl	_char%c(%%rip), %%eax\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tsubl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tmovl	%%eax, %s(%%rip)\n\n", itTac->res->text);
            break;
        case TAC_MUL:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_DIV:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_EQ:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_NOT:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_GTR:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_LSS:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_LE:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_GE:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_DIF:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_OR:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_AND:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_LABEL:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_FOOSTART:
            fprintf(outputFile, "##TAC_FOOSTART\n"
                                "\t.globl	%s\n"
                                "%s:\n"
                                "\tpushq	%%rbp\n"
                                "\tmovq	%%rsp, %%rbp \n\n",
                    itTac->res->text, itTac->res->text);
            break;

        case TAC_FOOEND:
            fprintf(outputFile, "##TAC_FOOEND\n"
                                "\tpopq	%%rbp\n"
                                "\tret\n\n");
            break;

        case TAC_IFS:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_JUMP:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_FOOCALL:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_ARG:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_RETURN:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_VECCALL:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_VECVAR:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_VECINIT:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_INPUT:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_PARAM:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_LIST:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_VARDEC:
            fprintf(outputFile, "##TAC_VARDEC\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), ", itTac->op1->text[1]);
            else if (itTac->op1->dataType == DATATYPE_FLOAT)
                fprintf(outputFile, "\tmovl	_%d(%%rip), ", strtof(itTac->op1->text, NULL));
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), ", itTac->op1->text);
            fprintf(outputFile, "%%eax\n");
            fprintf(outputFile, "\tmovl	%%eax, ");
            fprintf(outputFile, "_%s(%%rip)\n\n", itTac->res->text);
            break;

        default:
            break;
        }
    }

    return;
}