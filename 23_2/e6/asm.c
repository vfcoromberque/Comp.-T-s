// ASM
// Author: Vinicius Fraga Coromberque - 00302369
// 05/02/2023

#include "asm.h"

extern HASH_NODE *Table[HASH_SIZE];

void generateAsm(tac *firstTac, AST *ast)
{

    FILE *outputFile = fopen("asm.s", "w");

    tac *itTac = firstTac;

    int auxLabel = 0;

    for (itTac = firstTac; itTac; itTac = itTac->next)
    {
        switch (itTac->type)
        {
        case TAC_MOVE:
            fprintf(outputFile, "##TAC_MOVE\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
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
                                    "\tleaq	_s%d(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->strCode);
            else if (itTac->res->dataType == DATATYPE_CHAR)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	_%s(%%rip), %%esi\n"
                                    "\tleaq	printCharStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            else if (itTac->res->dataType == DATATYPE_FLOAT)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	_%s(%%rip), %%esi\n"
                                    "\tleaq	printFloarStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            else if (itTac->res->dataType == DATATYPE_INT)
                fprintf(outputFile, "##TAC_PRINT\n"
                                    "\tmovl	_%s(%%rip), %%esi\n"
                                    "\tleaq	printIntStr(%%rip), %%rax\n"
                                    "\tmovq	%%rax, %%rdi\n"
                                    "\tcall	printf@PLT\n\n",
                        itTac->res->text);
            break;

        case TAC_ADD:
            fprintf(outputFile, "##TAC_ADD\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%eax\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op1->text);
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\taddl	_char%c(%%rip), %%eax\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\taddl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tmovl	%%eax, _%s(%%rip)\n\n", itTac->res->text);
            break;

        case TAC_SUB:
            fprintf(outputFile, "##TAC_SUB\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%eax\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op1->text);
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tsubl	_char%c(%%rip), %%eax\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tsubl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tmovl	%%eax, _%s(%%rip)\n\n", itTac->res->text);
            break;
        case TAC_MUL:
            fprintf(outputFile, "##TAC_MUL \n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            if (itTac->op2->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op2->text);
            fprintf(outputFile, "\timull	%%edx, %%eax\n");
            fprintf(outputFile, "\tmovl	%%eax, _%s(%%rip)\n\n", itTac->res->text);
            break;

        case TAC_DIV:
            fprintf(outputFile, "##TAC_DIV \n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            if (itTac->op2->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op2->text);
            fprintf(outputFile, "\tcltd\n");
            fprintf(outputFile, "\tidivl	%%ecx\n");
            fprintf(outputFile, "\tmovl	%%eax, _%s(%%rip)\n\n", itTac->res->text);
            break;

        case TAC_EQ:
            fprintf(outputFile, "##TAC_EQ\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tcmpl	%%eax, %%edx \n\n");
            break;

        case TAC_NOT:
            fprintf(outputFile, "##TAC_NOT \n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            fprintf(outputFile, "\ttestl	%%eax, %%eax\n");
            fprintf(outputFile, "\tsete	%%al\n");
            fprintf(outputFile, "\tmovzbl	%%al, %%eax\n");
            fprintf(outputFile, "\tmovl	%%eax, _%s(%%rip)\n", itTac->res->text);

            break;

        case TAC_GTR:
            fprintf(outputFile, "##TAC_GTR\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tcmpl	%%eax, %%edx \n\n");
            break;

        case TAC_LSS:
            fprintf(outputFile, "##TAC_LSS\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tcmpl	%%eax, %%edx \n\n");
            break;

        case TAC_LE:
            fprintf(outputFile, "##TAC_LSS\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tcmpl	%%eax, %%edx \n\n");
            break;

        case TAC_GE:
            fprintf(outputFile, "##TAC_LSS\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tcmpl	%%eax, %%edx \n\n");
            break;

        case TAC_DIF:
            fprintf(outputFile, "##TAC_LSS\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op1->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%edx\n", itTac->op1->text);
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op2->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), %%edx\n", itTac->op2->text[1]);
            else
                fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->op2->text);
            fprintf(outputFile, "\tcmpl	%%eax, %%edx \n\n");
            break;

            //        case TAC_OR:
            //            fprintf(outputFile, "##Ass \n\n");
            //            break;

            //        case TAC_AND:
            //            fprintf(outputFile, "##Ass \n\n");
            //            break;

        case TAC_LABEL:
            fprintf(outputFile, "##TAC_LABEL\n"
                                "_%s:\n\n",
                    itTac->res->text);
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

        case TAC_IF:
            if (itTac->prev->type == TAC_EQ)
                fprintf(outputFile, "##TAC_IF \n"
                                    "\tjne	_%s\n\n",
                        itTac->res->text);

            else if (itTac->prev->type == TAC_LSS)
                fprintf(outputFile, "##TAC_IF \n"
                                    "\tjge	_%s\n\n",
                        itTac->res->text);

            else if (itTac->prev->type == TAC_GTR)
                fprintf(outputFile, "##TAC_IF \n"
                                    "\tjle	_%s\n\n",
                        itTac->res->text);

            else if (itTac->prev->type == TAC_GE)
                fprintf(outputFile, "##TAC_IF \n"
                                    "\tjl	_%s\n\n",
                        itTac->res->text);

            else if (itTac->prev->type == TAC_LE)
                fprintf(outputFile, "##TAC_IF \n"
                                    "\tjg	_%s\n\n",
                        itTac->res->text);

            else if (itTac->prev->type == TAC_DIF)
                fprintf(outputFile, "##TAC_IF \n"
                                    "\tje	_%s\n\n",
                        itTac->res->text);

            else if (itTac->prev->type == TAC_OR)
            {
                fprintf(outputFile, "##TAC_OR \n");
                if (itTac->prev->op1->dataType == DATATYPE_CHAR && itTac->prev->op1->text[0] == '\'')
                    fprintf(outputFile, "\tmovl	_char%c(%%rip), %%eax\n", itTac->prev->op1->text[1]);
                else
                    fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->prev->op1->text);
                fprintf(outputFile, "\ttestl	%%eax, %%eax\n");
                fprintf(outputFile, "\tjne	_orLabel%d\n", auxLabel);
                if (itTac->prev->op2->dataType == DATATYPE_CHAR && itTac->prev->op2->text[0] == '\'')
                    fprintf(outputFile, "\tmovl	_char%c(%%rip), %%eax\n", itTac->prev->op2->text[1]);
                else
                    fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->prev->op2->text);
                fprintf(outputFile, "\ttestl	%%eax, %%eax\n");
                fprintf(outputFile, "##TAC_IF \n");
                fprintf(outputFile, "\tje	_%s\n", itTac->res->text);
                fprintf(outputFile, "_orLabel%d\n\n", auxLabel);
                auxLabel++;
            }
            else if (itTac->prev->type == TAC_AND)
            {
                fprintf(outputFile, "##TAC_AND \n");
                if (itTac->prev->op1->dataType == DATATYPE_CHAR && itTac->prev->op1->text[0] == '\'')
                    fprintf(outputFile, "\tmovl	_char%c(%%rip), %%eax\n", itTac->prev->op1->text[1]);
                else
                    fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->prev->op1->text);
                fprintf(outputFile, "\ttestl	%%eax, %%eax\n");
                fprintf(outputFile, "\tje	_%s\n\n", itTac->res->text);
                if (itTac->prev->op2->dataType == DATATYPE_CHAR && itTac->prev->op2->text[0] == '\'')
                    fprintf(outputFile, "\tmovl	_char%c(%%rip), %%eax\n", itTac->prev->op2->text[1]);
                else
                    fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax\n", itTac->prev->op2->text);
                fprintf(outputFile, "\ttestl	%%eax, %%eax\n");
                fprintf(outputFile, "##TAC_IF \n");
                fprintf(outputFile, "\tje	_%s\n\n", itTac->res->text);
            }
            break;

        case TAC_JUMP:
            fprintf(outputFile, "##TAC_JUMP \n");
            fprintf(outputFile, "\tjmp  _%s\n\n", itTac->res->text);
            break;

        case TAC_FOOCALL:
            //            fprintf(outputFile, "##TAC_FOOCALL\n");
            //            fprintf(outputFile, "\tcall	%s\n", itTac->op1->text);
            //            fprintf(outputFile, "\tmovl	%%eax, _%s(%%rip)\n", itTac->res->text);
            //        	call	jorge
            //	movl	%eax, b(%rip)
            break;

        case TAC_ARG:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_RETURN:
            fprintf(outputFile, "##TAC_RETURN \n");
            fprintf(outputFile, "\tmovl	_%s(%%rip), %%eax \n\n", itTac->res->text);
            break;

        case TAC_VECCALL:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_INPUT:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_PARAM:
            fprintf(outputFile, "##Assembly code \n\n");
            break;

        case TAC_VARDEC:
            fprintf(outputFile, "##TAC_VARDEC\n");
            if (itTac->op1->dataType == DATATYPE_CHAR && itTac->op1->text[0] == '\'')
                fprintf(outputFile, "\tmovl	_char%c(%%rip), ", itTac->op1->text[1]);
            else if (itTac->op1->dataType == DATATYPE_FLOAT)
                fprintf(outputFile, "\tmovl	_%d(%%rip), ", (int)strtof(itTac->op1->text, NULL));
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

    return;
}