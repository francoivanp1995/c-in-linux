#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "def.h"
#include "archivos.h"
#include "semaforos.h"

int main(int argc, char *argv[]) {
    FILE *archivo;
	char buffer[LARGO_MENSAJE];
    int id_semaforo;

    id_semaforo = creo_semaforo();
    
    while (1) {
        espera_semaforo(id_semaforo);
        printf("Interesados\n"); 

        abrirArchivo(&archivo, "propiedades.txt", "r");
        if (archivo != NULL) {
            cerrarArchivo(&archivo);
            printf("Espera entre lecturas...\n");
        } else {
            perror("Error al abrir propiedades.txt");
        }
        levanta_semaforo(id_semaforo);
        usleep(INTERVALO * 1000);
    }

    return 0;
}
