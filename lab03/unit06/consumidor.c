#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "def.h"
#include "archivos.h"

int main(int argc, char *argv[])
{
	Pedido pedido;
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
    }

    if (tipo_menu_filtro != 'A' && tipo_menu_filtro != 'B' && tipo_menu_filtro != 'C') {
        printf("Tipo de menú inválido. Debe ser A, B o C.\n");
        exit(1);
    }

	while(1)
	{
		espera_semaforo(id_semaforo);
		inAbrirArchivo(&archivo,"menues.txt", "r");
		if (archivo!=NULL)
		{
			fp_read = archivo;
			menues_total = 0;
			total_facturado = 0;
			printf("\nCONSUMIMOS\n");
			while (inLeerPedido(&pedido, buffer, sizeof(buffer)))
			{
				if (pedido.tipoMenu == tipo_menu_filtro)
				{
					if (pedido.tipoMenu == 'A')
					{
						tipoMenu[0]++;
						facturado_por_menu[0] += pedido.precio;
					} else if (pedido.tipoMenu == 'B')
					{
						tipoMenu[1]++;
						facturado_por_menu[1] += pedido.precio;
					}
					else
					{
						tipoMenu[2]++;
						facturado_por_menu[2] += pedido.precio;
					}					
					menues_total++;
                    total_facturado += pedido.precio;
                    printf("→ Menu: %c | Postre: %d | Sistema: %c | Precio: %d\n",
                        pedido.tipoMenu, pedido.con_postre, pedido.sistema, pedido.precio);
				}
				usleep(1000);
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

	return 0;
}
