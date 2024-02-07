// ASM
// Author: Vinicius Fraga Coromberque - 00302369
// 05/02/2023

#include "asm.h"

void asmBinOps(tac *itTac, FILE *outputFile)
{
    switch (itTac->type)
    {
    case TAC_ADD:
        fprintf(outputFile, "\tmov	w8, #%s\n\tadd	w8, w8, #%s\n\tstr	w8, [sp, #12]\n", itTac->op1->text, itTac->op2->text);
        break;
    case TAC_SUB:
        fprintf(outputFile, "\tmov	w8, #%s\n\tstr	w8, [sp, #12]\n\tldr	w8, [sp, #12]\n\tsubs	w8, w8, #%s\n\tstr	w8, [sp, #12]\n", itTac->op1->text, itTac->op2->text);
        break;
    case TAC_MUL:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_DIV:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;

    default:
        break;
    }

    return;
}

void asmLogicOps(tac *itTac, FILE *outputFile)
{
    switch (itTac->type)
    {
    case TAC_EQ:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_NOT:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_GTR:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_LSS:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_LE:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_GE:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_DIF:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_OR:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;
    case TAC_AND:
        fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
        break;

    default:
        break;
    }
}

void asmGenerate(tac *firstTac, AST *ast)
{

    FILE *outputFile = fopen("asm.s", "w");

    fprintf(outputFile, "\t.globl	_%s\n\t.p2align\t2\n", firstTac->res->text);

    fprintf(outputFile, "\t_%s:\n", firstTac->res->text);
    // addLiteral(outputFile);

    tac *itTac = firstTac;
    for (itTac = firstTac; itTac; itTac = itTac->next)
    {
        switch (itTac->type)
        {
        case TAC_MOVE:
            fprintf(outputFile, "//Assembly code \n");
            break;
        case TAC_MOVEVEC:
            fprintf(outputFile, "//Assembly code \n");
            break;
        case TAC_PRINT:
            fprintf(outputFile, "//Assembly code \n");
            break;
        case TAC_ADD:
        case TAC_SUB:
        case TAC_MUL:
        case TAC_DIV:
            asmBinOps(itTac, outputFile);
            break;
        case TAC_EQ:
        case TAC_NOT:
        case TAC_GTR:
        case TAC_LSS:
        case TAC_LE:
        case TAC_GE:
        case TAC_DIF:
        case TAC_OR:
        case TAC_AND:
            asmLogicOps(itTac, outputFile);
            break;
        case TAC_LABEL:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;

        case TAC_FOOSTART:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;

        case TAC_FOOEND:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;

            /*****************************************/
        case TAC_IFS:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;

        case TAC_JUMP:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;

        case TAC_FOOCALL:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;

            /*****************************************/
        case TAC_ARG:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;
        case TAC_RETURN:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;

            /*****************************************/
        case TAC_VECCALL:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;
        case TAC_VECVAR:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;
        case TAC_VECINIT:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;
        case TAC_INPUT:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;
        case TAC_PARAM:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;
        case TAC_LIST:
            fprintf(outputFile, "//Assembly code \n"); //, itTac->op1->text,itTac->op2->text,itTac->res->text);
            break;

        default:
            break;
        }
    }

    return;
}