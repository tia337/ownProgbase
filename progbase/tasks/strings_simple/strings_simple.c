#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
 
 
int main(void) {
    int i = 0;
    int num = 0;
    int j = 0;
    int check = 0;
    char word[200][200];
    int wordIndex = 0;
    int col = 0;
    int row = 0;
    int vow = 0;
    int cons = 0;
    int count = 0;
 
   char vowel[] = {'a','e','y','u','o','i','A','E','Y','U','I','O'};
    char consonants[] = {'q', 'w','r','t','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','Q','W','R','T','P','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
    int size_vowel = strlen(vowel);
    int size_consonant = strlen(consonants);
    char text[] = {"Tesla gained experience in telephony and electrical engineering before emigrating to the UnitedStates in 1884 to work for Thomas Edison in New York City.He soon struck out on his own with financial backers setting up laboratories and companies to develop a range of electrical devices.His patented AC induction motor and transformer were licensed by George Westinghouse who also hired Tesla for a short time as a consultant.Tesla was renowned for his achievements eventually earning him a reputation."};
   int length = strlen(text);
 
    printf("Here is task 1:we output all text and number of characters in it:\n");
    printf("===========================================================\n");
    for(i = 0; i < length; i++){
        printf("%c", text[i]);
    }
    printf("\nThe number of characters is:%i\n", length);
    printf("===========================================================\n");
 
/*task2*/
 
    printf("Here is task 2:we output all text without spaces and punctuation characters and number of characters in it:\n");
    printf("===========================================================\n");
    for(i = 0; i < length; i++){
        if(isspace(text[i]) == 0 && ispunct(text[i]) == 0){
                printf("%c", text[i]);
                num++;
        }
        else{
                i++;
                printf("%c", text[i]);
                num++;
        }
     }
     length = strlen(text);
     printf("\n");
     printf("The number of characters is:%i\n", num);
     printf("===========================================================\n");
 
/*task3*/
     num = 0;
     printf("Here is task 3:we output all sentences and number of characters in it:\n");
     printf("===========================================================\n");
     for(i = 0; i < length; i++){
        if(text[i] == '.' ||text[i] == '!' || text[i] == '?'){
            printf("\nThe number of characters is:%i", num);
            printf("\n_______________________________\n");
            num = 0;
        }
        else {
            printf("%c", text[i]);
            num++;
        }
     }
 
/*task4*/
 
        printf("\n===========================================================\n");
        printf("Here is task 4:we output amount of words in the text:\n");
        printf("===========================================================\n");
        num = 0;
        for(i = 0; i < length; i++){
            if(isspace(text[i]) != 0){
                num++;
            }
 
        }
        printf("The amount of words in the text is:%i\n", num);
        printf("===========================================================\n");
 
/*task5*/
 
        printf("Here is task 5:we output all words in low register starting with vovel :\n");
        printf("===========================================================\n");
        num = 0;
        i = 0;
        size_vowel = sizeof(vowel) / sizeof(vowel[0]);
        for(j = 0; j < size_vowel; j++){
            if(text[0] == vowel[j]){
                while(isspace(text[i]) != 0){
                    num++;
                    printf("%c", text[i]);
                    i++;
                }
            }
 
        }
 
        for(i = 0; text[i] !='\0'; i++){
            for(j = 0; j < size_vowel; j++){
                if(isspace(text[i]) != 0 && text[i+1] == vowel[j] && isupper(text[i+1]) == 0){
                i++;
                   while(isalpha(text[i]) != 0){
                        printf("%c", text[i]);
                        i++;
 
                   }
                    i--;
                    printf(", ");
                    num++;
                }
 
            }
 
        }
        printf("\nThe amount of words in the text is:%i\n", num);
        printf("===========================================================\n");
 
/*task6*/
 
        printf("Here is task 6:we output all words that has more vovel than consonants:\n");
        printf("===========================================================\n");
        cons = 0;
        i = 0;
        j = 0;
 
        vow = 0;
        size_vowel = sizeof(vowel) / sizeof(vowel[0]);
        size_consonant = sizeof(consonants) / sizeof(consonants[0]);
  /*this block compare vowels and consonants*/
       count = 0;
       row = 0;
       col = 0;
       length = strlen(text);
       for(i = 0; i < length; i++) {
        check = 0;
        if (isalpha(text[i]) != 0) {
            vow = 0;
            cons = 0;
          check = 1;
            for (wordIndex = i; isalpha(text[wordIndex]) != 0; wordIndex++) {
            for (j = 0; j < size_vowel; j++) {
                    if(text[wordIndex] == vowel[j]) {
                        vow++;
                    }
            }
            for (j = 0; j < size_consonant; j++) {
                    if(text[wordIndex] == consonants[j]) {
                        cons++;
                    }
            }
          }
          if (vow > cons) {
           count ++;
           for(j = i; j < wordIndex; j++) {
              word[row][col] = text[j];
              col++;
            }
            i += col - 1;
            word[row][col] = '\0';
            row++;
            col = 0;
          }
        }
 
        if (check == 1) {
          i = wordIndex;
        }
      }
 
       for (i = 0; i < row; i++) {
        length = strlen(word[i]);
        for (j = 0; j < length; j++) {
            putchar(word[i][j]);
        }
        if (i != row - 1) {
            printf(", ");
        }
       }
       printf("\nhere is amount of wordsthat has more vovel than consonants: %i\n", count);
 
 
    return 0;
}
