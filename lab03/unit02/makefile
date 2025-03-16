CC = gcc
CFLAGS = -Wall -pedantic-errors -std=gnu89

all: prog

prog: functions.o main.o
	$(CC) $(CFLAGS) -o prog functions.o main.o

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

main.o: main.c functions.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -rf *.o prog
