#include "Json.h"

Json newJson() {
    Json this = malloc(sizeof(struct JSON));
    this->readJsonIntoString = &ReadJsonIntoString;
    this->parseJsonIntoList = &ParseJsonIntoList;
    this->findNumberOfKeyValues = &FindNumberOfKeyValues;
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

LinkedList ParseJsonIntoList(char *json){
    int numberOfKeyValues = FindNumberOfKeyValues(json);
    LinkedList list = newLinkedList();
    int numberOfCharacterInJson = strlen(json);
    char str[numberOfCharacterInJson];
    int i;
    memset(str, 0, numberOfCharacterInJson);
    int listIterator = 0;
    int numberOfDittoMarks = 0;
    int j = 0;
    for(i = 0; i < numberOfCharacterInJson; i++){
        str[j] = json[i];
        if(json[i] == '\"'){
            if(numberOfDittoMarks == 0){
                numberOfDittoMarks++;
            }else{
                numberOfDittoMarks--;
            }
        }
        if((json[i] == ',' || json[i] == '}') && numberOfDittoMarks == 0){
            str[j] = ',';
            Node node = newNode();
        }
        j++;
    }
    return list;
}

int FindNumberOfKeyValues(char *json){
    int numberOfKeyValues = 0;
    int i = 0;
    while(json[i] != '\0'){
        if(json[i] == ':'){
            numberOfKeyValues++;
        }
        i++;
    }
    return numberOfKeyValues;
}

void DeleteJson(Json this){
    free(this);
}