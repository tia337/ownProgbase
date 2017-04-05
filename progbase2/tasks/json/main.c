#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list.h>
#include <JsonLoader.h>

void readAllText(char * filename, char * str);

int main(void){
    char str[1000] = "";
    char result[1000];
    readAllText("driver.json", str);

    TaxiDriver * driver = TaxiDriver_new("", 0, 0.0, NULL);
    JsonLoader_loadFromString(driver, str);
    JsonLoader_saveToString(result, driver);
    puts(result);

    //free memory
    List * list = TaxiDriver_getClients(driver);
    List_clean(list);
    List_free(&list);
    TaxiDriver_free(&driver);
    return EXIT_SUCCESS;
}

void readAllText(char * filename, char * str){
    FILE * fin = fopen(filename, "r");
    if(fin == NULL) return;
    char buffer[100];
    while(fgets(buffer, 100, fin)){
        strcat(str, buffer);
    }
    fclose(fin);
}
