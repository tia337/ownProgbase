#ifndef CONVERT_H
#define CONVERT_H

typedef struct University University;
typedef struct MoreData MoreData;

MoreData* MoreData_new(int matanPoints, int students);
MoreData* MoreData_new(int matanPoints, int students);
University* University_newEmpty(void);
University* University_new(char* name, char* location, float rank, int matanPoints, int students);
University* University_newFromString(const char* str);
University* University_getNext(University* self);

void University_free(University** selfPtr);
void MoreData_free(MoreData** selfPtr);
void University_print(University* self);
void University_set(University* self, const char* str);
void University_setNext(University* self, University* uNext);


char* University_toString(University* self, char* buffer);
char* University_getLocation(University* self);
char* University_getName(University* self);

double University_getRank(University* self) ;

int University_getmatanPoints(University* self);
int University_getStudents(University* self);
int University_setField(University* self, const char* field, const char* data);
int University_isEmpty(University* self);
#endif