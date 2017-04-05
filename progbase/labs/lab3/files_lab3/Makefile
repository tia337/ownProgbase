# Makefile for LAB_3 project

LAB_3: main.o function.o menu.o assert_func.o
	gcc -o LAB_3 main.o function.o menu.o assert_func.o -lprogbase

main.o: main.c
	gcc -c main.c

function.o: function.c
	gcc -c function.c

menu.o: menu.c
	gcc -c menu.c

assert_func.o: assert_func.c
	gcc -c assert_func.c

clean:
	rm -f *.o LAB_3
