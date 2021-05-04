#include "Node.h"

struct LINKEDLIST{
    Node head;
    int size;
    void (*add)(Node, Node);
    Node (*get)(int, Node);
    void (*clear)(struct LINKEDLIST*);
    void (*delete)(struct LINKEDLIST*);
};

typedef struct LINKEDLIST* LinkedList;

LinkedList newLinkedList();
void AddLinkedList(Node, Node);
Node GetNode(int, Node);
void ClearLinkedList(LinkedList);
void DeleteLinkedList(LinkedList);