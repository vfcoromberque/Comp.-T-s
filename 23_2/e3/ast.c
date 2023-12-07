// AST - Abstract Syntax Tree
// Author: Vinicius Fraga Coromberque - 00302369
// 06/12/2023

#include "ast.h"

AST *astCreate(int type, HASH_NODE *symbol,
               AST *s0, AST *s1, AST *s2, AST *s3)
{
    AST *newnode;
    newnode = (AST *)calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->symbol = symbol;
    newnode->son[0] = s0;
    newnode->son[1] = s1;
    newnode->son[2] = s2;
    newnode->son[3] = s3;
    return newnode;
}

void astPrint(AST *node, int level)
{
    if (node == 0)
        return;

    for (int i = 0; i < level; i++)
    {
        fprintf(stderr, "  ");
    }

    switch (node->type)
    {
    case AST_SYMBOL:
        fprintf(stderr, "AST_SYMBOL");
        break;
    case AST_ADD:
        fprintf(stderr, "AST_ADD");
        break;
    case AST_SUB:
        fprintf(stderr, "AST_SUB");
        break;
    case AST_MUL:
        fprintf(stderr, "AST_MUL");
        break;
    case AST_DIV:
        fprintf(stderr, "AST_DIV");
        break;
    case AST_LSS:
        fprintf(stderr, "AST_LSS");
        break;
    case AST_GTR:
        fprintf(stderr, "AST_GTR");
        break;
    case AST_LE:
        fprintf(stderr, "AST_LE");
        break;
    case AST_GE:
        fprintf(stderr, "AST_GE");
        break;
    case AST_EQ:
        fprintf(stderr, "AST_EQ");
        break;
    case AST_DIF:
        fprintf(stderr, "AST_DIF");
        break;
    case AST_AND:
        fprintf(stderr, "AST_AND");
        break;
    case AST_OR:
        fprintf(stderr, "AST_OR");
        break;
    case AST_NOT:
        fprintf(stderr, "AST_NOT");
        break;
    case AST_DECLARATION:
        fprintf(stderr, "AST_DECLARATION");
        break;
    case AST_FOOCALL:
        fprintf(stderr, "AST_FOOCALL");
        break;
    case AST_VECCALL:
        fprintf(stderr, "AST_VECCALL");
        break;
    case AST_INPUT:
        fprintf(stderr, "AST_INPUT");
        break;
    case AST_ATR:
        fprintf(stderr, "AST_ATR");
        break;
    case AST_ARG:
        fprintf(stderr, "AST_ARG");
        break;
    case AST_PRINT:
        fprintf(stderr, "AST_PRINT");
        break;
    case AST_RETURN:
        fprintf(stderr, "AST_RETURN");
        break;
    case AST_IF:
        fprintf(stderr, "AST_IF");
        break;
    case AST_WHILE:
        fprintf(stderr, "AST_WHILE");
        break;
    case AST_ELSE:
        fprintf(stderr, "AST_ELSE");
        break;
    case AST_CODE:
        fprintf(stderr, "AST_CODE");
        break;
    case AST_CODELIST:
        fprintf(stderr, "AST_CODELIST");
        break;
    case AST_CMD:
        fprintf(stderr, "AST_CMD");
        break;
    case AST_IDENTIFIER:
        fprintf(stderr, "AST_IDENTIFIER");
        break;
    case AST_DEC:
        fprintf(stderr, "AST_DEC");
        break;
    case AST_IDDEC:
        fprintf(stderr, "AST_IDDEC");
        break;
    case AST_VECDEC:
        fprintf(stderr, "AST_VECDEC");
        break;
    case AST_FOODEC:
        fprintf(stderr, "AST_FOODEC");
        break;
    case AST_PARAM:
        fprintf(stderr, "AST_PARAM");
        break;
    case AST_VECVAL:
        fprintf(stderr, "AST_VECVAL");
        break;
    case AST_KWCHAR:
        fprintf(stderr, "AST_KWCHAR");
        break;
    case AST_KWINT:
        fprintf(stderr, "AST_KWINT");
        break;
    case AST_KWFLOAT:
        fprintf(stderr, "AST_KWFLOAT");
        break;
    default:
        fprintf(stderr, "AST_UNKNOWN");
        break;
    }

    if (node->symbol != 0)
        fprintf(stderr, ",%s\n", node->symbol->text);
    else
        fprintf(stderr, "\n");
    for (int i = 0; i < MAX_SONS; ++i)
    {
        astPrint(node->son[i], level + 1);
    }
}

// END OF FILE