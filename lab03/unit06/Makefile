CC = gcc
CFLAGS = -Wall -pedantic-errors -std=gnu89

all: productor consumidor

productor: productor.o semaforos.o key.o archivos.o functions.o
	$(CC) $(CFLAGS) productor.o semaforos.o key.o archivos.o functions.o -o productor

productor.o: productor.c functions.h def.h semaforos.h archivos.h
	$(CC) $(CFLAGS) -c productor.c -o productor.o

consumidor: consumidor.o semaforos.o key.o archivos.o functions.o
	$(CC) $(CFLAGS) consumidor.o semaforos.o key.o archivos.o functions.o -o consumidor

consumidor.o: def.h archivos.h
	$(CC) $(CFLAGS) -c consumidor.c -o consumidor.o

semaforos.o: semaforos.c semaforos.h key.h
	$(CC) $(CFLAGS) -c semaforos.c -o semaforos.o

key.o: key.c key.h
	$(CC) $(CFLAGS) -c key.c -o key.o

archivos.o: archivos.c archivos.h
	$(CC) $(CFLAGS) -c archivos.c -o archivos.o

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c -o functions.o

clean:
	rm -rf *.o productor consumidor menues.txt