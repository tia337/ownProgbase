#ifndef STORAGE_H
#define STORAGE_H

#include "list.h"
#include "convert.h"
#include <stdbool.h>


List * Storage_load(const char* fileName);
void Storage_save(List* self, char* fileName);

void Storage_writeAsXml(const char * filePath, List * list);
List* Storage_readAsXml(const char * filePath);

void Storage_writeAsJson(const char * filePath, List * list);
List * Storage_readAsJson(const char * filePath);

bool readAllText(const char * filePath, char * text);
#endif