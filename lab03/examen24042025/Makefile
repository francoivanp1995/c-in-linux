CC = gcc-4.1
CFLAGS = -Wall -pedantic-errors -std=gnu89

all: empresa interesados

empresa: empresa.o semaforos.o key.o archivos.o functions.o
	$(CC) $(CFLAGS) empresa.o semaforos.o key.o archivos.o functions.o -o empresa

empresa.o: empresa.c functions.h def.h semaforos.h archivos.h
	$(CC) $(CFLAGS) -c empresa.c -o empresa.o

interesados: interesados.o semaforos.o key.o archivos.o functions.o
	$(CC) $(CFLAGS) interesados.o semaforos.o key.o archivos.o functions.o -o interesados

interesados.o: interesados.c semaforos.h def.h archivos.h
	$(CC) $(CFLAGS) -c interesados.c -o interesados.o

semaforos.o: semaforos.c semaforos.h key.h
	$(CC) $(CFLAGS) -c semaforos.c -o semaforos.o

key.o: key.c key.h
	$(CC) $(CFLAGS) -c key.c -o key.o

archivos.o: archivos.c archivos.h
	$(CC) $(CFLAGS) -c archivos.c -o archivos.o

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c -o functions.o

clean:
	rm -rf *.o propiedades.txt empresa interesados
