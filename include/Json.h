#ifndef JSON_H
#define JSON_H

#include "LinkedList.h"
#include "string.h"

struct JSON{
    char* (*readJsonIntoString)(char *path);
    void (*delete)(struct JSON*);
};

typedef struct JSON* Json;

Json newJson();
char* ReadJsonIntoString(char *path);
void DeleteJson(Json);

#endif