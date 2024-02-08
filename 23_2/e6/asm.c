// ASM
// Author: Vinicius Fraga Coromberque - 00302369
// 05/02/2023

#include "asm.h"

void generateAsm(tac *firstTac, AST *ast)
{

    FILE *outputFile = fopen("asm.s", "w");

    fprintf(outputFile, "printIntStr:\n"
                        "\t.string	\"%%d\n\n");

    fprintf(outputFile, "printFloatStr:\n"
                        "\t.string	\"%%f\n\n");

    fprintf(outputFile, "printCharStr:\n"
                        "\t.string	\"%%c\n\n");

    int dec = 0;

    tac *itTac = firstTac;
    for (itTac = firstTac; itTac; itTac = itTac->next)
    {
        switch (itTac->type)
        {
        case TAC_MOVE:
            fprintf(outputFile, "##TAC_MOVE\n"
                                "\tmovl	$%s, %s(%%rip)\n\n",
                    itTac->op1 ? itTac->op1->text : 0, itTac->res->text);
            break;

        case TAC_MOVEVEC:
            fprintf(outputFile, "##Assembly code \n");
            break;

        case TAC_PRINT:
            if (!itTac->res->dataType)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	$%s, %%esi\n"
                                    "\tleaq	printStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            else if (itTac->res->dataType == DATATYPE_CHAR)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	$%s, %%esi\n"
                                    "\tleaq	printCharStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            else if (itTac->res->dataType == DATATYPE_FLOAT)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	$%s, %%esi\n"
                                    "\tleaq	printFloarStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            else if (itTac->res->dataType == DATATYPE_INT)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	$%s, %%esi\n"
                                    "\tleaq	printIntStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            break;

        case TAC_ADD:
            fprintf(outputFile, "##TAC_ADD\n"
                                "\tmovl	%s(%%rip), %%eax\n"
                                "\taddl	$%s, %%eax\n"
                                "\tmovl	%%eax, %s(%%rip)\n\n",
                    itTac->op1->text, itTac->op2->text, itTac->res->text);
            break;

        case TAC_SUB:
            fprintf(outputFile, "##Assembly code \n\n");
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
            if (dec == 0)
            {
                fprintf(outputFile, "\t.data \n");
                dec = 1;
            }
            fprintf(outputFile, "%s: \n", itTac->res->text);
            fprintf(outputFile, "\t.long\t%s\n", itTac->op1->text);
            break;

        default:
            break;
        }
    }

    return;
}