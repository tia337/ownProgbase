#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
int main(void){
    /* pointers declaration */
    char *inputStr = NULL;
    int *i = NULL;
    int *flag = NULL;
    /* memory allocation */
    inputStr =(char *) malloc(100 * sizeof(char));           /* alloc memory for input string */
    i = (int *) malloc(1 * sizeof(int));
    flag = (int *) malloc(1 * sizeof(int));
    
    if (NULL == inputStr || NULL == i || NULL == flag){
        printf("Alloc error");
        return EXIT_FAILURE;
    }
    printf("Please, input string and I will output last char in Upper Case:\n ");
    fgets(inputStr, 100, stdin);
    printf("here is your string : %s\n", inputStr);
    	
    for((*i) = strlen(inputStr); (*i) > 0; (*i)-- ){
    	if(isupper(inputStr[*i])!= 0){
    		printf("here is last char in Upper Case: %c\n", inputStr[*i]);
    		*flag = 1;
    		break;
    	}
    }
    if(*flag == 0){
    	printf("0, there is no elements in uppercase \n");
    }
    /* memory deallocation */
    free(inputStr);          
    free(i);            
    free(flag);
    return EXIT_SUCCESS;
}

