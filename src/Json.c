#include "Json.h"

Json newJson() {
    Json this = malloc(sizeof(struct JSON));
    this->readJsonIntoString = &ReadJsonIntoString;
    this->delete = &DeleteJson;
    return this;
}

char* ReadJsonIntoString(char* path){
    FILE *file = fopen(path, "r");
    char *json;
    int n = 0;
    int c;
    if (file == NULL){
        printf("File not found!");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    json = malloc(f_size);
    while ((c = fgetc(file)) != EOF) {
        json[n++] = (char)c;
    }
    json[n] = '\0';
    return json;
}

void DeleteJson(Json this){
    free(this);
}