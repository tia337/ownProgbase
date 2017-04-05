#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "xml.h"
#include "list.h"

struct Client{
    char name[20];
};

struct TaxiDriver{
    char name[15];
    int age;
    double salary;
	List * client;
};

void XmlLoader_saveToString(char * str, struct TaxiDriver * td){
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * clientsNode = NULL;
	xmlNode * clientNode = NULL;
	char strBuf[100];
	
	doc = xmlNewDoc(BAD_CAST "1.0");

	// create xml tree

	// create one root element
	rootNode = xmlNewNode(NULL, BAD_CAST "TaxiDriver");
	xmlDocSetRootElement(doc, rootNode);
	
	// student child
	xmlNewChild(rootNode, NULL, BAD_CAST "name", BAD_CAST td->name);
	sprintf(strBuf, "%i", td->age);  // copy number to string
	xmlNewChild(rootNode, NULL, BAD_CAST "age", BAD_CAST strBuf);
	sprintf(strBuf, "%f", td->salary);  // copy number to string
	xmlNewChild(rootNode, NULL, BAD_CAST "salary", BAD_CAST strBuf);
	clientsNode = xmlNewChild(rootNode, NULL, BAD_CAST "clients", NULL);
	// create client  element as taxidriver child
	int len = List_count(td->client);
    for(int i = 0; i < len; i++){
		clientNode = xmlNewChild(clientsNode, NULL, BAD_CAST "client", NULL);
        Client * cl = List_get(td->client, i);
        xmlNewProp(clientNode, BAD_CAST "name", BAD_CAST cl->name);
    }
	// copy xml contents to char buffer
	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
	strcpy(str, (char *) bufferPtr->content);
	
	xmlBufferFree(bufferPtr);
	
	xmlFreeDoc(doc);
}


void XmlLoader_loadFromString(struct TaxiDriver * td, const char * xmlStr){
	List * list = TaxiDriver_getClients(td);
	
    xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return ;
    }
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
    for(xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
        if (XML_ELEMENT_NODE == xCur->type) {
            for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
                if (XML_ELEMENT_NODE == xJ->type) {
					if (xmlStrcmp(xJ->name, BAD_CAST "client") == 0) {
                        xmlNode * xName = xJ;
						char * name = (char *)xmlGetProp(xName, BAD_CAST "name");
						Client * new = Client_new(name);
						List_addLast(list, new);
						xmlFree(name);
                        continue;
                    }
					char * content = (char *)xmlNodeGetContent(xJ);
					if(xmlStrcmp(xJ->name, BAD_CAST "name") == 0){
						strcpy(td->name, content);
					}
					if(xmlStrcmp(xJ->name, BAD_CAST "age") == 0){
						td->age = atoi(content);
					}
					if(xmlStrcmp(xJ->name, BAD_CAST "salary") == 0){
						td->salary = atof(content);
					}
					xmlFree(content);
                }
            }
        }
    }
	xmlFreeDoc(xDoc);
}

void * Client_new(char * str){
	Client * self = (Client *)malloc(sizeof(Client));
	strcpy(self->name, str);
	return self;
}

void * Client_free(void **self){
	free(*self);
    *self = NULL;
}

List * TaxiDriver_getClients(TaxiDriver * self){
	return self->client;
}

TaxiDriver * test(void){
	List * list = List_new();
	Client * first  = Client_new("vadim");
	Client * second = Client_new("misha") ;
	List_addLast(list, first);
	List_addLast(list, second);

    TaxiDriver * self = malloc(sizeof(TaxiDriver));
    strcpy(self->name, "Taras");
	self->age = 23;
	self->salary = 1756.56;
	self->client = list;
    return self;
}
char * Driver_getName(TaxiDriver * self){ 
	return self->name;
}
int  Driver_getAge(TaxiDriver * self){ 
	return self->age;
}
double  Driver_getSalary(TaxiDriver * self){ 
	return self->salary;
}

char * Clients_getClient(List * self, int position){
    return (char *)List_get(self, position);
}