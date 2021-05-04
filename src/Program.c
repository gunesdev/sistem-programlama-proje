#include "Json.h"

int main(){
    Json json = newJson();
    char *str = json->readJsonIntoString("./.kilit");
    LinkedList list = json->parseJsonIntoList(str);
    json->delete(json);
    free(str);
    list->delete(list);
}