#ifndef JSONLOADER_H
#define JSONLOADER_H
#include <stdlib.h>
//#include <list.h>

typedef struct TaxiDriver TaxiDriver;
typedef struct Clients Clients;

TaxiDriver * TaxiDriver_new(char * name, int age, float salary, List * clients);
void TaxiDriver_free(TaxiDriver ** selfPtr);
List * TaxiDriver_getClients(const TaxiDriver * self);

void JsonLoader_saveToString(char * str, const TaxiDriver * master);
void JsonLoader_loadFromString(TaxiDriver * master, const char * jsonString);




#endif