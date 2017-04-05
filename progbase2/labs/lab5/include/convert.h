#ifndef CONVERT_H
#define CONVERT_H

typedef struct University University;
typedef struct MoreData MoreData;

MoreData* MoreData_new(int matanPoints, int students);
void MoreData_free(MoreData** selfPtr);

University* University_new(void);
University* University_newFromString(const char* str);
void University_free(University** selfPtr);

void University_print(University* self);

char* University_toString(University* self, char* buffer);

char* University_getLocation(University* self);
char* University_getName(University* self);
double University_getRank(University* self) ;
int University_getmatanPoints(University* self);
int University_getStudents(University* self);
University* University_getNext(University* self);

void University_setFromString(University* self, const char* str);
University* University_set(char* name, char* location, float rank, int matanPoints, int students);
int University_setField(University* self, const char* field, const char* data);
void University_setNext(University* self, University* uNext);
void University_setRank(University* self, double data);
void University_setmatanPoints(University* self, int data);
void University_setStudents(University* self, int data);

int University_isEmpty(University* self);
#endif