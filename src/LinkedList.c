#include "LinkedList.h"

LinkedList newLinkedList(){
    LinkedList this = malloc(sizeof(struct LINKEDLIST));
    this->head = newNode();
    this->size = 0;
    this->add = &AddLinkedList;
    this->get = &GetNode;
    this->clear = &ClearLinkedList;
    this->delete = &DeleteLinkedList;
    return this;
}

void AddLinkedList(Node node, Node head){
    Node iterator = head;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    iterator->next = node;
}

Node GetNode(int index, Node head){
    Node iterator = head->next;
    int i;
    for(i = 0; i < index; i++){
        iterator = iterator->next;
    }
    return iterator;
}

void ClearLinkedList(LinkedList this){
    while(this->head->next != NULL){
        Node iterator = this->head->next;
        this->head->next = iterator->next;
        iterator->delete(iterator);
        this->size--;
    }
}

void DeleteLinkedList(LinkedList this){
    this->clear(this);
    free(this);
}