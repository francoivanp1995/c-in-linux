#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "def.h"

FILE *fp_read = NULL;
FILE *fp_write = NULL;

int inAbrirArchivo(FILE **fp, const char* nombre_archivo, const char* modo) {
    *fp = fopen(nombre_archivo, modo);
    if (*fp == NULL) {
        return 0;  
    }
    return 1;  
}

int inCerrarArchivo(FILE **fp) {
    if (*fp != NULL) {
        fclose(*fp);
        *fp = NULL;
        return 1;  
    }
    return 0;  
}

int inLeerArchivo(char* buffer, int maxLen) {
    if (fp_read == NULL) {
        return 0;  
    }
    
    if (fgets(buffer, maxLen, fp_read) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        return 1;  
    }
    return 0;  
}

int inLeerPedido(Pedido* pedido, char* buffer, int maxLen) {
    if (fp_read == NULL) {
        return 0;
    }

    if (fgets(buffer, maxLen, fp_read) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;

        if (sscanf(buffer, "%c,%d,%c,%d", &pedido->tipoMenu, &pedido->con_postre, &pedido->sistema, &pedido->precio) == 4) {
            return 1;
        }
    }
    return 0;  
}


int inEscribirArchivo(char* texto) {
    if (fp_write == NULL) {
        return 0;
    }
    fprintf(fp_write, "%s\n", texto);
    return 1;
}

int escribirArchivoPedido(Pedido p)
{
    if (fp_write == NULL) {
        return 0;
    }
    fprintf(fp_write, "%c,%d,%c,%d\n", 
        p.tipoMenu, 
        p.con_postre, 
        p.sistema, 
        p.precio
    );
    return 1;
}
