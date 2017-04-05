#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "list.h"
#include "nlp.h"



struct WordNode * WordNode_new(Word data){
  struct WordNode * node = (struct WordNode *)malloc(sizeof(struct WordNode));
  node->next = NULL;
  node->data = data;
  return node;
}

struct SentenceNode * SentenceNode_new(Sentence data){
  struct SentenceNode * node = (struct SentenceNode *)malloc(sizeof(struct SentenceNode));
  node->next = NULL;
  node->data = data;
  return node;
}


void Text_removeList(Text * self) {
  SentenceNode * cur = self->head;
  while(cur != NULL) {
    findAndRemoveWord(&cur->data);
    cur = cur->next;
  }
}


WordNode * Sentence_removeNode(Sentence * self, WordNode * similar) {
  assert(self->head != NULL);
  WordNode * cur = self->head;
  if (strcmp(self->head->data.word,similar->data.word) == 0) {
    Sentence_removeFirst(self);
    return cur;
  }
  while (cur->next->next != NULL && strcmp(cur->next->data.word, similar->data.word) != 0) {
    cur = cur->next;
  }
  WordNode * node = cur->next;
  cur->next = node->next;
  WordNode_free(&node);
  return cur;
}

Text * Text_process(Text * self){
  SentenceNode * curr = self->head;
  while(curr != NULL){
    Sentence_process(&curr->data);
    if(Sentence_size(&curr->data) == 0){

    }
    curr = curr->next;
  }
  return self;
}

Sentence * Sentence_process(Sentence * self){
  WordNode * curr = self->head;
  while(curr != NULL){
    if(!findAndRemoveWord(self)){

    }
    curr = curr->next;
  }
  return self;
}

Sentence * Sentence_new(void){
  Sentence * list = (Sentence *)malloc(sizeof(Sentence));
  list->head = NULL;
  return list;
}

int Text_size(Text * self) {
  int size = 0;
  SentenceNode * curr = self->head;
  while (curr != NULL) {
    size += 1;
    curr = curr->next;
  }
  return size;
}

void Sentence_free(Sentence ** self){
 
  assert(NULL != self);
  free(*self);
  *self = NULL;
}

void Sentence_removeFirst(Sentence * self) {
  assert(self->head != NULL);
  struct WordNode * node = self->head;
  self->head = node->next;
  WordNode_free(&node);
}

void WordNode_free(WordNode ** self) {
    assert(NULL != self);
    free(*self);
    *self = NULL;
}

void Sentence_addLast(Sentence * self, Word data){
    WordNode * node = WordNode_new(data);
    if (self->head == NULL) {
        self->head = node;
        return;
    }
    WordNode * curr = self->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = node;
}

int Sentence_size(Sentence * self){
  int count = 0;
  WordNode * curr = self->head;
  while(curr != NULL){
    count++;
    curr = curr->next;
  }
  return count;
}

Text * Text_new(void){
  Text * text = (Text *)(malloc(sizeof(Text)));
  text->head = NULL;
  return text;
}

void Text_free(Text ** self){
  int i = 0;
  while(i < Text_size(*self)){
    Text_removeFirst(*self);
    i++;
  }
  assert(NULL != self);
  free(*self);
  *self = NULL;
}

void Text_addLast(Text * self, Sentence data){
  SentenceNode * node = SentenceNode_new(data);
  if(self->head == NULL){
    self->head = node;
    return;
  }
  SentenceNode * curr = self->head;
  while(curr->next != NULL){
    curr = curr->next;
  }
  curr->next = node;
}

void SentenceNode_free(SentenceNode ** self){
  assert(NULL != self);
  free(*self);
  *self = NULL;
}

void Text_removeFirst(Text * self){
  struct SentenceNode * node = self->head;
  if(node == NULL) assert(0);
  self->head = node->next;
  SentenceNode_free(&node);
}


void Sentence_cleanList(Sentence * self){
    int size = Sentence_size(self);
    for(int i = 0; i < size; i++){
        WordNode * curr = self->head;
        if(curr == NULL) return;
        if(curr->next == NULL){
            WordNode_free(&curr);
            self->head = NULL;
            return;
        } 
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        WordNode_free(&(curr->next));
        curr->next = NULL;
    }
}

void Text_cleanList(Text * self){
    int size = Text_size(self);
    for(int i = 0; i < size; i++){
        SentenceNode * curr = self->head;
        if(curr == NULL) return;
        if(curr->next == NULL){
            Sentence_cleanList(&curr->data);
            SentenceNode_free(&curr);
            self->head = NULL;
            return;
        }
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        Sentence_cleanList(&(curr->next->data));
        SentenceNode_free(&curr->next);
        curr->next = NULL;
    }
}
