// AST - Abstract Syntax Tree

#ifndef AST_HEADER
#include "hash.h"
#define AST_HEADER

#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5
#define AST_AND 6
#define AST_OR 7
#define AST_NOT 8
#define AST_LT 9
#define AST_GT 10
#define AST_EQ 11
#define AST_OP_LE 12
#define AST_OP_GE 13
#define AST_OP_EQ 14
#define AST_OP_DIF 15
#define AST_KW_ENTR 16
#define AST_ENCLOSING 17
#define AST_BODY 18
#define AST_KW_ENTAUM 19
#define AST_KW_SENAUM 20
#define AST_KW_SE 21
#define AST_KW_ESCREVA 22
#define AST_KW_ENQUANTO 23
#define AST_FUNCT 24
#define AST_KW_CARA 25
#define AST_KW_INTE 26
#define AST_KW_REAL 27
#define AST_PARAM 28
#define AST_KW_RETORNE 29
#define AST_DECLARE 30
#define AST_VECT 31
#define AST_DEC_LIST 32

typedef struct astnode {

  int type;
  HASH_NODE *symbol;
  struct astnode *son[MAX_SONS];

} AST;

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3);
void astPrint(AST *node, int level);

#endif