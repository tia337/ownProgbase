#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <pbconsole.h>
#include "function.h"
#include <stdbool.h>
#include "menu.h"
#include <string.h>
#include "assert_func.h"

int main(int argc, char * argv[]){


    struct university * univers[1000] = {NULL};
    char option;
    int key_push;
    int key_down;
    char input_country[100];
    bool run = true;
    bool nrun = true;
    bool isRunning = true;
    int i = 0;
    for (i = 0; i < argc; i++) {
      if(strcmp(argv[i], "test") == 0){
        test_delete_struct(univers);
        testfx(univers);
        conClear();
        test(univers);
        conClear();
        conMove(1, 1);
        printf("assert test() is complete!\n");
        conMove(2,1);
        new_year_tree();
        return EXIT_SUCCESS;
      }
    }
    while(isRunning==true){
        system("clear");
        fflush(stdin);
        border_row();
        menu_func2();
        option = getchar();
        clean();

        switch(option) {
            case '1':
            run = true;
            while (run == true){
            menu_func1();
            fflush(stdin);
            key_down = conGetChar();
            clean_small();
              switch(key_down){
                case '1':
                  write_string_to_struct(univers);
                break;
                case '2':
                  print_out(univers);
                break;
                case '3':
                  clean();
                  delete_from_struct(univers, input_index());
                break;
                case '4':
                  clean();
                  copy_struct(univers);
                break;
                case '5':
                  clean();
                  struct_fields_modify(univers);
                break;
                case '6':
                  clean();
                  input_country_additional(input_country);
                  country_search(univers, input_country);
                break;
                case '7':
                  clean();
                  file_process("read.txt", univers);
                break;
                case '8':
                  clean();
                  file_write(univers);
                break;
                case 'q':
                  clean();
                  run = false;
                break;
                default:
                clean();
                conMove(26,2);
                puts("try again only numbers 1 to 8");
                conMove(27,2);
                break;
              }
            }
              break;


            case '2':
            nrun = true;
            while (nrun == true){
            file_process("read.txt", univers);
            menu_func1();
            fflush(stdin);
            key_push = conGetChar();
            clean();
              switch(key_push){
                case '1':
                  clean();
                  write_string_to_struct(univers);
                break;
                case '2':
                  clean();
                  print_out(univers);
                break;
                case '3':
                  clean();
                  delete_from_struct(univers, input_index());
                break;
                case '4':
                  clean();
                  copy_struct(univers);
                break;
                case '5':
                  clean();
                  struct_fields_modify(univers);
                break;
                case '6':
                  clean();
                  input_country_additional(input_country);
                  country_search(univers, input_country);
                break;
                case '7':
                  clean();
                  file_process("read.txt", univers);
                break;
                case '8':
                  clean();
                  file_write(univers);
                break;
                case 'q':
                  nrun = false;
                break;
                default:
                  clean();
                  conMove(26,2);
                  puts("try again only numbers 1 to 8");
                  conMove(27,2);
                break;
              }
            }
                break;
            case '*':
              testfx(univers);
              conClear();
              test(univers);
              conClear();
              conMove(1, 1);
              printf("assert test() is complete!\n");
            case 'z':
                     conMove(47,2);
                     isRunning = false;
                     conClear();
                     return 0;
            default :
                     conMove(26,2);
                     puts("Try again to enter 1 or 2.");
                     break;
        }
    }

    for(int k = 0; k < 1000; k++){
      free(univers[k]);
    }
    return 0;
}
