#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int descending_arr(const void * a, const void * b);
int descending_struct(const void * a, const void * b);
void Array_foreach(int intsArray[], int len, void (*action)(int, int));
void Array_foreachReversed(int intsArray[], int len, void (*callbackSecond)(int, int));
void callbackFirst(int value, int index);
void callbackSecond(int value, int index);

typedef struct Startup Startup;
struct Startup{
  char project[20];
  int investitions;
  int teamSize;
};

int main (void){
    char words [] [10] = {
      "plumber", "quizzed",
      "auizzer", "muzjiks",
      "grizzly", "puzzler",
      "mezuzot", "conflux",
      "waxworm", "maffick"};

    int intsArray [] = {1, 15, 25, 35, 3, 78, 66, 44, 77, 17 };
    int size = sizeof(intsArray) / sizeof(intsArray[0]);
    printf("Task: output array of words in descending order of vowels amount\n");
    for(int i = 0; i < 10; i++){
      printf("%s ", words[i]);
    }
    puts(" ");
    qsort(words, 10, sizeof(words[0]), descending_arr);
    printf("After sort\n");
    for(int i = 0; i < 10; i++){
      printf("%s ", words[i]);
    }
    printf("\n");

    Startup array[3];
    strcpy(array[0].project, "Boticar");
    array[0].investitions = 45;
    array[0].teamSize = 10;

    strcpy(array[1].project, "3Dscanner");
    array[1].investitions = 150;
    array[1].teamSize = 7;

    strcpy(array[2].project, "Drone");
    array[2].investitions = 70;
    array[2].teamSize = 15;

    puts(" ");
    printf("Task: output structs in descending order of investitions amount\n");
    for(int i = 0; i < 3; i++){
      printf("--> %s| %i| %i|   ", array[i].project, array[i].investitions, array[i].teamSize);
    }
    qsort(array, 3, sizeof(struct Startup), descending_struct);
    printf("\nAfter sorting:\n");
    for(int i = 0; i < 3; i++){
      printf("--> %s| %i| %i|   ", array[i].project, array[i].investitions, array[i].teamSize);
    }
    printf("\n\n");
    printf("Task is vey long (I`ve put it in the end of main.c)\n");
    printf("This is array:\n");
    for(int i = 0; i < size; i++){
      printf("%i  ", intsArray[i]);
    }
    printf("\n\n");
    Array_foreach(intsArray, size, (*callbackFirst));
    printf("\n\n");
    Array_foreachReversed(intsArray, size, (*callbackSecond));
    printf("\n");
    return 0;
}

void callbackFirst(int value, int index){
  printf("value:%i index:%i |", value, index);
}

void callbackSecond(int value, int index){
  if(index % 2 == 0){
    printf("value:%i index:%i |", value, index);
  }
}

void Array_foreach(int intsArray[], int len, void (*callbackfirst)(int, int)){
  for(int i = 0; i < len; i++){
    callbackFirst(intsArray[i], i);
  }
}

void Array_foreachReversed(int intsArray[], int len, void (*callbackSecond)(int, int)){
  for(int i = len - 1; i >= 0 ; i--){
    callbackSecond(intsArray[i], i);
  }
}

int descending_struct(const void * a, const void * b){
  struct Startup * first = (struct Startup * )a;
  struct Startup * second = (struct Startup * )b;
    if(first->investitions < second->investitions){
      return 1;
    }
    else if(first->investitions > second->investitions){
      return -1;
    }
    else{
      return 0;
    }

}

int descending_arr(const void * a, const void * b) {
  char vowels[] = "aeiouAEIOU";
  char * word1 = (char*)a;
  char * word2 = (char*)b;
  int vowelCount1 = 0;
  int vowelCount2 = 0;
    for (int i = 0; i < strlen(word1); i++) {         /* loop through word   */
          for (int j = 0; j < strlen(vowels); j++) {   /* loop through vowels */
             if (word1[i] == vowels[j]) {
                 vowelCount1++;
                //  break;
             }
             if (word2[i] == vowels[j]) {
                 vowelCount2++;
                //  break;
            }
        }
    }
      if(vowelCount1 < vowelCount2){
        return 1;
      }
      else if(vowelCount1 > vowelCount2){
        return -1;
      }
      else{
        return 0;
      }

}

// task 3
// Створити функцію: void Array_foreach(int arr[], int len, void (*action)(int, int));
// яка проходиться по масиву arr у прямому порядку і для кожного значення викликає
// callback-функцію action із двома аргументами: поточне значення у масиві та індекс
// поточного елемента масиву.
//
// Створити функцію: void Array_foreachReversed(int arr[], int len, void (*action)(int, int));
// яка проходиться по масиву arr у зворотньому порядку і для кожного значення викликає
// callback-функцію action із двома аргументами: поточне значення у масиві та індекс
// поточного елемента масиву.
// У функції main() створити і вивести тестовий масив цілих чисел та викликати функції
// Array_foreach() та Array_foreachReversed на тестовому масиві чисел із callback-функціями,
// що виводять у консоль індекс і значення елементів із парними значеннями.
