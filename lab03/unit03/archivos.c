#include "archivos.h"
#include <stdio.h>

int openFile(char *fileName, char *type)
{
    FILE *fileNamePointer;
    if((fileNamePointer=fopen(fileName,type))==NULL)
    {
        printf("\n Error while opening the file");
        return 0;
    }
    else {
        return 1;
    }
}

int readFile(char *fileName)
{   
    char cadena[100];
    FILE *fileNamePointer = fopen(fileName,"r");
    if (fileNamePointer == NULL) {
        printf("Error while opening the file. Please check if the file exists before reading it. %s\n", fileName);
        return 0;
    }
    while (fscanf(fileNamePointer, "%s", cadena) != EOF) {
        printf("%s\n", cadena);
    }

    fclose(fileNamePointer);
    return 1;
}

int writeFile(char *fileName)
{
    int limite = 10;
    int iterator;
    FILE *fileNamePointer = fopen(fileName,"w");
    if (fileNamePointer == NULL) {
        printf("Error while opening the file %s\n", fileName);
        return 0;
    }
    printf("Ingrese los nombres de diez productos\n");
    for (iterator = 1; iterator <= limite ; iterator++)
    {
        char producto[50];
        printf("Ingrese el nombre del producto: ");
        scanf("%s",producto);
        fprintf(fileNamePointer, "%s-%02d\n", producto, iterator);
    }
    fclose(fileNamePointer);
    printf("El archivo ha sido creado.");
    return 0;

}

void closeFile(FILE *filePointer) {
    if (filePointer != NULL) {
        fclose(filePointer);
    }
}
