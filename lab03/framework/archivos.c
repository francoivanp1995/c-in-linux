#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "def.h"

FILE *file_pointer_read = NULL;
FILE *file_pointer_write = NULL;

int abrirArchivo(FILE **fp, const char* nombre_archivo, const char* modo) {
    *fp = fopen(nombre_archivo, modo);
    if (*fp == NULL) {
        return 0;  
    }
    return 1;  
}

int cerrarArchivo(FILE **fp) {
    if (*fp != NULL) {
        fclose(*fp);
        *fp = NULL;
        return 1;  
    }
    return 0;  
}

int leerArchivo(char* buffer, int maxLen) {
    if (file_pointer_read == NULL) {
        return 0;  
    }
    
    if (fgets(buffer, maxLen, file_pointer_read) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        return 1;  
    }
    return 0;  
}

int escribirArchivo(FILE *fp, char* texto) {
    if (fp == NULL) return 0;
    fprintf(fp, "%s\n", texto);
    return 1;
}

