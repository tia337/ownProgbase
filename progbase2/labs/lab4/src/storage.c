#include <stdio.h>
#include <string.h>
#include "list.h"
#include "convert.h"
#include "storage.h"

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
