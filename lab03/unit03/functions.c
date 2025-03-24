#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"

void checkArgVec(int argc, char *argv[])
{
    if (argc != 3)
    {
        print_msg("Los argumentos deben ser, <nombre_archivo> y <r> o <w>");
        return;
    } else if (argc == 3 && (strcmp(argv[2],"r")!=0) && (strcmp(argv[2],"w")!=0))
    {
        print_msg("El segundo argumento debe ser r o w");
        return;
    } else
    {
        return;
    }
}

void file(char *argv[])
{
    if (strcmp(argv[2],"r")==0)
    {
        readFile(argv[1]);
    }
    else if (strcmp(argv[2],"w")==0)
    {
        writeFile(argv[1]);
    }
    else
    {
        return;
    }
}

void print_msg(char *msg)
{
	printf("%s\n", msg);
}
