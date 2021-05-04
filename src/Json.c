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
            node->code = malloc(sizeof(str));
            strcpy(node->code, str);
            memset(str, 0, numberOfCharacterInJson);
            list->add(node, list->head);
            list->size++;
            j = -1;
        }
        j++;
    }
    for(i = 0; i < numberOfKeyValues; i++){
        char *characters = list->get(i, list->head)->code;
        char key[strlen(characters)];
        // memset(key, 0, strlen(characters));
        int x = 0;
        while(characters[x] != ':'){
            key[x] = characters[x];
            x++;
        }
        key[x] = '\0';
        char value[strlen(characters)];
        int y = 0;
        x += 1;
        while(characters[x] != ','){
            value[y] = characters[x];
            x++;
            y++;
        }
        value[y] = '\0';
        x = 0;
        while(key[x] != '\"'){
            x++;
        }
        x++;
        for(y = 0; y < strlen(characters); y++){
            key[y] = key[y + x];
        }
        x = 0;
        while(key[x] != '\"'){
            x++;
        }
        key[x] = '\0';
        
        x = 0;
        while(value[x] != '\"'){
            x++;
        }
        x++;
        for(y = 0; y < strlen(characters); y++){
            value[y] = value[y + x];
        }
        x = 0;
        while(value[x] != '\"'){
            x++;
        }
        value[x] = '\0';
        list->get(i, list->head)->key = malloc(sizeof(key));
        strcpy(list->get(i, list->head)->key, key);
        list->get(i, list->head)->value = malloc(sizeof(value));
        strcpy(list->get(i, list->head)->value, value);
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