// TAC
// Author: Vinicius Fraga Coromberque - 00302369
// 28/01/2024

#include "tac.h"
#include "hash.h"
#include "stdlib.h"

tac *newTac(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2)
{
    tac *n = (tac *)calloc(1, sizeof(tac));
    n->type = type;
    n->res = res;
    n->op1 = op1;
    n->op2 = op2;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

tac *tacJoin(tac *l1, tac *l2)
{
    tac *tacJoined;
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    tacJoined = l2;
    while (tacJoined->prev)
    {
        tacJoined = tacJoined->prev;
    }
    tacJoined->prev = l1;
    return l2;
}

void printAllTacs(tac *l)
{
    tac *tac;
    for (tac = l; tac; tac = tac->next)
        printTac(tac);
}

tac *rewindTac(tac *l)
{
    tac *tac;
    for (tac = l; tac->prev; tac = tac->prev)
        tac->prev->next = tac;
    return tac;
}

void printTac(tac *l)
{

    if (l->type == TAC_SYMBOL)
        return;

    fprintf(stderr, "TAC(");
    switch (l->type)
    {
    case TAC_SYMBOL:
        fprintf(stderr, "SYMBOL(");
        break;
    case TAC_ADD:
        fprintf(stderr, "ADD(");
        break;
    case TAC_SUB:
        fprintf(stderr, "SUB(");
        break;
    case TAC_MUL:
        fprintf(stderr, "MUL(");
        break;
    case TAC_DIV:
        fprintf(stderr, "DIV(");
        break;
    case TAC_GTR:
        fprintf(stderr, "GTR(");
        break;
    case TAC_LSS:
        fprintf(stderr, "LSS(");
        break;
    case TAC_GE:
        fprintf(stderr, "GE(");
        break;
    case TAC_LE:
        fprintf(stderr, "LE(");
        break;
    case TAC_EQ:
        fprintf(stderr, "EQ(");
        break;
    case TAC_DIF:
        fprintf(stderr, "DIF(");
        break;
    case TAC_AND:
        fprintf(stderr, "AND(");
        break;
    case TAC_OR:
        fprintf(stderr, "OR(");
        break;
    case TAC_NOT:
        fprintf(stderr, "NOT(");
        break;
    case TAC_MOVE:
        fprintf(stderr, "MOVE(");
        break;
    case TAC_MOVEVEC:
        fprintf(stderr, "MOVEVEC(");
        break;
    case TAC_LABEL:
        fprintf(stderr, "LABEL(");
        break;
    case TAC_FOOSTART:
        fprintf(stderr, "FOOSTART(");
        break;
    case TAC_FOOEND:
        fprintf(stderr, "FOOEND(");
        break;
    case TAC_IF:
        fprintf(stderr, "IF(");
        break;
    case TAC_JUMP:
        fprintf(stderr, "JUMP(");
        break;
    case TAC_FOOCALL:
        fprintf(stderr, "FOOCALL(");
        break;
    case TAC_ARG:
        fprintf(stderr, "ARG(");
        break;
    case TAC_RETURN:
        fprintf(stderr, "RETURN(");
        break;
    case TAC_VECCALL:
        fprintf(stderr, "VECCALL(");
        break;
    case TAC_VECVAR:
        fprintf(stderr, "VECVAR(");
        break;
    case TAC_VECINIT:
        fprintf(stderr, "VECINIT(");
        break;
    case TAC_INPUT:
        fprintf(stderr, "INPUT(");
        break;
    case TAC_PARAM:
        fprintf(stderr, "PARAM(");
        break;
    case TAC_LIST:
        fprintf(stderr, "LIST(");
        break;
    case TAC_PRINT:
        fprintf(stderr, "PRINT(");
        break;
    case TAC_FOODEC:
        fprintf(stderr, "FOODEC(");
        break;
    case TAC_VARDEC:
        fprintf(stderr, "VARDEC(");
        break;

    default:
        fprintf(stderr, "UNKNOWN TAC TYPE(");
        break;
    }

    if (l->res)
        fprintf(stderr, "%s, ", l->res->text);
    else
        fprintf(stderr, "0, ");

    if (l->op1)
        fprintf(stderr, "%s, ", l->op1->text);
    else
        fprintf(stderr, "0, ");

    if (l->op2)
        fprintf(stderr, "%s", l->op2->text);
    else
        fprintf(stderr, "0");

    fprintf(stderr, "))\n");
}

tac *createTacs(AST *node, HASH_NODE *currentLoopLabel)
{
    if (!node)
        return NULL;

    tac *sons[MAX_SONS];
    if (node->type == AST_WHILE)
    {
        currentLoopLabel = makeLabel();
    }
    for (int i = 0; i < MAX_SONS; i++)
        sons[i] = createTacs(node->son[i], currentLoopLabel);

    switch (node->type)
    {
    case AST_SYMBOL:
        return newTac(TAC_SYMBOL, node->symbol, 0, 0);
    case AST_IDDEC:
        return tacJoin(sons[0], newTac(TAC_VARDEC, node->son[1]->symbol, sons[2] ? sons[2]->res : 0, 0));

    case AST_ADD:
        return createBinop(TAC_ADD, sons);
    case AST_SUB:
        return createBinop(TAC_SUB, sons);
    case AST_MUL:
        return createBinop(TAC_MUL, sons);
    case AST_DIV:
        return createBinop(TAC_DIV, sons);

    case AST_GTR:
        return createBinop(TAC_GTR, sons);
    case AST_LSS:
        return createBinop(TAC_LSS, sons);
    case AST_EQ:
        return createBinop(TAC_EQ, sons);
    case AST_GE:
        return createBinop(TAC_GE, sons);
    case AST_LE:
        return createBinop(TAC_LE, sons);
    case AST_DIF:
        return createBinop(TAC_DIF, sons);

    case AST_AND:
        return createBinop(TAC_AND, sons);
    case AST_OR:
        return createBinop(TAC_OR, sons);
    case AST_NOT:
        return createBinop(TAC_NOT, sons);
    case AST_ATTR:
        return tacJoin(tacJoin(sons[0], newTac(TAC_MOVE, node->son[0]->symbol, sons[1] ? sons[1]->res : 0, 0)), sons[1]);
    case AST_VECATTR:
        return tacJoin(sons[0], tacJoin(sons[1], newTac(TAC_MOVEVEC, node->son[0]->son[0]->symbol, node->son[0]->son[1]->symbol, sons[1] ? sons[1]->res : 0)));
    case AST_INPUT:
        return tacJoin(sons[0], newTac(TAC_INPUT, sons[1] ? sons[1]->res : 0, 0, 0));
    case AST_PRINT:
        return tacJoin(sons[0], newTac(TAC_PRINT, sons[0] ? sons[0]->res : 0, 0, 0));
    case AST_RETURN:
        return tacJoin(sons[0], newTac(TAC_RETURN, sons[0] ? sons[0]->res : 0, 0, 0));
    case AST_IFELSE:
        return createIf(sons);
    case AST_IF:
        return createIf(sons);
    case AST_WHILE:
        return createLoop(sons, currentLoopLabel);

    case AST_FOODEC:
        return tacJoin(sons[1], tacJoin(newTac(TAC_FOODEC, node->son[1]->symbol, 0, 0), sons[2]));
    case AST_FOOCALL:
        return tacJoin(tacJoin(sons[0], newTac(TAC_FOOCALL, makeTemp(), node->son[0]->symbol, 0)), sons[1]);
    case AST_ARG:
        return tacJoin(newTac(TAC_ARG, sons[0] ? sons[0]->res : 0, 0, 0), sons[1]);
    case AST_VECCALL:
        return tacJoin(sons[0], newTac(TAC_VECCALL, node->son[0]->symbol, sons[1] ? sons[1]->res : 0, 0));
    case AST_VECDEC:
        return tacJoin(sons[0], newTac(TAC_MOVEVEC, node->son[1]->symbol, sons[2] ? sons[2]->res : 0, sons[3] ? makeTemp() : 0));

    case AST_CODE:
        return createFunction(newTac(TAC_SYMBOL, node->son[0]->symbol, 0, 0), sons[1], sons[2]);
    case AST_PARAM:
        return tacJoin(newTac(TAC_PARAM, node->son[1]->symbol, 0, 0), sons[2]);

    default:
        return tacJoin(tacJoin(tacJoin(sons[0], sons[1]), sons[2]), sons[3]);
    }
}

tac *createBinop(int type, tac *sons[])
{
    HASH_NODE *op1;
    HASH_NODE *op2;
    if (sons[0])
        op1 = sons[0]->res;
    else
        op1 = 0;
    if (sons[1])
        op2 = sons[1]->res;
    else
        op2 = 0;
    return tacJoin(sons[0], tacJoin(sons[1], newTac(type, makeTemp(), op1, op2)));
}

tac *createIf(tac *sons[])
{
    HASH_NODE *ifLabel = makeLabel();
    tac *ifTac = tacJoin(sons[0], newTac(TAC_IF, ifLabel, sons[0] ? sons[0]->res : 0, 0));
    tac *ifLabelTac = newTac(TAC_LABEL, ifLabel, 0, 0);

    if (sons[2])
    {
        HASH_NODE *elseLabel = makeLabel();
        tac *elseLabelTac = newTac(TAC_LABEL, elseLabel, 0, 0);
        tac *elseJumpTac = newTac(TAC_JUMP, elseLabel, 0, 0);
        tac *ifElseTac = tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(ifTac, sons[1]), elseJumpTac), ifLabelTac), sons[2]), elseLabelTac);
        return ifElseTac;
    }
    else
    {
        return tacJoin(tacJoin(ifTac, sons[1]), ifLabelTac);
    }
}

tac *createLoop(tac *sons[], HASH_NODE *whileLabel)
{
    HASH_NODE *jumpLabel = makeLabel();

    tac *whileTac = newTac(TAC_IF, jumpLabel, sons[0] ? sons[0]->res : 0, 0);
    tac *whileLabelTac = newTac(TAC_LABEL, whileLabel, 0, 0);
    tac *jumpTac = newTac(TAC_JUMP, whileLabel, 0, 0);
    tac *jumpLabelTac = newTac(TAC_LABEL, jumpLabel, 0, 0);

    return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(whileLabelTac, sons[0]), whileTac), sons[1]), jumpTac), jumpLabelTac);
}

tac *createFunction(tac *symbol, tac *code, tac *rest)
{
    return tacJoin(tacJoin(tacJoin(newTac(TAC_FOOSTART, symbol->res, 0, 0), code), newTac(TAC_FOOEND, symbol->res, 0, 0)), rest);
}