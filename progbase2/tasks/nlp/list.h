#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "list.h"


typedef struct Text Text;
typedef struct Word Word;
typedef struct Sentence Sentence;
typedef struct SentenceNode SentenceNode;
typedef struct WordNode WordNode;

struct Word{
    char word[20];
};


struct WordNode {
    Word data;
    WordNode * next;
};

struct Sentence{
  struct  WordNode * head;
};

struct SentenceNode{
    Sentence data;
    SentenceNode * next;
};

struct Text{
    SentenceNode * head;
};


struct WordNode * WordNode_new(Word data);

struct SentenceNode * SentenceNode_new(Sentence data);

void Sentence_addLast(Sentence * self, Word data);

void Sentence_free(Sentence ** self);

int Sentence_size(Sentence * self);

void Sentence_cleanList(Sentence * self);

void SentenceNode_free(SentenceNode ** self);

void Sentence_removeFirst(Sentence * self) ;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WordNode_free(WordNode ** self);

void Text_removeList(Text * self);

void Text_count(Text * self);

void Text_free(Text ** self);

int Text_size(Text * self);

void Text_addLast(Text * self, Sentence data);

void Text_print(Text * self);

int Text_size(Text * self);

void Text_removeFirst(Text * self);

void Text_cleanList(Text * self);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

Text * Text_new(void);

Sentence * Sentence_new(void);

Text * Text_process(Text * self);

WordNode * Sentence_removeNode(Sentence * self, WordNode * similar);

Sentence * Sentence_process(Sentence * self);

#endif
