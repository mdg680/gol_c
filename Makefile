CC = gcc # Flag for implicit rules
CFLAGS = -g # Flag for implicit rules. Turn on debug info

all:
	gcc main.c -o main.o -c
	gcc grid.c -o grid.o -c
	gcc -o prog *.o

clean:
	rm -r *.o prog