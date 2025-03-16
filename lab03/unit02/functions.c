#include "functions.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void get_random_num(int argc, char *argv[])
{
    srand(time(0));

    if (argc>=4)
    {
        int lb = atoi(argv[1]);
        int ub = atoi(argv[2]);
        int count = atoi(argv[3]);
        int n;
        
        if (lb > ub) {
            printf("Error: The lower bound can NOT be higher than the upper bound..\n");
            return;
        }

        for (n=0; n<count; n++)
        {
            printf("%d ", (rand() % (ub - lb + 1)) + lb );
        }
        
    } else if (argc==3)
    {
        int lb = atoi(argv[1]);
        int ub = atoi(argv[2]);

        if (lb > ub) {
            printf("Error: The lower bound can NOT be higher than the upper bound..\n");
            return;
        }

        printf("%d ", (rand() % (ub - lb + 1)) + lb );
    } else if (argc==2)
    {
        int lb = 0;
        int ub = atoi(argv[1]);

        if (ub < 0) {
            printf("Error: The upper bound should be positive..\n");
            return;
        }

        printf("%d ", (rand() % (ub - lb + 1)) + lb );
    } else 
    {
        int value = rand();
        printf("%d ", value);
    }
    printf("\n");
}

void print_msg(char *msg)
{
	printf("%s\n", msg);
}
