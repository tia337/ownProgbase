#include <stdio.h>
#include <string.h>
#include <list.h>
#include <convert.h>
#include <storage.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <stdbool.h>
#include <jansson.h>
#include <pbconsole.h>

#define BUFFER_SIZE 100

List * Storage_load(const char * fileName) {
	FILE* fin = fopen(fileName, "r");
	if(fin == NULL) {
		return NULL;
	}

	List* head = List_new();
	char buffer[BUFFER_SIZE];

	while(!feof(fin)) {
		fgets(buffer, BUFFER_SIZE, fin);
		buffer[strlen(buffer) - 1] = '\0';
		List_addLast(head,University_newFromString(buffer));
	}

	fclose(fin);
	return head;
}
void Storage_save(List* self, char* fileName) {
	FILE* fout = fopen(fileName, "w");
	
	University* cur = List_getUniversity(self, 0);
	while(cur != NULL) {
		fprintf(fout, "%s %s %-f %i %i\n",
			University_getName(cur),
			University_getLocation(cur),
			University_getRank(cur),
			University_getmatanPoints(cur),
			University_getStudents(cur));
		 cur = University_getNext(cur);
	}
	fclose(fout);
}

void Storage_writeAsXml(const char * filePath, List * list) {
	FILE* fout = fopen(filePath, "w");
	if(fout == NULL) {
		puts("Can`t open the file.");
		return;
	}

	xmlDoc* doc = NULL;
	xmlNode* rootNode = NULL;
	xmlNode* uniNode = NULL;
	xmlNode* moreDataNode = NULL;

	char strBuf[100];
	doc = xmlNewDoc(BAD_CAST "1.0");

    //root element
    rootNode = xmlNewNode(NULL, BAD_CAST "universities");
    xmlDocSetRootElement(doc, rootNode);

	for(int i = 0; i < List_getSize(list); i++) {
		University* property = List_getUniversity(list, i);
		
		//child
    	uniNode = xmlNewChild(rootNode, NULL, BAD_CAST "university",NULL);
    	xmlNewChild(uniNode, NULL, BAD_CAST "name", BAD_CAST University_getName(property));
    	xmlNewChild(uniNode, NULL, BAD_CAST "location", BAD_CAST University_getLocation(property));
    	sprintf(strBuf, "%f", University_getRank(property));
    	xmlNewChild(uniNode, NULL, BAD_CAST "rank", BAD_CAST strBuf);
    
    	//moreData element as university child
    	moreDataNode = xmlNewChild(uniNode, NULL, BAD_CAST "moreData", NULL);
		sprintf(strBuf, "%i", University_getmatanPoints(property));
    	xmlNewChild(moreDataNode, NULL, BAD_CAST "matanPoints", BAD_CAST strBuf);
		sprintf(strBuf, "%i", University_getStudents(property));
    	xmlNewChild(moreDataNode, NULL, BAD_CAST "students", BAD_CAST strBuf);

	}
	// copy xml contents to buffer
    xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
    fprintf(fout, "%s", (const char *)bufferPtr->content);		
    xmlBufferFree(bufferPtr);
	xmlFreeDoc(doc);
	fclose(fout);
}

List* Storage_readAsXml(const char * filePath) {
	char xmlStr[1500] = "";
	if (!readAllText(filePath, xmlStr)) {
		printf("Error reading %s\n", filePath);
		return NULL;
	}

	xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return NULL;
	}

	List* list = List_new();
	xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
	for(xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) { 
        if (XML_ELEMENT_NODE == xCur->type) {
			University* property = University_new();
             for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
                if (XML_ELEMENT_NODE == xJ->type) {
                    char * content = (char *)xmlNodeGetContent(xJ);
                    if(xmlStrcmp(xJ->name, BAD_CAST "name") == 0) {
                        University_setField(property,"name", (char*) content);
                    } else if(xmlStrcmp(xJ->name, BAD_CAST "location") == 0) {
                        University_setField(property,"location", (char*) content);
                    } else if(xmlStrcmp(xJ->name, BAD_CAST "rank") == 0) {
                        University_setField(property,"rank", (char*)content);
                    } else if(xmlStrcmp(xJ->name, BAD_CAST "moreData") == 0) {
						for(xmlNode* xS = xJ->children; NULL != xS; xS = xS->next) {
							if (XML_ELEMENT_NODE == xS->type) {
								char* source = (char*)xmlNodeGetContent(xS);
								if(xmlStrcmp(xS->name, BAD_CAST "matanPoints") == 0) {
									University_setField(property, "matanPoints", (char*)source);
								} else if(xmlStrcmp(xS->name, BAD_CAST "students") == 0) {
									University_setField(property, "students", (char*)source);
								}
								xmlFree(source);
							}
                        
                    	}
					}

                    xmlFree(content);
                }
             }
			 List_addLast(list, property);
        }
    }
    xmlFreeDoc(xDoc);
	return list;
}

void Storage_writeAsJson(const char * filePath, List * list) {
	FILE* fout = fopen(filePath, "w");

	//create array
	json_t* root = json_array();
	json_t * json = NULL;
	
	for(int i = 0; i < List_getSize(list); i++) {
		University* node = List_getUniversity(list, i);
	
		json = json_object();
	
		json_object_set_new(json, "name", json_string(University_getName(node)));
		json_object_set_new(json, "location", json_string(University_getLocation(node)));
		json_object_set_new(json, "rank", json_real(University_getRank(node)));
		json_t * moreDataObj = json_object();
		json_object_set_new(json, "moreData", moreDataObj);
		json_object_set_new(moreDataObj, "matanPoints", json_integer(University_getmatanPoints(node)));
		json_object_set_new(moreDataObj, "students", json_integer(University_getStudents(node)));


		json_array_append(root, json);
	}
	
	// create JSON doc
	char * jsonString = json_dumps(root, JSON_INDENT(4) | JSON_PRESERVE_ORDER);
	fputs(jsonString, fout);
	free(jsonString);

    // decrease reference count 
	for(int i = 0; i < List_getSize(list); i++) {
		json_decref(json_array_get(root, i));
	}
	json_decref(root);
	fclose(fout);
}

List * Storage_readAsJson(const char * filePath) {
	char jsonStr[1000] = "";
	readAllText(filePath, jsonStr);

	List* list = List_new();

	json_error_t err;
	json_t * jsonArr = json_loads(jsonStr, 0, &err);
	int index = 0;
	json_t * value = NULL;
	json_array_foreach(jsonArr, index, value) {
		json_t * moreDataObj = json_object_get(value, "moreData");
		University* node = University_new();
		University_setField(node, "name",(char *)json_string_value(json_object_get(value, "name")));
		University_setField(node, "location",(char *)json_string_value(json_object_get(value, "location")));
		University_setRank(node, json_real_value(json_object_get(value, "rank")));
		University_setmatanPoints(node, json_integer_value(json_object_get(moreDataObj, "matanPoints")));
		University_setStudents(node, json_integer_value(json_object_get(moreDataObj, "students")));
		List_addLast(list, node);
	}
	json_decref(jsonArr);
	return list;
}

bool readAllText(const char * filePath, char * text) {
	char line[100];
	FILE* fin = fopen(filePath, "r");
    if (fin == NULL) return false;
    if(fgets(line, 100, fin))
        strcpy(text, line);
    while(fgets(line, 100, fin)) {
        strcat(text, line);
    }
    text[strlen(text)+1] = '\0';
	fclose(fin);
	return true;
}
