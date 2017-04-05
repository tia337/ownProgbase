all:
	gcc -c -g *.c -std=c99 -Werror -Wall -pedantic-errors
	gcc *.o -o a.out -lprogbase
	rm *.o
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes ./a.out; exec /bin/bash -i'"