#include "Node.h"

Node newNode(){
    Node this = malloc(sizeof(struct NODE));
    this->next = NULL;
    this->delete= &DeleteNode;
    return this;
}

void DeleteNode(Node this){
    free(this->code);
    free(this->key);
    free(this->value);
    free(this);
}