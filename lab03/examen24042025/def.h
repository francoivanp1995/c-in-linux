#ifndef DEF_H
#define DEF_H

#define ROJO  			0
#define VERDE 			1
#define LARGONOMBRE 30
#define LARGO_MENSAJE 100
#define MINMT2 20
#define MAXMT2 30
#define INTERVALO 500
#define METROCUADRADOPRECIO 2000
#define QPROPIEDADES 4

typedef struct {
	int num_identificador;
	char nombre_propiedad[LARGONOMBRE];
	int cantidadMetrosCuadrados;
	int precio;
} Propiedad;

typedef struct 
{
	char nombre_propiedad[LARGONOMBRE];
	int precio;
	char reservada;
	int cantidadMetrosCuadrados;
} Consulta;

typedef struct
{
	int num_identificador;
	int dni;
	char apellido[LARGONOMBRE];
} Reserva;



#endif
