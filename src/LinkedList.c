#include "LinkedList.h"

LinkedList newLinkedList(){
    LinkedList this = malloc(sizeof(struct LINKEDLIST));
    this->head = newNode();
    this->size = 0;
    this->delete = &DeleteLinkedList;
    return this;
}

void DeleteLinkedList(LinkedList this){
    free(this);
}