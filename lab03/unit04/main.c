#include <stdio.h>
#include "key.h"
#include <sys/ipc.h>

int main(int argc, char *argv[])
{

    key_t clave = create_key();
    printf("key is %d\n",clave);
    return 0;
}