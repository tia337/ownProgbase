#ifndef STORAGE_H
#define STORAGE_H

#include "list.h"
#include "convert.h"

List * Storage_load(const char* fileName);
void Storage_save(List* self, char* fileName);

#endif