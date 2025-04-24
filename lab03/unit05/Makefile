CC = gcc
CFLAGS = -Wall -pedantic-errors -std=gnu89

all: programa

programa: key.o main.o
	$(CC) $(CFLAGS) -o programa key.o main.o

main.o: main.c key.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -rf *.o programa