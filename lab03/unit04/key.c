#include <sys/ipc.h>
#include "key.h"
#include <stdio.h>
#include <stdlib.h>

key_t create_key()
{
    key_t key;
    key = ftok ("/usr/bin/less",34);

    if(key == (key_t)-1)
    {
        printf("mensaje\n");
        exit(0);
    }
    return key;
}