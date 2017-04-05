#ifndef LIST_H
#define LIST_H

#include "convert.h"
typedef struct List List;

List* List_new(); 
void List_free(List** selfPtr);

void List_addFirst(List* self, University* uni);
void List_addAt(List* self, University* uni, int position);
void List_addLast(List* self, University* uni);

void List_removeFirst(List* self);
void List_removeAt(List* self, int position);
void List_removeLast(List* self);

University* List_getUniversity(List* self, int position);
int List_getSize(List* self);
int List_count(List* self);

void List_setField(List* self, char* field, char* data, int position);
void List_set(List* self, char* data, int position);

void List_print(List* self);
void List_findUniversity(List* head, const char* country);

#endif