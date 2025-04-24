CC = gcc
CFLAGS = -Wall -pedantic-errors -std=gnu89

all: avion panel

avion: avion.o semaforos.o key.o archivos.o functions.o
	$(CC) $(CFLAGS) avion.o semaforos.o key.o archivos.o functions.o -o avion

avion.o: avion.c functions.h def.h semaforos.h archivos.h
	$(CC) $(CFLAGS) -c avion.c -o avion.o

panel: panel.o semaforos.o archivos.o key.o
	$(CC) $(CFLAGS) panel.o semaforos.o archivos.o key.o -o panel

panel.o: panel.c semaforos.h def.h archivos.h
	$(CC) $(CFLAGS) -c panel.c -o panel.o

semaforos.o: semaforos.c semaforos.h key.h
	$(CC) $(CFLAGS) -c semaforos.c -o semaforos.o

key.o: key.c key.h
	$(CC) $(CFLAGS) -c key.c -o key.o

archivos.o: archivos.c archivos.h
	$(CC) $(CFLAGS) -c archivos.c -o archivos.o

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c -o functions.o

clean:
	rm -rf *.o panel.txt avion panel
