#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "def.h"

void print_msg(char *msg);
int generar_numero_random();
Pedido generar_pedido();
void mostrar_pedido(Pedido p);
void check_argv(const char tipo_menu_filtro);

#endif /* FUNCTIONS_H */
