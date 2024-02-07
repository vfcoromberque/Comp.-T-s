// Semantic
// Author: Vinicius Fraga Coromberque - 00302369
// 16/01/2024

#include "ast.h"
#include <string.h>
#include <stdbool.h>

int verifySemantic(AST *root);
void setIDTypes(AST *node);
void setNodeTypes(AST *node);

void checkDeclaration();
void checkUsage(AST *node);
bool checkElementVector(AST *node, int dataType);

int isDataTypeCompatible(int datatype0, int datatype1);
int isInteger(int datatype);
int isNumerical(int datatype);
int isRelationalOp(int nodetype);
int isAritmeticOp(int nodetype);
int isLogicalOp(int nodetype);

int greaterDatatype(int type1, int type2);

void validateFunction(AST *node);

AST *findFunctionDeclaration(char *name, AST *node);

bool checkNumberOfArguments(AST *node, AST *declaration);
int getNumberOfArguments(AST *node);
void compareCalledArguments(AST *node, AST *declaration);