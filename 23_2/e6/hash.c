// Code created from recorded classes

#include "hash.h"
#include <string.h>
#include <stdlib.h>

HASH_NODE *Table[HASH_SIZE];

void hashInit(void)
{
    int i;
    for (i = 0; i < HASH_SIZE; ++i)
        Table[i] = 0;
}

int hashAddress(char *text)
{
    int address = 1;
    int i;
    for (i = 0; i < strlen(text); ++i)
        address = (address * text[i]) % HASH_SIZE + 1;
    return address - 1;
}

HASH_NODE *hashFind(char *text)
{
    HASH_NODE *node;
    int address = hashAddress(text);
    for (node = Table[address]; node; node = node->next)
        if (strcmp(node->text, text) == 0)
            return node;
    return 0;
}

HASH_NODE *hashInsert(char *text, int type, int datatype)
{
    static int i = 0;

    HASH_NODE *newnode;
    int address = hashAddress(text);

    if ((newnode = hashFind(text)) != 0)
        return newnode;

    newnode = (HASH_NODE *)calloc(1, sizeof(HASH_NODE));
    newnode->type = type;

    switch (newnode->type)
    {
    case SYMBOL_LIT_CHAR:
        newnode->dataType = DATATYPE_CHAR;
        break;
    case SYMBOL_LIT_INT:
        newnode->dataType = DATATYPE_INT;
        break;
    case SYMBOL_LIT_FLOAT:
        newnode->dataType = DATATYPE_FLOAT;
        break;
    case SYMBOL_LIT_STRING:
        newnode->strCode = i;
        i++;
    default:
        break;
    }

    newnode->text = (char *)calloc(strlen(text) + 1, sizeof(char));
    strcpy(newnode->text, text);
    newnode->next = Table[address];
    Table[address] = newnode;
    return newnode;
}

void hashPrint(void)
{
    int i;
    HASH_NODE *node;
    for (i = 0; i < HASH_SIZE; ++i)
        for (node = Table[i]; node; node = node->next)
            printf("Table[%d] has %s code %d\n", i, node->text, node->strCode);
}

int hashCheckUndeclared()
{
    HASH_NODE *node;
    int undecVars = 0;
    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (Table[i] != NULL)
        {
            for (node = Table[i]; node != NULL; node = node->next)
            {
                if (node->type == SYMBOL_ID)
                {
                    fprintf(stderr, "SEMANTIC ERROR - Variable %s not declared.\n", node->text);
                    undecVars++;
                }
            }
        }
    }
    return undecVars;
}

HASH_NODE *makeTemp()
{
    static int serialNumber = 0;
    static char buffer[128];
    sprintf(buffer, "_temp%d", serialNumber++);
    return hashInsert(buffer, SYMBOL_ID, 0);
}

HASH_NODE *makeLabel()
{
    static int serialNumber = 0;
    static char buffer[128];
    sprintf(buffer, "_label%d", serialNumber++);
    return hashInsert(buffer, SYMBOL_ID, 0);
}