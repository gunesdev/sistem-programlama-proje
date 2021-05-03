#include "Json.h"

int main(){
    Json json = newJson();
    char *str = json->readJsonIntoString("./.kilit");
    printf("%s", str);
    json->delete(json);
    free(str);
}