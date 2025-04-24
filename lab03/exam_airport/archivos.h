#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <stdio.h>
#include "def.h"

extern FILE *file_pointer_read;
extern FILE *file_pointer_write;

int abrirArchivo(FILE **fp, const char* nombre_archivo, const char* modo);
int cerrarArchivo(FILE **fp);
int leerArchivo(FILE *fp, char* buffer, int maxLen);
int escribirArchivo(FILE *fp, char* texto);
int escribirAvionArchivo(Avion avion);

#endif
