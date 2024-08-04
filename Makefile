CC = gcc # Flag for implicit rules
CFLAGS = -Wall -W -pedantic -O # Flag for implicit rules. Turn on debug info

all:
	$(CC) $(CFLAGS) main.c -o main.o -c
	$(CC) $(CFLAGS) grid.c -o grid.o -c
	$(CC) -o prog.out *.o
	rm -r *.o

clean:
	rm -r *.o prog.out