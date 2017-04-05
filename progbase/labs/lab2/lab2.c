#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<progbase.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<pbconsole.h>
#include<stdbool.h>

void bordergraphics();
void clean();
void menu();
void clean2();
void clean3();

int main(void) {
    /* reading the user input*/
    char option;
    /* controlling the while loop*/
    bool isRunning = true;
    bool Running_case = true;
    int A[10] = {0};
    double A_doub2[10] = {0};
    double A_doub1[10] = {0};
    double A_doub_devide[10] = {0};
    int A_two_dim[8][8] = {0};
    char string[80] = {"hi, dear user, I`m the string for task 4. Are you going to do something with me?"};
    int i = 0;
    int j = 0;
    int size_A = sizeof(A) / sizeof(A[0]);
    int size_A_doub1 = sizeof(A_doub1) / sizeof(A_doub1[0]);
    int size_A_doub2 = sizeof(A_doub2) / sizeof(A_doub2[0]);
    int size_A_doub_devide = sizeof(A_doub_devide) / sizeof(A_doub_devide[0]);
    int length_A_two_dim = 8;
    int size_string = 0;
    /*int size_A_two_dim = 64;*/
    /*int row;*/
    /*int col;*/
    int key_input = 0;
    int key_input_y = 0;
    int key_input_el = 0;
    int sum = 0;
    double sum_doub1 = 0;
    double sum_doub2 = 0;
    int multiply = 1;
    double random;
    int random_3tsk;
    int min_arr = 0;
    int index_max_arr = 0;
    int index_min_arr = 0;
    int index_min_x = 0;
    int index_min_y = 0;
    int index_max_x = 0;
    int index_max_y = 0;
    int max_arr = 0;
    double max_arr_d = 0;
    double min_arr_d = 0;
    int maxCount = 0;
    int element;
    int str_input_begin = 0;
    int str_input_end = 0;
    char character_key;
    int flag;
    int length = 0;
    int count = 0;
    int word_1 = 0;
    int word_2 = 0;
    int count_before = 0;
    int count_after = 0;
    char maininput[10];

    srand(time(0));

    bordergraphics();

    while (isRunning == true) {
        /*Clears the screen*/
        /*Clears the keyboard buffer*/
        fflush(stdin);
        /*Outputs the options to console*/
        menu();
        /*Reads the user's option*/
        option = conGetChar(); /*check*/ /*here i have changed getchar with conGetChar*/
        /*Selects the course of action specified by the option*/
        switch (option) {
        case '1':
            conMove(3, 5);
            puts("Click number from 1-8 to select option or z to go back.");
            conMove(4, 5);
            puts("1. Output random array of integers from -100 to 100.");
            conMove(5, 5);
            puts("2. Make all array of zeros.");
            conMove(6, 5);
            puts("3. Find the smallest element from array and its index.");
            conMove(7, 5);
            puts("4. Find the sum of the elements in array.");
            conMove(8, 5);
            puts("5. Output multiplication of negative elements in array.");
            conMove(9, 5);
            puts("6. Find first the most common element in array .");
            conMove(10, 5);
            puts("7. Swap the largest and the smallest element of array.");
            conMove(11, 5);
            puts("8. Increase every element in array with  input from keyboard.");
            conMove(32, 5);
            /*here commented that staff*/
            Running_case = true;
            while (Running_case == true) {
                option = conGetChar();
                switch (option) {
                case '1':
                    clean2();
                    conMove(21, 5);
                    for (i = 0; i < size_A; i++) {
                        random = rand() % 200 - 100;
                        A[i] = random;
                    }
                    for (i = 0; i < size_A; i++) {

                        printf(" %i", A[i]);

                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '2':
                    clean2();
                    conMove(21, 5);
                    for (i = 0; i < size_A; i++) {

                        A[i] = 0;
                        printf(" %i", A[i]);
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '3':
                    clean2();
                    conMove(21, 5);
                    min_arr = A[1];
                    for (i = 0; i < size_A; i++) {
                        if (A[i] < min_arr) {
                            min_arr = A[i];
                            index_min_arr = i;
                        }
                    }
                    conMove(21, 5);
                    printf("Here is the minimal element in array%i\n", min_arr);
                    conMove(22, 5);
                    printf("Here is index of minimal element in array%i\n", index_min_arr);
                    conReset();
                    conMove(32, 5);
                    break;
                case '4':
                    clean2();
                    for (i = 0; i < size_A; i++) {
                        sum = sum + A[i];
                    }
                    conMove(21, 5);
                    printf("Here is sum of elements from array:%i\n", sum);
                    conReset();
                    conMove(32, 5);
                    break;
                case '5':
                    clean2();
                    for (i = 0; i < size_A; i++) {
                        if (A[i] < 0) {
                            multiply = multiply * A[i];
                        }
                    }
                    for (i = 0; i < size_A; i++) {
                        if (A[i] == 0) {
                            multiply = 0;
                        }
                    }
                    conMove(21, 5);
                    printf("Here is multiplication of negative elements from array:%i\n", multiply);
                    conReset();
                    conMove(32, 5);
                    break;
                case '6':
                    clean2();
                    maxCount = 0;
                    element = 0;
                    for (i = 0; i < size_A; i++) {
                        count = 0;
                        for (j = 0; j < size_A; j++) {
                            if (A[i] == A[j]) {
                                count++;
                            }
                            if (maxCount < count) {
                                maxCount = count;
                                element = A[i];
                            }
                        }
                    }
                    conMove(21, 5);
                    printf("The most common element is: %i\n", element);
                    conReset();
                    conMove(32, 5);
                    break;
                case '7':
                    clean2();
                    min_arr = A[1];
                    for (i = 0; i < size_A; i++) {
                        if (A[i] < min_arr) {
                            min_arr = A[i];
                            index_min_arr = i;
                        }
                    }
                    max_arr = A[1];
                    for (i = 0; i < size_A; i++) {
                        if (A[i] > max_arr) {
                            max_arr = A[i];
                            index_max_arr = i;
                        }
                    }
                    A[index_max_arr] = min_arr;
                    A[index_min_arr] = max_arr;
                    conMove(21, 5);
                    printf("Here we have swaped the minimum and maximum elements:\n");
                    conMove(22, 5);
                    for (i = 0; i < size_A; i++) {
                        if (i == index_max_arr || i == index_min_arr) {
                            conSetAttr(FG_RED);
                            printf(" %i", A[i]);
                            conReset();
                        } else {
                            printf(" %i", A[i]);
                        }
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '8':
                    clean2();
                    conMove(21, 5);
                    printf("Type in the integer number to increase every element of  array with:\n");
                    conMove(32, 5);
                    flag = 0;
                    fgets(maininput, 10, stdin);
                    clean3();
                    for (i = 0; i < 10; i++) {
                        if (isdigit(maininput[i])) {
                            key_input = atoi(maininput);
                            flag = 1;
                        }
                    }
                    if (flag == 0) {
                        conMove(23, 5);
                        printf("Error type number");
                    }
                    conMove(22, 5);
                    for (i = 0; i < size_A; i++) {
                        A[i] = A[i] + key_input;
                        printf(" %i", A[i]);
                    }
                    conReset();
                    conMove(32, 5);

                    break;
                case 'z':
                    Running_case = false;
                    clean();
                    menu();
                    break;
                }
            }
            clean2();
            break;
        case '2':
            clean();
            conMove(3, 5);
            puts("Click number from 1-5 to select option or z to go back.");
            conMove(4, 5);
            puts("1. Output random arrays of doubles from -20 to 20.");
            conMove(5, 5);
            puts("2. Make all arrays of zeros.");
            conMove(6, 5);
            puts("3. Find the array whose each element is dividation of elements from 1 and 2 arrays.");
            conMove(7, 5);
            puts("4. Find array whose sum of elements is bigger.");
            conMove(8, 5);
            puts("5. Swap the smallest element from 1 array and the biggest from 2 array.");
            conMove(32, 5);
            conReset();
            Running_case = true;
            while (Running_case == true) {
                option = conGetChar(); /*made congetchar instead of getchar*/
                switch (option) {
                case '1':
                    clean2();
                    conMove(22, 5);
                    printf("Here are 2 arrays of random double numbers:\n");
                    srand(time(0));
                    conMove(23, 5);
                    for (i = 0; i < size_A_doub1; i++) {
                        random = -20 + rand() / (float)(RAND_MAX - 1) + rand() % 40;
                        A_doub1[i] = random;
                        printf(" %.2f", A_doub1[i]);
                    }
                    printf("\n");
                    conMove(24, 5);
                    for (i = 0; i < size_A_doub2; i++) {
                        random = -20 + rand() / (float)(RAND_MAX - 1) + rand() % 40;
                        A_doub2[i] = random;
                        printf(" %.2f", A_doub2[i]);
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '2':
                    clean2();
                    conMove(22, 4);
                    printf("Here are 2 arrays of zeroes:\n");
                    conMove(23, 4);
                    for (i = 0; i < size_A_doub1; i++) {
                        A_doub1[i] = 0;
                        printf(" %.2f", A_doub1[i]);
                    }
                    printf("\n");
                    conMove(24, 4);
                    for (i = 0; i < size_A_doub2; i++) {
                        A_doub2[i] = 0;
                        printf(" %.2f", A_doub2[i]);
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '3':
                    clean2();
                    conMove(22, 4);
                    printf("Here is an array whose each element is dividation of elements from 1 and 2 arrays:\n");
                    for (i = 0; i < size_A_doub1; i++) {

                    }
                    for (i = 0; i < size_A_doub2; i++) {

                    }
                    conMove(23, 4);
                    for (i = 0; i < size_A_doub_devide; i++) {
                        A_doub_devide[i] = A_doub1[i] / A_doub2[i];
                        printf(" %.2f", A_doub_devide[i]);
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '4':
                    clean2();
                    conMove(22, 5);
                    printf("Here we gonna find array whose sum of elements is bigger.");
                    conMove(23, 5);
                    printf("Here is an array whose sum of elements is bigger:");
                    for (i = 0; i < size_A_doub1; i++) {
                        sum_doub1 = sum_doub1 + A_doub1[i];
                    }
                    for (i = 0; i < size_A_doub2; i++) {
                        sum_doub2 = sum_doub2 + A_doub2[i];
                    }
                    if (sum_doub1 > sum_doub2) {
                        conMove(24, 5);
                        for (i = 0; i < size_A_doub1; i++) {
                            printf(" %.2f", A_doub1[i]);
                        }
                        conReset();
                        conMove(25, 5);
                        printf("it`s number is 1");
                    } else {
                        conMove(24, 5);
                        for (i = 0; i < size_A_doub1; i++) {
                            printf(" %.2f", A_doub2[i]);
                        }
                        conMove(25, 5);
                        printf("its number is 2");
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '5':
                    clean2();
                    min_arr_d = 20;
                    index_max_arr = 0;
                    index_min_arr = 0;
                    min_arr = A_doub1[0];
                    conMove(21, 5);
                    printf("Here we swaped the smallest element from 1 array and the biggest from 2 array:\n");
                    for (i = 0; i < size_A_doub1; i++) {
                        if (A_doub1[i] < min_arr_d) {
                            min_arr_d = A_doub1[i];
                            index_min_arr = i;
                        }
                    }
                    max_arr_d = -20;
                    for (i = 0; i < size_A_doub2; i++) {
                        if (max_arr_d < A_doub2[i]) {
                            max_arr_d = A_doub2[i];
                            index_max_arr = i;
                        }
                    }
                    A_doub2[index_max_arr] = min_arr_d;
                    A_doub1[index_min_arr] = max_arr_d;
                    conMove(22, 5);
                    for (i = 0; i < size_A_doub1; i++) {
                        printf(" %.2f", A_doub1[i]);
                    }
                    clean2();

                    conMove(21, 5);

                    for (i = 0; i < size_A_doub2; i++) {
                        if (i == index_max_arr) {
                            conSetAttr(FG_RED);
                            printf(" %.2f", A_doub2[i]);
                            conReset();
                        } else {
                            printf(" %.2f", A_doub2[i]);
                        }
                    }
                    conMove(22, 5);
                    for (i = 0; i < size_A_doub1; i++) {
                        if (i == index_min_arr) {
                            conSetAttr(FG_RED);
                            printf(" %.2f", A_doub1[i]);
                            conReset();
                        } else {
                            printf(" %.2f", A_doub1[i]);
                        }
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case 'z':
                    Running_case = false;
                    clean();
                    menu();
                    break;
                }
            }
            clean2();
            break;
        case '3':
            conMove(3, 5);
            puts("Click number from 1-8 to select option or z to go back.");
            conMove(4, 5);
            puts("1. Output random 2 dimensional array of integers from -8 to 8.");
            conMove(5, 5);
            puts("2. Make all array of zeros.");
            conMove(6, 5);
            puts("3. Find the biggest element from array and its index.");
            conMove(7, 5);
            puts("4. Find the sum of the elements in pobichna diagonal.");
            conMove(8, 5);
            puts("5. Find the sum of the elements in chosen column (you have to choose).");
            conMove(9, 5);
            puts("6. Find the biggest element in array.");
            conMove(10, 5);
            puts("7. Swap the largest and the smallest element of array.");
            conMove(11, 5);
            puts("8. Change the element with inputed cordinates with inputed from keyboard.");
            conMove(32, 5);
            conReset();
            /*option = getchar();*/
            /*removed option = getchar()*/
            Running_case = true;
            while (Running_case == true) {
                option = conGetChar(); /*made congetchar instead of getchar*/
                switch (option) {
                case '1':
                    clean2();
                    srand(time(0));
                    for (i = 0; i < length_A_two_dim; i++) { 
                        conMove(21 + i, 5);
                        for (j = 0; j < length_A_two_dim; j++) {
                            random_3tsk = rand() % 20 - 10;
                            A_two_dim[i][j] = random_3tsk;
                            printf(" %*i", 3, A_two_dim[i][j]);
                        }
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '2':
                    clean2();
                    for (i = 0; i < length_A_two_dim; i++) {
                        conMove(21 + i, 5);
                        for (j = 0; j < length_A_two_dim; j++) {
                            A_two_dim[i][j] = 0;
                            printf(" %*i", 3, A_two_dim[i][j]);
                        }
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '3':
                    clean2();
                    max_arr = 0;
                    index_max_arr = 0;
                    index_min_arr = 0;
                    max_arr = A_two_dim[0][0];
                    for (i = 0; i < length_A_two_dim; i++) {
                        for (j = 0; j < length_A_two_dim; j++) {
                            if (max_arr < A_two_dim[i][j]) {
                                max_arr = A_two_dim[i][j];
                                index_max_arr = i;
                                index_min_arr = j;
                            }
                        }
                    }
                    conMove(21, 5);
                    printf("here is the maximal element in array %i", max_arr);
                    conMove(22, 5);
                    printf("here is index of minimal element in array(x and y cordinates): %i %i", index_min_arr, index_max_arr);
                    conReset();
                    conMove(32, 5);
                    break;
                case '4':
                    clean2();
                    sum = 0;
                    for (i = 0, j = 0; i < length_A_two_dim && j < length_A_two_dim; i++, j++) {
                        sum += A_two_dim[j][length_A_two_dim - 1 - i];
                    }
                    conMove(21, 5);
                    printf("Here is sum of pobichna diagonal:%i\n", sum);
                    conReset();
                    conMove(32, 5);
                    break;
                case '5':
                    clean2();
                    key_input = 0;
                    sum = 0;
                    conMove(32, 5);
                    printf("Enter number of row sum of which you wanna count\n");
                    conMove(33, 5);
                    flag = 0;
                    fgets(maininput, 10, stdin);
                    clean3();
                    for (i = 0; i < 10; i++) {
                        if (isdigit(maininput[i])) {
                            key_input = atoi(maininput);

                            if (key_input < 8) {
                                flag = 1;
                                for (j = 0; j < length_A_two_dim; j++) {
                                    sum += A_two_dim[j][key_input];
                                }
                                conMove(21, 5);
                                printf("Here is sum of chosen column:%i\n", sum);
                                conReset();
                                conMove(32, 5);
                            }
                        }
                    }
                    if (flag == 0) {
                        conMove(23, 5);
                        printf("Error type number");
                    }
                    /*scanf("%i", &key_input);*/
                    /*for(j = 0; j < length_A_two_dim; j++){
									sum += A_two_dim[j][key_input];
								}
								conMove(21, 5);
								printf("Here is sum of chosen column:%i\n", sum);
								conReset();
							    conMove(32, 5);*/
                    break;
                case '6':
                    clean2();
                    max_arr = -10;
                    conMove(32, 5);
                    printf("Here we gonna find the biggest element in array\n");
                    A_two_dim[0][0] = max_arr;
                    clean2();
                    for (i = 0; i < length_A_two_dim; i++) {
                        for (j = 0; j < length_A_two_dim; j++) {
                            if (A_two_dim[i][j] > max_arr) {
                                max_arr = A_two_dim[i][j];
                            }
                        }
                    }
                    conMove(21, 5);
                    printf("The biggest element is: %i", max_arr);
                    conReset();
                    conMove(32, 5);
                    break;
                case '7':
                    clean2();
                    conMove(20, 5);
                    printf("Swap the biggest and the smallest elements:%i\n", multiply);
                    max_arr = -10;
                    for (i = 0; i < 8; i++) {
                        conMove(21 + i, 5);
                        clean2();
                        for (j = 0; j < 8; j++) {
                            if (A_two_dim[i][j] > max_arr) {
                                max_arr = A_two_dim[i][j];
                                index_max_x = i;
                                index_max_y = j;
                            }
                        }
                    }
                    min_arr = 10;
                    for (i = 0; i < 8; i++) {
                        for (j = 0; j < 8; j++) {
                            if (A_two_dim[i][j] < min_arr) {
                                min_arr = A_two_dim[i][j];
                                index_min_x = i;
                                index_min_y = j;
                            }
                        }
                    }
                    A_two_dim[index_min_x][index_min_y] = max_arr;
                    A_two_dim[index_max_x][index_max_y] = min_arr;
                    for (i = 0; i < length_A_two_dim; i++) {
                        conMove(21 + i, 5);
                        for (j = 0; j < length_A_two_dim; j++) {
                            if ((i == index_max_x || j == index_max_y) && (i == index_min_x || j == index_min_y)) {
                                conSetAttr(FG_RED);
                                printf(" %*i", 3, A_two_dim[i][j]);
                                conReset();
                            } else {
                                printf(" %*i", 3, A_two_dim[i][j]);
                            }
                        }
                        printf("\n");
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case '8':
                    clean2();
                    conMove(21, 5);
                    printf("Type in cordinates (x then y) of element that you wanna change and value of new one\n");
                    conMove(32, 5);
                    flag = 0;
                    fgets(maininput, 10, stdin);
                    clean3();
                    for (i = 0; i < 10; i++) {
                        if (isdigit(maininput[i])) {
                            key_input = atoi(maininput);
                            flag = 1;
                        }
                    }
                    if (flag == 0) {
                        conMove(23, 5);
                        printf("Error (you`ve entered not a number) press any key from 1-8");
                         break;
                    }                   
                    /*scanf("%i", &key_input);*/
                    conMove(33, 5);
                    flag = 0;
                    fgets(maininput, 10, stdin);
                    clean3();
                    for (i = 0; i < 10; i++) {
                        if (isdigit(maininput[i])) {
                            key_input_y = atoi(maininput);
                            flag = 1;
                        }
                    }
                    if (flag == 0) {
                        conMove(23, 5);
                        printf("Error (you`ve entered not a number) press any key from 1-8");
                    }
                    /*scanf("%i", &key_input_y);*/
                    conMove(34, 5);
                    flag = 0;
                    fgets(maininput, 10, stdin);
                    clean3();
                    for (i = 0; i < 10; i++) {
                        if (isdigit(maininput[i])) {
                            key_input_el = atoi(maininput);
                            flag = 1;
                        }
                    }
                    if (flag == 0) {
                        conMove(23, 5);
                        printf("Error (you`ve entered not a number) press any key from 1-8");
                    }
                    /*scanf("%i", &key_input_el);*/
                    conMove(22, 5);
                    clean2();
                    for (i = 0; i < length_A_two_dim; i++) {
                        conMove(21 + i, 5);
                        for (j = 0; j < length_A_two_dim; j++) {
                            A_two_dim[key_input][key_input_y] = key_input_el;
                            if(key_input == i && key_input_y == j){
                            	conSetAttr(FG_RED);
                            	printf(" %*i", 3, A_two_dim[i][j]);
                            	conReset();
                            }
                            else{
                            	 printf(" %*i", 3, A_two_dim[i][j]);
                            }
                        }
                        printf("\n");
                    }
                    conReset();
                    conMove(32, 5);
                    break;
                case 'z':
                    Running_case = false;
                    clean();
                    menu();
                    break;
                }
            }
            clean2();
            break;
        case '4':
            clean();
            conMove(3, 5);
            puts("Click number from 1-8 to select option or z to go back.");
            conMove(4, 5);
            puts("1. Type in 80 characters.");
            conMove(5, 5);
            puts("2. Make the string empty.");
            conMove(6, 5);
            puts("3. Output string length.");
            conMove(7, 5);
            puts("4. Here we output string from start position and string length.");
            conMove(8, 5);
            puts("5. Here we output string pieces devided by inputed character.");
            conMove(9, 5);
            puts("6. Output the longest word in the string.");
            conMove(10, 5);
            puts("7. Output all double values from the string.");
            conMove(11, 5);
            puts("8. Output multiplication of integers from the string.");
            conMove(32, 5);
            conReset();
            Running_case = true;
            while (Running_case == true) {
                option = conGetChar();
                switch (option) {
                case '1':
                    clean2();
                    conMove(21, 5);
                    printf("Type in 80 characters:\n");
                    conMove(32, 5);
                    fgets(string, 82, stdin);
                    clean2();
                    conMove(21, 5);
                    printf("here is your string:");
                    conMove(22, 5);
                    puts(string);
                    clean3();
                    conReset();
                    conMove(32, 5);
                    break;
                case '2':
                    clean2();
                    conMove(21, 5);
                    printf("Here we make our string empty:\n");
                    strcpy(string, " ");
                    conMove(32, 5);
                    puts(string);
                    clean3();
                    conReset();
                    conMove(32, 5);
                    break;
                case '3':
                    clean2();
                    conMove(21, 5);
                    printf("Here we output the string length.\n");
                    size_string = strlen(string) - 1;
                    conMove(22, 5);
                    printf("String length is: %i\n", size_string);
                    clean3();
                    conReset();
                    conMove(32, 5);
                    break;
                case '4':
                    clean2();
                    i = 0;
                    conMove(21, 5);
                    printf("Type in start position of string and its length.\n");
                    conMove(32, 5);
                    flag = 0;
                    fgets(maininput, 10, stdin);
                    clean3();
                    clean2();
                    for (i = 0; i < 10; i++) {
                        if (isdigit(maininput[i])) {
                            str_input_begin = atoi(maininput);
                            flag = 1;
                        }
                    }
                    if (flag == 0) {
                        conMove(23, 5);
                        printf("Error type number");
                    }
                    /*scanf("%i", &str_input_begin);*/
                    conMove(32, 5);
                    flag = 0;
                    fgets(maininput, 10, stdin);
                    clean3();
                    clean2();
                    for (i = 0; i < 10; i++) {
                        if (isdigit(maininput[i])) {
                            str_input_end = atoi(maininput);
                            flag = 1;
                        }
                    }
                    if (flag == 0) {
                        conMove(23, 5);
                        printf("Error type number");
                    }
                    /*scanf("%i", &str_input_end);*/
                    conMove(21, 5);
                    printf("Here is your string:\n");
                    conMove(22, 5);
                    for (i = str_input_begin; i < str_input_end; i++) {
                        printf("%c", string[i]);
                    }
                    clean3();
                    conReset();
                    conMove(32, 5);
                    break;
                case '5':
                    clean2();
                    conMove(21, 5);
                    printf("Type in word which will devide string in pieces.\n");
                    conMove(32, 5);
                    character_key = getchar();
                    clean2();
                    for (i = 0 , j =0; i < strlen(string);j ++, i++) {
                        if (character_key != string[i]) {
                       	 conMove(22, 5+j);
                            printf("%c", string[i]);
                        } 
                        else {
                        j= j+2;
                        printf("\t");
                        }
                    }
                    clean3();
                    conReset();
                    conMove(32, 5);
                    break;
                case '6':
                    clean2();
                    conMove(21, 5);
                    printf("Here we gonna output the longest word.\n");
                    conMove(22, 5);
                    printf("The longest word is:\n");
                    for (i = 0; i < strlen(string); i++) {
                        if (isalpha(string[i])) {
                            word_1++;
                        } else {
                            if (word_2 < word_1) {
                                word_2 = word_1;
                                count = i - word_1;
                                word_2 += count;
                            }
                            word_1 = 0;
                        }
                    }
                    conMove(23, 5);
                    for (i = count; i < word_2; i++) {
                        printf("%c", string[i]);
                    }
                    clean3();
                    conReset();
                    conMove(32, 5);
                    break;
                case '7':
                    clean2();
                    conMove(21, 5);
                    printf("Here we gonna output all double values from the string.\n");
                    for (i = 0; i < strlen(string); i++) {
                        if (isdigit(string[i]) != 0 && string[i + 1] == '.' && isdigit(string[i + 2]) != 0) {
                            count_before = i;
                            count_after = i + 2;
                            while (isdigit(string[count_before - 1]) != 0) {
                                count_before--;
                            }
                            conMove(22, 5);
                            if (string[count_before - 1] == '-') {
                                printf("-");
                            }
                            while (isdigit(string[count_after]) != 0) {
                                count_after++;
                            }
                            conMove(32, 6);
                            for (i = count_before; i < count_after; i++) {
                                printf("%c", string[i]);
                            }
                            printf(" ");
                        }
                    }
                    clean3();
                    conReset();
                    conMove(32, 5);
                    break;
                case '8':
                    clean2();
                    conMove(21, 5); 
                    printf("Here we gonna output multiplication of integers from the string.");
                    flag = 0;
                    multiply = 1;
                    length = strlen(string);
                    for (i = 0; i < length; i++) {
                        char ch = string[i];
                        char nextCh = string[i + 1];
                        
                        if (isdigit(ch) || (ch == '-' && isdigit(nextCh))) {
                            flag = 1;
                            count = printf("%i", atoi(string + i));
                            printf(" ");
                            multiply *= atoi(string + i);
                            i += count - 1;
                        }
                    }
                    
                    if (flag == 0) {
                    clean2();
                    conMove(22, 5);
                        printf("there is no numbers iin the string!");
                    }
                    else{
		                clean2();
		                conMove(21, 5);
		                printf("Here is multiply %i\n", multiply);
		                clean3();
		                conReset();
		                conMove(32, 5);
                    }
                    break;
                case 'z':
                    Running_case = false;
                    clean();
                    menu();
                    break;
                }
            }
            break;

        case 'q':
            /*Exits the system*/
            isRunning = false;
            return 0;
        default:
            conMove(21, 5);
            printf("Hehehe, type in a number)");
            conReset();
            break;
        }
    }
    return 0;
}

void bordergraphics() {

    int col = 0;
    int row = 0;
    conClear();
    conSetAttr(BG_WHITE);
    for (col = 0; col < 90; col++) {
        conMove(1, col);
        printf(" ");

        conMove(19, col);
        printf(" ");

        conMove(30, col);
        printf(" ");

        conMove(45, col);
        printf(" ");

    }
    for (row = 0; row < 45; row++) {
        conMove(row, 1);
        printf(" ");
    }
    for (row = 0; row < 46; row++) {
        conMove(row, 90);
        printf(" ");
    }
    conReset();
}

void clean() {
    int x = 0;
    int y = 0;
    for (x = 3; x < 89; x++) {
        for (y = 2; y < 19; y++) {
            conMove(y, x);
            puts(" ");
        }

    }
}

void clean2() {
    int x = 0;
    int y = 0;
    for (x = 3; x < 90; x++) {
        for (y = 20; y < 30; y++) {
            conMove(y, x);
            puts(" ");
        }

    }
}

void clean3() {
    int x = 0;
    int y = 0;
    for (x = 3; x < 90; x++) {
        for (y = 31; y < 45; y++) {
            conMove(y, x);
            puts(" ");
        }

    }
}

void menu() {
    conMove(3, 5);
    puts("Click [1] to select task 1.");
    conMove(4, 5);
    puts("Click [2] to select task 2.");
    conMove(5, 5);
    puts("Click [3] to select task 3.");
    conMove(6, 5);
    puts("Click [4] to select task 4.");
    conMove(7, 5);
    puts("Click [q]to exit");
    conMove(32, 5);
    conReset();

}
