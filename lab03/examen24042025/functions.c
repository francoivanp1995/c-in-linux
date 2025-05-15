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

int generar_metros_cuadrados(const int num_min, const int num_max)
{
    return rand() % (num_max - num_min + 1) + num_min;
}

Propiedad ingresoDatosPropiedad(){
    Propiedad propiedad;
    int numIdPropiedad;
    int c;
    int qMetrosCuadrados = generar_metros_cuadrados(MINMT2,MAXMT2);;
    printf("\nIngrese numero identificador de la propiedad:");
    scanf("%d", &numIdPropiedad);
    while ((c = getchar()) != '\n' && c != EOF) { }
    propiedad.num_identificador = numIdPropiedad;
    printf("\nIngrese nombre de la propiedad:" );
    if (fgets(propiedad.nombre_propiedad, LARGONOMBRE, stdin) != NULL) {
        propiedad.nombre_propiedad[strcspn(propiedad.nombre_propiedad, "\n")] = '\0';
    }
    propiedad.cantidadMetrosCuadrados = qMetrosCuadrados;
    propiedad.precio = (propiedad.cantidadMetrosCuadrados*METROCUADRADOPRECIO);
    return propiedad;
}

void consultarDisponibilidad(int num_id){
    Propiedad propiedad;
    if (num_id == propiedad.num_identificador)
    {
        
    }
    
}

void realizarReserva(){

}