#include <stdio.h>
#include "msg.h"

int main(void)
{
	char welcome_msg[] = {"Hello c developer"};
	char goodbye_msg[] = {"Ciao c developer"};
	
	printf("%s\n", welcome_msg);
	print_msg(goodbye_msg);
	return 0;
}
