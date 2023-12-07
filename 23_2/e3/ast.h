// AST - Abstract Syntax Tree
// Author: Vinicius Fraga Coromberque - 00302369
// 06/12/2023

#include <stdlib.h>
#include "hash.h"

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 5
#define AST_DIV 6
#define AST_LSS 7
#define AST_GTR 8
#define AST_LE 9
#define AST_GE 10
#define AST_EQ 11
#define AST_DIF 12
#define AST_AND 13
#define AST_OR 14
#define AST_NOT 15
#define AST_DECLARATION 16
#define AST_FCALL 17
#define AST_VECCALL 18
#define AST_INPUT 19
#define AST_ATR 20
#define AST_ARG 21
#define AST_PRINT 22
#define AST_RETURN 23
#define AST_IF 24
#define AST_WHILE 25
#define AST_ELSE 26
#define AST_CODE 27
#define AST_CODELIST 28
#define AST_CMD 29

typedef struct astnode
{
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3);
void astPrint(AST *node, int level);

#endif

// END OF FILE