#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "convert.h"

struct MoreData {
	int matanPoints;
	int students;
};
struct University {
	char name[30];
	char location[30];
	double rank;
	struct MoreData * amounts;
	struct University * next;
};

MoreData* MoreData_new(int matanPoints, int students) {
	MoreData* self = (MoreData*)malloc(sizeof(MoreData));
	self->matanPoints = matanPoints;
	self->students = students;
	return self;
}

University* University_newEmpty(void) {
	University* self = (University*)malloc(sizeof(University));
	strcpy(self->name, "");
	strcpy(self->location, "");
	self->rank = 0.0;
	self->amounts = MoreData_new(0,0);
	self->next = NULL;
	return self;
}

University* University_new(char* name, char* location, float rank, int matanPoints, int students) {
	University* self = (University*)malloc(sizeof(University));
	strcpy(self->name, name);
	strcpy(self->location, location);
	self->rank = rank;
	self->amounts = MoreData_new(matanPoints, students);
	self->next = NULL;
	return self;
}

void Stats_free(MoreData** selfPtr){
	free(*selfPtr);
	*selfPtr = NULL;
}
void University_free(University** selfPtr){
	MoreData* node = (*selfPtr)->amounts;
	Stats_free(&node);
	free(*selfPtr);
	*selfPtr = NULL;
}

void University_print(University* self) {
	printf(" %-12s | %-12s | %-4.1f | %-6i    | %-7i |\n", self->name, self->location, self->rank, self->amounts->matanPoints, self->amounts->students);  
}

char* University_toString(University* self, char* buffer) {
	sprintf(buffer, "%s %s %-.1f %i %i", self->name, self->location, self->rank, self->amounts->matanPoints, self->amounts->students);
	return buffer;
}

University* University_newFromString(const char* str) {
	University* self = University_new("","",0.0,0,0);
	University_set(self, str);
	return self;
}

void University_set(University* self, const char* str) {
	sscanf(str, "%s %s %lf %i %i",self->name, self->location, &(self->rank), &(self->amounts->matanPoints), &(self->amounts->students));
}
int University_setField(University* self, const char* field, const char* data) {
	if(strcmp(field, "name") == 0) {
		strcpy(self->name, data);
	} else if(strcmp("location", field) == 0) {
		strcpy(self->location, data);
	} else if(strcmp(field, "rank") == 0) {
		self->rank = atof(data);
	} else if(strcmp(field, "matanPoints") == 0) {
		self->amounts->matanPoints = atoi(data);////////////////////////matanPoints atof
	} else if(strcmp(field, "students") == 0) {
		self->amounts->students = atoi(data);
	} else {
		return 1;
	}
	return 0;
}

char* University_getName(University* self) {
	return self->name;
}

char* University_getLocation(University* self) {
	return self->location;
}

double University_getRank(University* self) {
	return self->rank;
}

int University_getmatanPoints(University* self) {
	return self->amounts->matanPoints;
}

int University_getStudents(University* self) {
	return self->amounts->students;
}

University* University_getNext(University* self) {
	return self->next;
}
void University_setNext(University* self, University* uNext) {
	self->next = uNext;
}

int University_isEmpty(University* self) {
	if(strcmp(self->name, "") && strcmp(self->location, "") == 0 &&
	self->rank == 0.0 && self->amounts->matanPoints == 0 && self->amounts->students == 0) 
		return 0;
	return 1;
}
