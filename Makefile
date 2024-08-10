CC = gcc # Flag for implicit rules
CFLAGS = -Wall -W -pedantic -O #-municode # Flag for implicit rules. Turn on debug info
WINFLAGS = -mwindows #-Wl,-subsystem,windows

all:
	$(CC) $(CFLAGS) win_main.c $(WINFLAGS) -o win_main.o -c
	$(CC) $(CFLAGS) grid.c -o grid.o -c
	$(CC) -o prog.exe *.o

win: 
	$(CC) $(CFLAGS) win_main.c $(WINFLAGS) -o win_main.o -c
	$(CC) -o prog.exe *.o
clean:
	rm .\prog.exe
