#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pbconsole.h>
#include <ctype.h>
#include <string.h>
#include "function.h"
#include "menu.h"
#define VAR 1000

  char scan_str(char *str) {
    fgets(str, 200, stdin);
    return *str;
  }

  char scan_str_for5(char *str) {
    scanf("%s",str);
    return *str;
  }

  int file_pointer_for_fw(){
    char file_out[30];
    conMove(26,2);
    printf("Enter name of file where you wanna write the struct");
    conMove(27,2);
    scanf("%s", file_out);
    clean();
    return *file_out;
  }

  int file_write(struct university * ptr[]){
    char file_out[100];
    conMove(26,2);
    printf("Enter name of file where you wanna write the struct");
    conMove(27,2);
    scanf("%s", file_out);
    clean();
    conMove(26,2);
    char *write = file_out;
    FILE *fout = fopen(write, "w");
    if (file_out == NULL ){
  		  puts("ERROR, NO FILE");
  		    return 1;
      }
    for(int i = 0; i < VAR; i++){
      if(ptr[i] != NULL){
        fprintf(fout,"Full name: %s, Location: %s, Success level: %f, Rank: %i, Students:%i, Matan p: %i\n", ptr[i]->full_name, ptr[i]->location, ptr[i]->success_level, ptr[i]->rank, ptr[i]->more_data.students, ptr[i]->more_data.matan_points);
      }
    }

  		fclose(fout);
  		return 0;
  }

  int file_process(const char *file_in, struct university * ptr[]){
    enum{BUFFER_SIZE = 100};
		char buffer[BUFFER_SIZE];
    int i = 0;
		FILE *fin = fopen(file_in, "r");
		if (fin == NULL ){
      conMove(27,2);
			return 1;
		}
		while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
			buffer[strlen(buffer) - 1] = '\0';
      for(i = 0; i < VAR; i++){
        if(ptr[i] == NULL){
          ptr[i] = (struct university*)malloc(sizeof(struct university));
          break;
        }
      }
      sscanf(buffer,"%s %s %3f %i %i %i",ptr[i]->full_name, ptr[i]->location, &ptr[i]->success_level, &ptr[i]->rank, &ptr[i]->more_data.students, &ptr[i]->more_data.matan_points);
  	}
		fclose(fin);
		return 0;
  }

  void write_string_to_struct(struct university * ptr[]) {
    char buffer[200];
    int i;
    char key = '1';
    for (i = 0; i < VAR; i++){
      if(ptr[i] == NULL){
        while(key == '1'){
          conMove(27,2);
          scan_str(buffer);
          ptr[i] = (struct university*)malloc(sizeof(struct university));
          sscanf(buffer,"%s %s %3f %i %i %i",ptr[i]->full_name, ptr[i]->location, &ptr[i]->success_level, &ptr[i]->rank, &ptr[i]->more_data.students, &ptr[i]->more_data.matan_points);
          conMove(26,2);
          printf("Type in 1 to continue writing or 'z' to stop entering anything\n");
          clean_small();
          conMove(27,2);
          key = conGetChar();
            if( key == 'z' ){
              clean();
              break;
            }
            else if( key != '1'){
              clean();
              conMove(26,2);
              puts("Type in only 1 or z, cat cries.");
              conMove(26,2);
            }
        }
          break;
      }
    }
  }

  void print_out(struct university * ptr[]) {
    int i = 0;
    int k = 0;
    char key = 1;
    while(key != '1'){
      for(i = 0; i < VAR; i++){
        if(ptr[i] != NULL){
          conMove(26 + k, 2);
          printf("Full name: %s, Location: %s, Success level: %f, Rank: %i, Students:%i, Matan p: %i", ptr[i]->full_name, ptr[i]->location, ptr[i]->success_level, ptr[i]->rank, ptr[i]->more_data.students, ptr[i]->more_data.matan_points);
          conMove(27 + k,2);
          puts("press z to exit this function");
          conMove(28 + k,2);
          k++;
          key = conGetChar();
          if(key == 'z'){
            clean();
            break;
          }
          else if( key != '2'){
            clean();
            conMove(26,2);
            puts("Type in only 1 or z, cat cries.");
            conMove(27,2);
          }
        }
      }
      break;
    }
  }

  int input_index (){
    int input;
    bool is_out = true;
    while (is_out == true){
      conMove(26,2);
      printf("Type in index of a struct to delete.\n");
      conMove(27,2);
      scanf("%i", &input);
      clean_small();
      conMove(26,2);
      printf("If you wanna delete more structs press 1, to stop press 2.\n");
      conMove(27,2);
      int quit = conGetChar();
      if(quit != 1){
        clean();
          break;
      }
    }
    return input;
  }

  struct university * delete_from_struct(struct university * ptr[], int input){
    struct university * pntr = ptr[input];
    ptr[input] = NULL;
    return pntr;
    free(ptr[input]);
  }

  void copy_struct(struct university * ptr[]){
    bool is_out = true;
    int input;
    int output;
    while (is_out == true){
      clean();
      conMove(26,2);
      printf("Type in index of a struct to scan data from.\n");
      conMove(27,2);
      scanf("%i", &input);
      clean();
      conMove(26,2);
      printf("Type in  index of a struct to input data in.\n");
      conMove(27,2);
      scanf("%i", &output);
      clean_small();
      if(ptr[input] == NULL){
        clean();
        conMove(29,45);
        printf("There is no such struct!\n");
        conMove(27,2);
      }
      if(ptr[output] == NULL){
        ptr[input] = (struct university*)malloc(sizeof(struct university));
      }
      strcpy(ptr[input]->location, ptr[output]->location);
      strcpy(ptr[input]->full_name, ptr[output]->full_name);
      ptr[input]->success_level = ptr[output]->success_level;
      ptr[input]->rank = ptr[output]->rank;
      ptr[input]->more_data.students = ptr[output]->more_data.students;
      ptr[input]->more_data.matan_points = ptr[output]->more_data.matan_points;
      conMove(26,2);
      printf("If you wanna continue press 1, to stop press 2.\n");
      conMove(27,2);
      int quit = conGetChar();
        if(quit != 1){
          clean();
          break;
        }
    }
  }

  void struct_fields_modify(struct university * ptr[]){
    bool is_out = true;
    int struct_n = 0;
    int option;
    char buffer[200];
    float success_level;
    int rank;
    int students;
    int matan_points;

    conMove(26,2);
    printf("type in number of struct you wanna modify\n");
    conMove(27,2);
    scanf("%i", &struct_n);
    clean_small();
    if(ptr[struct_n] == NULL && isdigit(struct_n)){
      ptr[struct_n] = (struct university*)malloc(sizeof(struct university));
    }
        is_out = true;
      while (is_out == true){
          clean();
          conMove(26,2);
          puts("Type in number of field you wanna change from 1-6 or e to exit");
          conMove(27,2);
          option = conGetChar();
          switch (option) {
            case '1':
            clean();
            conMove(26,2);
            puts("Type in university`s abreviation");
            conMove(27,2);
              scan_str_for5(buffer);
              sscanf(buffer,"%s",ptr[struct_n]->full_name);
              clean();
            break;
            case '2':
            clean();
            conMove(26,2);
            puts("Type in university`s location");
            conMove(27,2);
              scan_str_for5(buffer);
              sscanf(buffer,"%s",ptr[struct_n]->location);
              clean();
            break;
            case '3':
            clean();
            conMove(26,2);
            puts("Type in university`s success level");
            conMove(27,2);
              scanf("%f", &success_level);
              if(isalpha(success_level) !=0 && ispunct(success_level) != 0){
                conMove(27,2);
                puts("It has to be a number");
              }
              else{
                ptr[struct_n]->success_level = success_level;
                clean();
              }
            break;
            case '4':
            clean();
            conMove(26,2);
            puts("Type in university`s rank");
            conMove(27,2);
              scanf("%i", &rank);
              if(isalpha(rank) !=0 && ispunct(rank) != 0){
                conMove(27,2);
                puts("It has to be a number");
                conMove(28,2);
              }
              else{
                ptr[struct_n]->rank = rank;
                clean();
              }
            break;
            case '5':
            clean();
            conMove(26,2);
            puts("Type in number of students");
            conMove(27,2);
              scanf("%i", &students);
              if(isalpha(students) !=0 && ispunct(students) != 0){
                conMove(27,2);
                puts("It has to be a number");

              }
              else{
                ptr[struct_n]->more_data.students = students;
                clean();
              }
            break;
            case '6':
            clean();
            conMove(26,2);
            puts("Type in students` matan points");
            conMove(27,2);
              scanf("%i", &matan_points);
              if(isalpha(matan_points) !=0 && ispunct(matan_points) != 0){
                conMove(27,2);
                puts("It has to be a number");

              }
              else{
                ptr[struct_n]->more_data.matan_points = matan_points;
                clean();
              }
            break;
            default:
            conMove(29,45);
              puts("There is no field with such number");
            break;
            case 'e':
              is_out = false;
              clean();
            break;
          }
          break;
        }
    }

  char * input_country_additional(char input_country[]){
    conMove(26,2);
    puts("Type in a country university of which you wanna find.");
    conMove(27,2);
    fgets(input_country, 100, stdin);
    scanf("%s", input_country);
    clean();
    return input_country;
  }

  int country_search(struct university * ptr[], char input_country[]){
    int flag = 0;
    for (int i = 0; i < VAR; i++){
      if(ptr[i] != NULL){
        if(strcmp(input_country, ptr[i]->location) == 0){
          conMove(26 + i,2);
          printf("Full name: %s, Location: %s, Success level: %f, Rank: %i, Students:%i, Matan p: %i", ptr[i]->full_name, ptr[i]->location, ptr[i]->success_level, ptr[i]->rank, ptr[i]->more_data.students, ptr[i]->more_data.matan_points);
          flag = 1;
        }
      }
    }
    if (flag == 0) {
      conMove(30, 2);
      puts("There is no universities from such country.");
    }
    return 0;
  }

  void new_year_tree(){
     int level;
     int levelcount = 5;
     int layercount = 5;
     int layer;
     int star;
     int starcount;
     int spacecount;
     int space;
     int length;
     printf("\n Chrismas Tree \n");
     conSetAttr(FG_RED);
     length = (layercount*levelcount);
     starcount = 1;
     spacecount = length;
     for (layer = 1 ; layer <= layercount ; layer++) {
         for (level = 1 ; level <= levelcount ; level++) {
             for (space = 1 ; space <= spacecount ; space++)
                 printf(" ");
             for (star = 1 ; star <= starcount ; star++)
                 printf("*");
             printf("\n");
             starcount += 2;
             spacecount--;
         }
         starcount -= 2;
         spacecount++;
         if(levelcount <= 3){
             starcount -= 2;
             spacecount += 1;
         }
         else{
             starcount -= 4;
             spacecount += 2;
         }
     }
     spacecount = length;
     for (layer = 1 ; layer <= 4; layer++) {
             for (space = 1 ; space <= spacecount-1 ; space++)
                 printf(" ");
             for (star = 1 ; star <= 3 ; star++)
                 printf("#");
             printf("\n");
     }
  };
