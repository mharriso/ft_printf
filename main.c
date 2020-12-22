#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int p = 1;
	char *str = "Hello World!:)";
	printf("\n%d\n",ft_printf("%"));
	printf("\n%d\n",printf("%"));
	printf("\n%d\n",ft_printf("%%%%"));
	printf("\n%d\n",printf("%%%%"));
	printf("\n%d\n",ft_printf("pointer: %p$", &p));
	printf("\n%d\n",printf("pointer: %p$", &p));
	printf("\n%d\n",ft_printf("pointer: %p$", NULL));
	printf("\n%d\n",printf("pointer: %p$", NULL));
	printf("\n%d\n",ft_printf("INT_MAX: %d$", INT_MAX));
	printf("\n%d\n",printf("INT_MAX: %d$", INT_MAX));
	printf("\n%d\n",ft_printf("INT_MIN: %i$", INT_MIN));
	printf("\n%d\n",printf("INT_MIN: %i$", INT_MIN));
	printf("\n%d\n",ft_printf("unsigned: %u$", -1));
	printf("\n%d\n",printf("unsighed: %u$", -1));
	printf("\n%d\n",ft_printf("NULL: %s$", NULL));
	printf("\n%d\n",printf("NULL: %s$", NULL));
	printf("\n%d\n",ft_printf("str: %s$", str));
	printf("\n%d\n",printf("str: %s$", str));
	printf("\n%d\n",ft_printf("empty str: %s$", ""));
	printf("\n%d\n",printf("empty str: %s$", ""));
	printf("\n%d\n",ft_printf("HEX: %x$ %x$ %X$", -1, 123456, 799999));
	printf("\n%d\n",printf("HEX: %x$ %x$ %X$", -1,  123456, 799999));

	//printf("\n%d\n", printf("%s$", str));

}
