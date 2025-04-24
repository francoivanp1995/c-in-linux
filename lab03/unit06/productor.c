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
	Pedido pedido;
	int id_semaforo;
	id_semaforo =  creo_semaforo();
	inicia_semaforo(id_semaforo, VERDE);
	while(1)
	{
		espera_semaforo(id_semaforo);
		printf("\nPRODUCIMOS-MENU\n");
		inAbrirArchivo(&archivo,"menues.txt", "a");
		if (archivo!=NULL)
		{
			fp_write = archivo;
			pedido = generar_pedido();
			mostrar_pedido(pedido);
			escribirArchivoPedido(pedido);
			usleep(1000);
			
		inCerrarArchivo(&archivo);
		fp_write = NULL; 
		printf("\nESPERAMOS\n");
		}
		else
		{
			perror ("Error al abrir menues.txt");
		}
		levanta_semaforo(id_semaforo);
		usleep(100);
	};
	return 0;
}
