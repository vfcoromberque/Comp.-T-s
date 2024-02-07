// ASM
// Author: Vinicius Fraga Coromberque - 00302369
// 05/02/2023

#ifndef ASM_HEADER
#define ASM_HEADER

#include "tac.h"
#include "ast.h"

void addLiteral(FILE *outputFile);

void addData(FILE *outputFile, AST *node);

void asmBinOps(tac *itTac, FILE *outputFile);
void asmLogicOps(tac *itTac, FILE *outputFile);

void asmGenerate(tac *firstTac, AST *ast);

#endif