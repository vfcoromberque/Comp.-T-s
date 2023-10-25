// AST - Abstract Syntax Tree

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2,
               AST *s3) {
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

void astPrint(AST *node, int level) {
  if (node == 0) {
    return;
  }

  for (int i = 0; i < level; ++i) {
    fprintf(stderr, "   ");
  }

  fprintf(stderr, "ast(");
  switch (node->type) {
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
  case AST_AND:
    fprintf(stderr, "AST_AND");
    break;
  case AST_OR:
    fprintf(stderr, "AST_OR");
    break;
  case AST_NOT:
    fprintf(stderr, "AST_NOT");
    break;
  case AST_LT:
    fprintf(stderr, "AST_LT");
    break;
  case AST_GT:
    fprintf(stderr, "AST_GT");
    break;
  case AST_EQ:
    fprintf(stderr, "AST_EQ");
    break;
  case AST_OP_LE:
    fprintf(stderr, "AST_OP_LE");
    break;
  case AST_OP_GE:
    fprintf(stderr, "AST_OP_GE");
    break;
  case AST_OP_EQ:
    fprintf(stderr, "AST_OP_EQ");
    break;
  case AST_OP_DIF:
    fprintf(stderr, "AST_OP_DIF");
    break;
  case AST_KW_ENTR:
    fprintf(stderr, "AST_KW_ENTR");
    break;
  case AST_ENCLOSING:
    fprintf(stderr, "AST_ENCLOSING");
    break;
  case AST_BODY:
    fprintf(stderr, "AST_BODY");
    break;
  case AST_KW_ENTAUM:
    fprintf(stderr, "AST_KW_ENTAUM");
    break;
  case AST_KW_SENAUM:
    fprintf(stderr, "AST_KW_SENAUM");
    break;
  case AST_KW_SE:
    fprintf(stderr, "AST_KW_SE");
    break;
  case AST_KW_ESCREVA:
    fprintf(stderr, "AST_KW_ESCREVA");
    break;
  case AST_KW_ENQUANTO:
    fprintf(stderr, "AST_KW_ENQUANTO");
    break;
  case AST_FUNCT:
    fprintf(stderr, "AST_FUNCT");
    break;
  case AST_KW_CARA:
    fprintf(stderr, "AST_KW_CARA");
    break;
  case AST_KW_INTE:
    fprintf(stderr, "AST_KW_INTE");
    break;
  case AST_KW_REAL:
    fprintf(stderr, "AST_KW_REAL");
    break;
  case AST_PARAM:
    fprintf(stderr, "AST_PARAM");
    break;
  case AST_KW_RETORNE:
    fprintf(stderr, "AST_KW_RETORNE");
    break;
  case AST_DECLARE:
    fprintf(stderr, "AST_DECLARE");
    break;
  case AST_VECT:
    fprintf(stderr, "AST_VECT");
    break;
  case AST_DEC_LIST:
    fprintf(stderr, "AST_DEC_LIST");
    break;
  default:
    fprintf(stderr, "AST_UNKNOWN");
    break;
  }

  if (node->symbol != 0) {
    fprintf(stderr, ",%s)\n", node->symbol->text);
  } else {
    fprintf(stderr, ",0)\n");
  }

  for (int i = 0; i < MAX_SONS; ++i) {
    astPrint(node->son[i], level + 1);
  }
  for (int i = 0; i < level; ++i) {
    fprintf(stderr, "   ");
  }
}
