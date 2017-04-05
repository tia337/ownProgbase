#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char output_common(const char * str);

int main(void) {
    char str[100];
    char symbol;
    printf("PLease, enter a string: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    printf("You've entered: %s\n", str);

    /* call recursive function and print it's result*/
    symbol = output_common(str);
    printf("\nTask: output the first char that we meet more than 1 time successively, else 0 in console : %c\n\n", symbol);

    return EXIT_SUCCESS;
}

char output_common(const char * str) {
    char symbol = str[0];
    if (symbol == '\0') {
        return '0';
    } else if (strchr(str + 1, symbol) == strchr(str + 2, symbol)) {
        return output_common(str + 1);
    } else {
        return symbol;
    }
}
