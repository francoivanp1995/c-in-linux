#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "def.h"

void print_msg(char *msg);
int generar_numero_random(const int num_min, const int num_max);
Avion armar_avion(int nro_avion);
int validar_parametros(int argc, char *argv[], int *nro_avion);

#endif
