#include <stdio.h>
#include <progbase.h>
#include <pbconsole.h>


  void border_row(){
    int row = 0;
    int col = 0;
    conClear();
    conSetAttr(BG_WHITE);
    for (row = 0; row < 120; row++) {
      conMove(1, row);
      puts(" ");
      conMove(25, row);
      puts(" ");
      conMove(45, row);
      puts(" ");
    }
    for(col = 0; col < 46; col++){
      conMove(col, 1);
      puts(" ");
      conMove(col, 120);
      puts(" ");
    }

    conMove(1, 50);
    conSetAttr(FG_BLACK);
    puts("Welcome to Ilya`s Program");
    conReset();

  }

  void menu_func1(){
    conMove(2,2);
    puts("1.Press the [1] in order to write string to struct.");
    conMove(3,2);
    puts("2.Press the [2] in order to write struct to string and output it.");
    conMove(4,2);
    puts("3.Press the [3] in order to delete struct.");
    conMove(5,2);
    puts("4.Press the [4] in order to change data between the structs (by index).");
    conMove(6,2);
    puts("5.Press the [5] in order to change data in chosen struct and field.");
    conMove(7,2);
    puts("6.Press the [6] in order to find university of entered country.");
    conMove(8,2);
    puts("7.Press the [7] in order to read from file.");
    conMove(9,2);
    puts("8.Press the [8] in order to write to file.");
    conMove(10,2);
    puts("8.Press the [q] in order to to escape to main menu.");
    conMove(26,2);
  }

  void menu_func2(){
    conMove(2,2);
      puts("1.Press the [1] to fill the struct manually.");
    conMove(3,2);
      puts("2.Press the [2] to read data for the struct from file.");
    conMove(4,2);
      puts("3.Press [z] to quit the programm.");
    conMove(5,2);
      puts("$Press [*] to run assert.$");
    conMove(26,2);
  }

  void clean() {
    int x = 0;
    int y = 0;
    for (x = 26; x < 45; x++) {
      for (y = 2; y < 120; y++) {
        conMove(x, y);
        puts(" ");
      }
    }
  }

  void clean_small(){
    int x = 0;
    int y = 0;
    for (x = 27; x < 45; x++) {
      for (y = 2; y < 120; y++) {
        conMove(x, y);
        puts(" ");
      }
    }
  }
