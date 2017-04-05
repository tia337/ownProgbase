#include <stdio.h>
#include <stdlib.h>
#include "xml.h"
#include "list.h"

// I return two clients in xmlLoadFromString and in test  function
// thats why we have in output
// vadim
// misha
// vadim
// misha



int main(void){
    char str[1000] = "";
	
    TaxiDriver * td = test();
    
    XmlLoader_saveToString(str, td);
     
    puts(str);

    XmlLoader_loadFromString(td, str);

    printf("Name:%s\nAge:%i\nSalary:%f\n", Driver_getName(td), Driver_getAge(td), Driver_getSalary(td));
    
    List * list = TaxiDriver_getClients(td);
    
    printf("Clients: \n");
    int len = List_count(list);
    for(int i = 0; i < len; i++){
        printf("\tclient: %s\n", Clients_getClient(list, i));
    }
    
    List_clean(list);
    List_free(&list);
    free(td);
	return 0;
}
