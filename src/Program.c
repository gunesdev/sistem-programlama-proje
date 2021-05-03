#include "LinkedList.h"

int main(){
    LinkedList list= newLinkedList();
    Node node = newNode();
    node->key = "merhaba";
    node->value = "10";
    list->head->next = node;
    printf("%s: %s", list->head->next->key, list->head->next->value);
    node->delete(node);
    list->delete(list);
}