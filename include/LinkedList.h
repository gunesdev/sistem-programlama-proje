#include "Node.h"

struct LINKEDLIST{
    Node head;
    int size;
    void (*delete)(struct LINKEDLIST*);
};

typedef struct LINKEDLIST* LinkedList;

LinkedList newLinkedList();
void DeleteLinkedList(LinkedList);