#include<stdio.h>
#include"list.h"
#include"nlp.h"

int main(void){
    Text * text = Text_new();
    text = File_readFile(text, "new.txt");
    Text_removeList(text);
    File_printRes(text, "result.txt");
    Text_cleanList(text);
    Text_free(&text);
    return EXIT_SUCCESS;
}