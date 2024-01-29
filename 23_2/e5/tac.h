// TAC
// Author: Vinicius Fraga Coromberque - 00302369
// 28/01/2024

#ifndef TAC_HEADER
#define TAC_HEADER

#include "ast.h"

#define TAC_SYMBOL 0

#define TAC_ADD 1
#define TAC_SUB 2
#define TAC_MUL 3
#define TAC_DIV 4

#define TAC_GTR 5
#define TAC_LSS 6
#define TAC_GE 7
#define TAC_LE 8
#define TAC_EQ 9
#define TAC_DIF 10

#define TAC_AND 11
#define TAC_OR 12
#define TAC_NOT 13

#define TAC_MOVE 14
#define TAC_MOVEVEC 15

#define TAC_LABEL 16

#define TAC_FOOSTART 17
#define TAC_FOOEND 18

#define TAC_IFS 19
#define TAC_JUMP 20
#define TAC_CALL 21

#define TAC_ARG 22
#define TAC_RETURN 23

#define TAC_VECREAD 24
#define TAC_VECVAR 25
#define TAC_VECINIT 26
#define TAC_INPUT 27
#define TAC_PARAM 28
#define TAC_LIST 29

#define TAC_PRINT 30

#define TAC_IFELSE 31
#define TAC_IF 32

typedef struct tac
{
    int type;
    HASH_NODE *res;
    HASH_NODE *op1;
    HASH_NODE *op2;
    struct tac *prev;
    struct tac *next;
} tac;

tac *newTac(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2);
tac *tacJoin(tac *l1, tac *l2);
void printAllTacs(tac *l);
tac *rewindTac(tac *l);
void printTac(tac *l);

tac *createTacs(AST *node, HASH_NODE *currentLoopLabel);

tac *createBinop(int type, tac *sons[]);
tac *createIf(tac *sons[]);
tac *createLoop(tac *sons[], HASH_NODE *label);

tac *createFunction(tac *symbol, tac *params, tac *code);

#endif