#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "def.h"
#include "archivos.h"
#include "semaforos.h"

int main(int argc, char *argv[]) {
    FILE *archivo;
    Avion avion;
	char buffer[LARGO_MENSAJE];
    int id_semaforo;

    id_semaforo = creo_semaforo();
    inicia_semaforo(id_semaforo, VERDE); 

    while (1) {
        espera_semaforo(id_semaforo);
        printf("Panel: Leyendo aviones...\n"); 

        abrirArchivo(&archivo, "panel.txt", "r");
        if (archivo != NULL) {
            file_pointer_read = archivo;

            while (leerArchivo(file_pointer_read, buffer, LARGO_MENSAJE)) {
                printf("Avion leido: %s\n", buffer);
            }
            cerrarArchivo(&archivo);
            file_pointer_read = NULL;

            printf("Espera entre lecturas...\n");
        } else {
            perror("Error al abrir panel.txt");
        }

        levanta_semaforo(id_semaforo);
        usleep(500000);
    }

    return 0;
}
