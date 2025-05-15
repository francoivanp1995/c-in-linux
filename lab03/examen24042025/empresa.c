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
    Propiedad propiedad;
	int id_semaforo;
	int indice=0;
    id_semaforo = creo_semaforo();
    inicia_semaforo(id_semaforo, VERDE); 
    for (indice=0; indice<QPROPIEDADES; indice++)
    {
        espera_semaforo(id_semaforo);
        printf("AlquiCor\n");
        abrirArchivo(&archivo, "propiedades.txt", "a");
        if (archivo != NULL)
        {        
            file_pointer_write = archivo;
            propiedad = ingresoDatosPropiedad(); 
            escribirPropiedadArchivo(propiedad);
            usleep(INTERVALO * 1000);
            cerrarArchivo(&archivo);
            file_pointer_write = NULL;
            printf("\nESPERAMOS\n");
        }
        else
        {
            perror("Error al abrir propiedades.txt");
        }
        levanta_semaforo(id_semaforo);
        usleep(INTERVALO * 1000);
    };

    return 0;
}
