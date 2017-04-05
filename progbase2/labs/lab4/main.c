#include <stdio.h>
#include <string.h>
#include <progbase.h>
#include <pbconsole.h>
#include <cui.h>
#include <list.h>
#include <storage.h>
#include <convert.h>



int testing(void);
void setupCommand(List* self);
void finishCommand(List* self);

int main(void) {
	char mode = '\0';
	Cui_mode();
	mode = getChar();
	if(mode == '2') {
		testing();
		return 0;
	}

	mode = '\0';
	List* list = NULL;
	int index = 0;
	char sourceFile[] = "input.txt";
	char destName[20] = "";
	char command[20] = "";
	char data[50] = "";
	char field[15] = "";

	Cui_interface();
	do {
		Cui_clearMenu();
		Cui_outMode();
		do {
			Cui_clearCommand();
            mode = getChar();
			switch(mode) {
				case 'r':
					list = Storage_load(sourceFile);
					break;
				case 'w':
					if(list == NULL) break;
					printf("Please, enter name of the file: ");
                    fgets(destName, 20, stdin);
                    destName[strlen(destName) - 1]= '\0';
					Storage_save(list, destName);
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
		} while(mode != 'r');

		do {
			Cui_clearMenu();
            Cui_clearCommand();
            if(strcmp(command, "h") == 0) {
               Cui_inHelp();
            }
            Cui_insideMode();
            fgets(command, 20, stdin);
            command[strlen(command) - 1] = '\0';

            Cui_clearMenu();
            Cui_clearCommand();

			if(strcmp(command, "esc") == 0) {
				break;
			} else if(strcmp(command, "add") == 0) {
				setupCommand(list);
				Cui_UniversityFields();

				printf("Please, enter an position to be inserted [0..%i] :", List_getSize(list) -1);
    			scanf("%i", &index);
    			getchar();

				printf("Enter data:");
				fgets(data, 40, stdin);
				data[strlen(data)-1] = '\0';

				List_addAt(list, University_newFromString(data),index);
				finishCommand(list);
			} else if(strcmp(command, "delete") == 0) {
				setupCommand(list);

				printf("Please, enter a position to be removed [0..%i] :", List_getSize(list) -1);
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
				fgets(field, 10, stdin);
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

				Cui_clearMenu();
				List_findUniversity(list, data);
			} else if(strcmp(command, "print") == 0) {
				Cui_clearMenu();
				List_print(list);
			} else {
                puts("Please, enter correct data");
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
	Cui_clearMenu();
	List_print(self);
	Cui_GoToCommand();
}
void finishCommand(List* self) {
	Cui_clearMenu();
	List_print(self);
	Cui_clearCommand();
}
