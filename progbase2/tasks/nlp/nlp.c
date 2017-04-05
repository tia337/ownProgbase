#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "nlp.h"


enum{BUFFERSIZE = 500};

void File_printRes(Text * self, const char * fileIn){
  FILE * fout = fopen(fileIn, "w");
  SentenceNode * curr = self->head;
  while(curr != NULL ){
    WordNode * currWrd = curr->data.head;
    while(currWrd!= NULL){
      fprintf(fout, "%s, ", currWrd->data.word);
      currWrd = currWrd->next;
    }
    fputc('\n', fout);

    curr = curr->next;
  }
  fclose(fout);
}

Text * File_readFile(Text * self, const char * fileIn){
  FILE * fin  = fopen(fileIn, "r");
  if(fin == NULL) return NULL;

  Sentence  * newSentence = Sentence_new();
  char buffer[BUFFERSIZE];
  int check = 0;
  int wordIndex = 0;
  while(fgets(buffer, BUFFERSIZE, fin) != NULL){
    buffer[strlen(buffer)] = '\0';
    for(int i = 0; i < strlen(buffer); i++){
      if(check == 1){
        Sentence_free(&newSentence);
        newSentence = Sentence_new();
        check = 0;
      }
      char ch = buffer[i];
      if(isalpha(ch)){
        Word word;
        while(isalpha(buffer[i])){
          word.word[wordIndex] = buffer[i];
          i++;
          wordIndex++;
        }
        word.word[wordIndex] = '\0';
        wordIndex = 0;
        i--;
       Sentence_addLast(newSentence, word);
      }
      else if(ch == '.' || ch == '!' || ch == '?' ){
        Text_addLast(self, *newSentence);
        check = 1;
      } else continue;
    }
    
  }
  
  fclose(fin);
 // WordNode_free(&newSentence);
 Sentence_free(&newSentence);
  return self;
}

int findAndRemoveWord(Sentence * self){
  WordNode * curr = self->head;
  while(curr != NULL){
    WordNode * currnt = curr->next;
    while(currnt != NULL){
        if(strcmp(curr->data.word, curr->data.word) == 0){
          curr = Sentence_removeNode(self, curr);
          currnt = Sentence_removeNode(self, currnt);
        }
        currnt = currnt->next;
    }
    curr = curr->next;
  }
  return 0;
}
