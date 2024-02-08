// Code created from recorded classes

#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>

#define HASH_SIZE 997

#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_FLOAT 2
#define SYMBOL_LIT_CHAR 3
#define SYMBOL_LIT_STRING 4
#define SYMBOL_ID 5

#define SYMBOL_VAR 10
#define SYMBOL_VECTOR 11
#define SYMBOL_FUNC 12
#define SYMBOL_PARAM 13

#define DATATYPE_CHAR 14
#define DATATYPE_INT 15
#define DATATYPE_FLOAT 16
#define DATATYPE_BOOL 17

typedef struct hash_node
{
    int type;
    char *text;
    int dataType;
    struct hash_node *next;
    int strCode;
} HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text, int type, int datatype);
void hashPrint(void);

int hashCheckUndeclared();
HASH_NODE *makeTemp();
HASH_NODE *makeLabel();
char *makeStrCode();

#endif
