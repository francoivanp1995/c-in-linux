#ifndef DEF_H
#define DEF_H

#define ROJO  			0
#define VERDE 			1
#define LARGO 			100
#define PRECIOMENUA 1000
#define PRECIOMENUB 2000
#define PRECIOMENUC 3000
#define PRECIOPOSTRE 200
#define MAX_PEDIDOS 30

typedef struct {
	char tipoMenu;
	int con_postre;
	char sistema;
	int precio;
} Pedido;

#endif
