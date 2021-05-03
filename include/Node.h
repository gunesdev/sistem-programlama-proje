#include <stdio.h>
#include <stdlib.h>

struct NODE{
    char *key;
    char *value;
    struct NODE *next;
    void (*delete)(struct NODE*);
};

typedef struct NODE* Node;
Node newNode();
void DeleteNode(Node);