CC = gcc
CFLAGS = -Wall -pedantic-errors -std=gnu89

all: programa

programa: functions.o main.o archivos.o
	$(CC) $(CFLAGS) -o programa functions.o main.o archivos.o

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

main.o: main.c functions.h archivos.h
	$(CC) $(CFLAGS) -c main.c

global.o: global.c global.h
	$(CC) $(CFLAGS) -c global.c

archivos.o: archivos.c archivos.h
	$(CC) $(CFLAGS) -c archivos.c

clean:
	rm -rf *o programa
