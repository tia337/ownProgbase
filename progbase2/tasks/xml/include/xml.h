#ifndef XML_H
#define XML_H
#include "list.h"

typedef struct TaxiDriver TaxiDriver;
typedef struct Client Client;

void XmlLoader_saveToString(char * str, struct TaxiDriver * td);  // 1
void XmlLoader_loadFromString(struct TaxiDriver * td, const char * xmlStr);  // 2
void * Client_new(char * str);
void * Client_free(void **self);

TaxiDriver * test(void);

List * TaxiDriver_getClients(TaxiDriver * self);

char * Driver_getName(TaxiDriver * self);
int  Driver_getAge(TaxiDriver * self);
double  Driver_getSalary(TaxiDriver * self);

char * Clients_getClient(List * self, int position);

#endif