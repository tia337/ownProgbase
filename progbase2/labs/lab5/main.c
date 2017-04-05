#include <stdio.h>
#include <string.h>
#include <progbase.h>
#include <pbconsole.h>
#include <convert.h>
#include <list.h>
#include <storage.h>
#include <cui.h>
#include <test.h>

void setupCommand(List* self);
void finishCommand(List* self);

int main(void) {
	char choice = '\0';
	Cui_mode();
	choice = getChar();
	if(choice == '2') {
		testing();
		return 0;
	}
	
	choice = '\0';
	List* list = NULL;
	int index = 0;
	char sourceName[] = "/home/ilya/projects/progbase2/labs/lab5/source.xml";
	char destName[20] = "";
	char command[20] = "";
	char data[50] = "";
	char field[15] = "";

	Cui_interface();
	do {
		Cui_clearImage();
		Cui_outerChoice();
		do {
			Cui_clearCommand();
            choice = getChar();
			switch(choice) {
				case 'r':
					switch(FormatDetector(sourceName)) {
						case 1: 
							list = Storage_load(sourceName);
							break;
						case 2: 
							list = Storage_readAsXml(sourceName);
							break;
						case 3: 
							list = Storage_readAsJson(sourceName);
							break;
						default: 
							puts("ERROR: Unappropriate file dimension.");
							// return 0;
					}
					break;
				case 'w':
					if(list == NULL) break;
					printf("Please, enter name of the file: ");
                    fgets(destName, 20, stdin);
                    destName[strlen(destName) - 1]= '\0';
					switch(FormatDetector(destName)) {
						case 1: 
							Storage_save(list, destName);
							break;
						case 2: 
							Storage_writeAsXml(destName, list);
							break;
						case 3: 
							Storage_writeAsJson(destName, list);
							break;
						default: 
							puts("ERROR: Unappropriate file dimension.");
							// return 0;
					}
					List_free(&list);
					break;
				case 'q':
					if(list != NULL)
						List_free(&list);
					return 0;
				default: 
					Cui_Help();
					break;
			}
		} while(choice != 'r');

		do {
			Cui_clearImage();
            Cui_clearCommand();
            if(strcmp(command, "h") == 0) {
               Cui_inHelp();
            }
            Cui_insideMode();
            fgets(command, 20, stdin);
            command[strlen(command) - 1] = '\0';

            Cui_clearImage();
            Cui_clearCommand();

			if(strcmp(command, "esc") == 0) {
				break;
			} else if(strcmp(command, "add") == 0) {
				setupCommand(list);
				Cui_UniversityFields();

				printf("Please, enter an position to be modified [0..%i] :", List_getSize(list) -1);
    			scanf("%i", &index);
    			getchar();

				printf("Enter data:");
				fgets(data, 40, stdin);
				data[strlen(data)-1] = '\0';

				List_insertAt(list, University_newFromString(data),index);
				finishCommand(list);
			} else if(strcmp(command, "delete") == 0) {
				setupCommand(list);

				printf("Please, enter a position to be reset [0..%i] :", List_getSize(list) -1);
    			scanf("%i", &index);
    			getchar();

				List_removeAt(list, index);
				finishCommand(list);
			} else if(strcmp(command, "modify") == 0) {
				setupCommand(list);
				Cui_UniversityFields();
				
				printf("Please, enter a position to be modified [0..%i] :", List_getSize(list) -1);
    			scanf("%i", &index);
    			getchar();
				
				printf("Enter field:");
				fgets(field, 20, stdin);
				field[strlen(field)-1] = '\0';
				
				printf("Enter new data:");
				fgets(data, 40, stdin);	
				data[strlen(data)-1] = '\0';
				
				List_setField(list,field,data,index);
				finishCommand(list);
			} else if(strcmp(command, "reset") == 0) {
				setupCommand(list);

				printf("Please, enter a position to be reset [0..%i] :", List_getSize(list) -1);
				scanf("%i", &index);
				getchar();

				printf("Enter new data:");
				fgets(data, 40, stdin);
				data[strlen(data)-1] = '\0';

				List_set(list, data, index);
				finishCommand(list);
			} else if(strcmp(command, "find") == 0) {
				setupCommand(list);

				printf("Enter name of country to be found: ");
				fgets(data, 40, stdin);
				data[strlen(data)-1] = '\0';

				Cui_clearImage();
				List_findUniversity(list, data);
			} else if(strcmp(command, "print") == 0) {
				Cui_clearImage();
				List_print(list);
			} else {
                puts("You've entered wrong command");
                strcpy(command, "h");
            }

            if(strcmp(command, "h") != 0) {
                Cui_request();
                fgets(command, 20, stdin);
                command[strlen(command) - 1] = '\0';
            } 
		} while(strcmp(command, "esc") != 0);
	} while(1);
	return 0;
}

void setupCommand(List* self) {
	Cui_clearImage();
	List_print(self);
	Cui_GoToCommand();
}
void finishCommand(List* self) {
	Cui_clearImage();
	List_print(self);
	Cui_clearCommand();
}
