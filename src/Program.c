#include "Json.h"

int main(){
    Json json = newJson();
    char *str = json->readJsonIntoString("./.kilit");
    LinkedList list = json->parseJsonIntoList(str);
    json->delete(json);
    free(str);
    int i;
    for(i = 0; i < list->size; i++){
        printf("%s: %s\n", list->get(i, list->head)->key, list->get(i, list->head)->value);
    }
    list->delete(list);
}