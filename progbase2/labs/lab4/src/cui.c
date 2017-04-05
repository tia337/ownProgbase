#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <progbase.h>
#include <pbconsole.h>
#include <cui.h>

#define HEIGTH 30
#define WIDTH 90
#define MID 20
#define BOTTOM 40

void Cui_mode(void) {
    Cui_interfaceStart();
    conMove(2,43);
    printf("Welcome!");
    conMove(3,2);
    printf("  Select mode you want from the list below:\n");
    conMove(4,2);
    printf("   1 - work with program\n");
    conMove(5,2);
    printf("   2 - testing\n");
    conMove(6,4);
    conReset();
}

void Cui_interface(void){
    conClear();
    for(int i = 1; i < WIDTH+5; i++){
    	conMove(1,i);
      conSetAttr(FG_BLUE);
    	putchar('*');
    	conMove(MID,i);
    	putchar('*');
      conReset();
    }
    for(int i = 1; i < HEIGTH - 10; i++){
    	conMove(i,0);
      conSetAttr(FG_BLUE);
    	putchar('*');
    	conMove(i, 94);
    	putchar('*');
        sleepMillis(100);
      conReset();
    }
}
void Cui_outMode(void){
    char ops[5][30] = {
                          "Choose an option: ",
                          " r - to read list from a file",
                          " w - to write list to a file",
                          " q - to quit the program",
                          " H - HELP "
                        };
    for(int i = 0; i < sizeof(ops)/sizeof(ops[0]); i++){
        conMove(i+2, 5);
        printf("%s\n", (ops[i]));
    }
}

void Cui_Help(void){
     conMove(MID - 1,1);
     printf("HELP: Choose 1 or 2 to fill array, 3 - to write to file, q - to quit program");
     conReset();
     conMove(MID + 1,1);
}

void Cui_interfaceStart(void){
     conClear();
    for(int i = 1; i < WIDTH+5; i++){
    	conMove(1,i);
      conSetAttr(FG_BLUE);
    	putchar('-');
    	conMove(MID,i);
    	putchar('-');
        sleepMillis(10);
      conReset();
    }
    for(int i = 1; i < HEIGTH - 10; i++){
    	conMove(i,0);
      conSetAttr(FG_BLUE);
    	putchar('|');
    	conMove(i, 94);
    	putchar('|');
        sleepMillis(10);
      conReset();
    }
}

void Cui_insideMode(void){
     char ops[9][70] = {
                        "Enter name of operation: ",
                        " add     - to add an university",
                        " delete  - to delete university",
                        " reset   - to rewrite university",
                        " modify  - to rewrite field of university",
                        " find    - to find universities from specified country",
                        " print   - to print a list of universities",
                        " esc     - to go back",
                        " press 'h' for help "
                    };
     int length = sizeof(ops)/sizeof(ops[0]);
     for(int i = 0; i < length; i++){
         conMove(i+2,1);
         printf("%s\n", (ops[i]));
     }
     conMove(MID - 1,1);
     printf("Waiting for a command");
     conMove(MID + 1,1);
     printf("Enter operation: ");
     conMove(MID + 1,18);
}

void Cui_inHelp(void){
     conMove(MID - 1,1);
     printf("HELP: Choose 1 or 2 to fill array, 3 - to write to file, q - to quit program");
     conMove(MID + 1,1);
}

void Cui_clearMenu(void) {
    for(int x = 1; x <= WIDTH; x++)
    {
        for(int y = 2; y < MID; y++)
        {
            conMove(y,x);
            putchar(' ');
        }
    }
    conMove(2,1);
}

void Cui_clearCommand(void){
    for(int x = 1; x <= WIDTH; x++)
    {
        for(int y = MID + 1; y <= HEIGTH; y++)
        {
            conMove(y,x);
            putchar(' ');
        }
    }
    conMove(MID + 1,1);
}

void Cui_request(void){
    conMove(MID + 1,1);
    puts("Press enter to continue or 'esc' to quit the program: ");
}

void Cui_UniversityFields(void){
    conMove(MID - 1, 1);
    printf("STRUCT: name, location, rank, natanPoints, students");
    conReset();
    conMove(MID + 1,1);
}

void Cui_GoToCommand(void) {
    conMove(MID+1, 1);
}
