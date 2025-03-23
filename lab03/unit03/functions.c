#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include <string.h>
#include "archivos.h"

void checkArgVec(int argc, char *argv[])
{
    if (argc != 3)
    {
        print_msg("Los argumentos deben ser, <nombre_archivo> y <r> o <w>");
    } else if (argc == 3 && (strcmp(argv[2],"r")!=0) && (strcmp(argv[2],"w")!=0))
    {
        print_msg("Debe ser r o w");
    }
    else
    {
        print_msg("Todo bien");
    }
}

void file(char *argv[])
{
    if (strcmp(argv[2],"r")==0)
    {
        readFile(argv[1]);
    }
    
}

void print_msg(char *msg)
{
	printf("%s\n", msg);
}
