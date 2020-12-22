#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i = 1;
	printf("\n%d\n",ft_printf("%20u$", 123));
	printf("\n%d\n",printf("%2u$", 123));
	//printf("\n%d\n", printf("%-2.10000000c$", 'A'));

}
