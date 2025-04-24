#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <stdio.h>

extern FILE *fp_read;
extern FILE *fp_write;

int inAbrirArchivo(FILE **fp, const char* nombre_archivo, const char* modo);
int inCerrarArchivo(FILE **fp);
int inLeerArchivo(char* buffer, int maxLen);
int inEscribirArchivo(char* texto);

#endif
