#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i = 1;
	printf("\n%d\n",ft_printf("%-30p$", &i));
	printf("\n%d\n",printf("%-16p$", &i));
	//printf("\n%d\n", printf("%-2.10000000c$", 'A'));

}
