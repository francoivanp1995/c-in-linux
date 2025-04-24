#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "def.h"
#include "archivos.h"

int main(int argc, char *argv[])
{
	FILE *archivo; 
	char buffer[LARGO];
	char tipo_menu_filtro = argv[1][0];
	int id_semaforo;
	int menues_total;
	int total_facturado;
	int tipoMenu[3];
	int facturado_por_menu[3];
	memset(tipoMenu,0,sizeof(tipoMenu));
	memset(facturado_por_menu,0,sizeof(facturado_por_menu));
	id_semaforo =  creo_semaforo();
	
    if (argc != 2) {
        printf("Uso: %s <tipo_menu: A | B | C>\n", argv[0]);
        exit(1);
    } else {

	check_argv(tipo_menu_filtro);

	while(1)
	{
		espera_semaforo(id_semaforo);
		inAbrirArchivo(&archivo,"menues.txt", "r");
		if (archivo!=NULL)
		{
			menues_total = 0;
			total_facturado = 0;
			printf("\nCONSUMIMOS\n");
			while (inLeerPedido(&pedido, buffer, sizeof(buffer)))
			{
				if (pedido.tipoMenu == tipo_menu_filtro)
				{
				}
				usleep(10000);
			}
		inCerrarArchivo(&archivo);
		}
		else
		{
			perror ("Error al abrir menues.txt");
		}
		printf("\nESPERAMOS\n");
		levanta_semaforo(id_semaforo);
		usleep(1000);
		printf("Resumen\n");
		printf("\nTotal menues A: %d",tipoMenu[0]);
		printf("\nTotal menues B: %d",tipoMenu[1]);
		printf("\nTotal menues C: %d",tipoMenu[2]);
		printf("\nFacturado menu A: %d",facturado_por_menu[0]);
		printf("\nFacturado menu B: %d",facturado_por_menu[1]);
		printf("\nFacturado menu C: %d",facturado_por_menu[2]);
		memset(tipoMenu, 0, sizeof(tipoMenu));
		memset(facturado_por_menu, 0, sizeof(facturado_por_menu));

	};
}
	return 0;
}
