#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <convert.h>
#include <list.h>

#define throw(MSG) assert(0 && MSG);

struct List {
	size_t size;
    University* items;
};

List* List_new(void) {
	List* self = (List*)malloc(sizeof(struct List));
	self->size = 0;
	self->items = NULL;
	return self;
}

void List_free(List ** selfPtr) {
	if (selfPtr == NULL || *selfPtr == NULL) throw("Null pointer on free()");
	University* cur = List_getUniversity(*selfPtr, 0);
	University* temp = NULL;
	while(cur != NULL) {
		temp = University_getNext(cur);
		University_free(&cur);
		cur = temp;
	}
	free(*selfPtr);
    *selfPtr = NULL;
}

void List_addFirst(List* self, University* uni) {
	University_setNext(uni, self->items);
	self->items = uni;
	self->size = List_count(self);
}
void List_insertAt(List* self, University* uni, int position) {
	if(uni == NULL) throw("Null reference");
	if(position < 0) throw("Out of bounds");
	if(position >= self->size) position = self->size;

	if(position == 0) {
		List_addFirst(self, uni);
		return;
	}
	
	University* cur = self->items;
	int i = 0;
	while(cur != NULL && i != position - 1) {
		cur = University_getNext(cur);
		i++;
	}
	University_setNext(uni, University_getNext(cur));
	University_setNext(cur, uni);
	self->size = List_count(self);
}

void List_addLast(List* self, University* uni) {
	if(uni == NULL) throw("Null reference");
	List_insertAt(self, uni, self->size++);
}

void List_removeFirst(List* self) {
	University* node = self->items;
	if(node == NULL) throw ("NUll reference");
	self->items = University_getNext(node);
	University_free(&node);
	self->size = List_count(self);
}

void List_removeAt(List* self, int position) {
	if(position < 0 || position >= self->size) throw("Out of bounds");

	if(position == 0) {
		List_removeFirst(self);
		return;
	}

	University* cur = self->items;
	int i = 0;
	while(cur != NULL && i != position - 1) {
		i++;
		cur = University_getNext(cur);
	}
	University* node = University_getNext(cur);
	University_setNext(cur, University_getNext(node));
	University_free(&node);
	self->size = List_count(self);
}

void List_removeLast(List* self) {
	List_removeAt(self, self->size - 1);
}

University* List_getUniversity(List* self, int position) {
	if(position < 0 || position > self->size) throw("Out of bounds");
	University* cur = self->items;
	int i = 0;

	while(cur != NULL && i != position) {
		i++;
		cur = University_getNext(cur);
	}
	return cur;
}

int List_getSize(List* self) {
	return (int)self->size;
}

int List_count(List* self) {
	int count = 0;
	University* cur = self->items;
	while(cur != NULL) {
		count++;
		cur = University_getNext(cur);
	}
	return count;
}

void List_set(List* self, char* data, int position) {
	University_setFromString(List_getUniversity(self, position), data);
}
void List_setField(List* self, char* field, char* data, int position) {
	University_setField(List_getUniversity(self, position), field, data);
}

void List_print(List* self) {
	if(self == NULL) throw("Null reference");
	University* cur = self->items;
	puts(" NAME         | LOCATION     | RATE | MATPOINTS | STUDENT |");
	while(cur != NULL) {
		University_print(cur);
		cur = University_getNext(cur);
	}
}

void List_findUniversity(List* head, const char* country) {
	University* cur = head->items;
	int found = 0;
	while(cur != NULL) {
		if(strcmp(country, University_getLocation(cur)) == 0) {
			University_print(cur);
			found++;
		}
		cur = University_getNext(cur);
	}
	if(!found) printf("There's no universities from %s", country);
}
