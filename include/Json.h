#ifndef JSON_H
#define JSON_H

#include "LinkedList.h"
#include "string.h"

struct JSON{
    char* (*readJsonIntoString)(char *path);
    LinkedList (*parseJsonIntoList)(char *json);
    int (*findNumberOfKeyValues)(char *json);
    void (*delete)(struct JSON*);
};

typedef struct JSON* Json;

Json newJson();
char* ReadJsonIntoString(char *path);
LinkedList ParseJsonIntoList(char *json);
int FindNumberOfKeyValues(char *json);
void DeleteJson(Json);

#endif