#include "archivos.h"
#include <stdio.h>
#include "global.h"

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
        printf("Error while opening the file %s\n", fileName);
        return 0;
    }
    while (fscanf(fileNamePointer, "%s", cadena) != EOF) {
        printf("%s\n", cadena);
    }

    fclose(fileNamePointer);
    return 1;
}

int writeFile();

int closeFile();

