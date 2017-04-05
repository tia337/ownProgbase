#ifndef NLP_H
#define NLP_H

#include <stdlib.h>
#include "nlp.h"
#include "list.h"

Text * File_readFile(Text * self, const char * fileIn);

void File_printRes(Text * self, const char * fileIn);

int findAndRemoveWord(Sentence * self);

#endif
