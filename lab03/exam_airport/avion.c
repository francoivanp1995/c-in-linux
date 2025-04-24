#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include "semaforos.h"
#include "archivos.h"
#include "functions.h"
#include "def.h"

int main(int argc, char *argv[])
{
    FILE *archivo;
    Avion avion;
	int id_semaforo;
	int nro_avion = atoi(argv[1]);
    if (!validar_parametros(argc, argv, &nro_avion)) {
        return EXIT_FAILURE;
    }
	
    id_semaforo = creo_semaforo();
    while (1)
    {
        espera_semaforo(id_semaforo);
        printf("Avion %d\n", nro_avion); 

        abrirArchivo(&archivo, "panel.txt", "a");
        if (archivo != NULL)
        {
            file_pointer_write = archivo;
            avion = armar_avion(nro_avion); 
            escribirAvionArchivo(avion);
            usleep(INTERVALO * 1000);
            cerrarArchivo(&archivo);
            file_pointer_write = NULL;
            printf("\nESPERAMOS\n");
        }
        else
        {
            perror("Error al abrir panel.txt");
        }
        levanta_semaforo(id_semaforo);
        usleep(INTERVALO * 1000);
    };

    return 0;
}
