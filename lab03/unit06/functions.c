#include "functions.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "def.h"

void print_msg(char *msg)
{
	printf("%s\n", msg);
}

int generar_numero_random()
{
    return(rand() %3) + 1;    
}

Pedido generar_pedido() 
{
    Pedido p;
    int opcion;
    int tipo = generar_numero_random();
    switch (tipo) {
        case 1:
            p.tipoMenu = 'A';
            p.precio = PRECIOMENUA;
            p.sistema = 'A';
            break;
        case 2:
            p.tipoMenu = 'B';
            p.precio = PRECIOMENUB;
            p.sistema = 'B';
            break;
        case 3:
            p.tipoMenu = 'C';
            p.precio = PRECIOMENUC;
            p.sistema = 'C';
            break;
    }
    
    printf("\nDesea postre? (1 = si, 0 = no):");
    scanf("%d", &opcion);
    p.con_postre = opcion;
    if (opcion == 1) {
        p.precio += 200;
    }

    return p;
}

void mostrar_pedido(Pedido p) 
{
    printf("\nDisplaying information\n");
    printf("Tipo de menu: %c", p.tipoMenu);
    printf("\nPrecio: %d", p.precio);
    printf("\nSistema: %c", p.sistema);
    printf("\nCon Postre: %d", p.con_postre);
}


void check_argv( const char tipo_menu_filtro)
{
    if (tipo_menu_filtro != 'A' && tipo_menu_filtro != 'B' && tipo_menu_filtro != 'C') {
        printf("Tipo de menú inválido. Debe ser A, B o C.\n");
        exit(1);
    }
}
