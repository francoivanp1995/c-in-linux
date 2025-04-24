#include "functions.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "def.h"
#include <string.h>

void print_msg(char *msg)
{
	printf("%s\n", msg);
}

int generar_numero_random(const int num_min, const int num_max)
{
    return rand() % (num_max - num_min + 1) + num_min;
}

Avion armar_avion(int nro_avion) 
{
    Avion avion;
    avion.num_avion = nro_avion;

    printf("Ingrese el nombre de la ciudad de la que proviene: ");

    if (fgets(avion.ciudad, LARGO_MENSAJE, stdin) != NULL) {
        avion.ciudad[strcspn(avion.ciudad, "\n")] = '\0';
    } else {
        strcpy(avion.ciudad, "CiudadDesconocida");
    }

    return avion;
}

int validar_parametros(int argc, char *argv[], int *nro_avion) {
    if (argc < 2) {
        fprintf(stderr, "Error: Debe ejecutar el programa como ./avion <nro_proceso>\n");
        return 0;
    }

    *nro_avion = atoi(argv[1]);
    if (*nro_avion <= 0) {
        fprintf(stderr, "Error: El número del avión debe ser mayor que 0.\n");
        return 0;
    }

    return 1;
}
