#include <sys/ipc.h>
#include "key.h"
#include <stdio.h>
#include <stdlib.h>

key_t create_key()
{
    key_t key;
    key = ftok ("/usr/bin/ls",33);

    if(key == (key_t)-1)
    {
        printf("No puedo conseguir la clave\n");
        exit(0);
    }
    return key;
}
