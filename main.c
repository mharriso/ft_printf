#include "ft_printf.h"
#include <stdio.h>
void error(int c1, int c2)
{
	if (c1 != c2)
		printf("__________________!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!____________________\nprintf_%d | ft_printf_%d\n\n", c1, c2);
}
int main()
{
	int p = 1;
	char *str = "Hello World!:)";
	printf("\n%d\n",ft_printf("%"));
	printf("\n%d\n",printf("%"));
	printf("\n%d\n",ft_printf("%%%%"));
	printf("\n%d\n",printf("%%%%"));
	printf("\n%d\n",ft_printf("char: %8c$", 'A'));
	printf("\n%d\n",printf("char: %8c$",'A'));
	printf("\n%d\n",ft_printf("char: %-8c$", 'A'));
	printf("\n%d\n",printf("char: %-8c$",'A'));
	printf("\n%d\n",ft_printf("char: %*c$", -8, 'A'));
	printf("\n%d\n",printf("char: %*c$", -8, 'A'));
	printf("\n%d\n",ft_printf("char: %*c$", 8, 'A'));
	printf("\n%d\n",printf("char: %*c$", 8, 'A'));
	printf("\n%d\n",ft_printf("char: %*c$", 0, 'A'));
	printf("\n%d\n",printf("char: %*c$", 0, 'A'));
	printf("\n%d\n",ft_printf("char: %*c$", 1, 'A'));
	printf("\n%d\n",printf("char: %*c$", 1, 'A'));
	printf("\n%d\n",ft_printf("char: %*c$", -1, 'A'));
	printf("\n%d\n",printf("char: %*c$", -1, 'A'));
	printf("\n%d\n",ft_printf("%%: %*%$", -10));
	printf("\n%d\n",printf("%%: %*%$", -10));
	printf("\n%d\n",ft_printf("pointer: %p$", &p));
	printf("\n%d\n",printf("pointer: %p$", &p));
	printf("\n%d\n",ft_printf("null pointer: %p$", NULL));
	printf("\n%d\n",printf("null pointer: %p$", NULL));
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


		int c1;
		int c2;

		printf("\n\n\n__________________________________________________________________________________\n");
		printf("\nTEST_%%\n\n");

		c1 = printf("|%%--|%5%--|%05%--|%-5%--|%-05%--|%.5%--|%-.5%--|%03.5%--|%3.5%--|%5.3%|\n");
		c2 = ft_printf("|%%--|%5%--|%05%--|%-5%--|%-05%--|%.5%--|%-.5%--|%03.5%--|%3.5%--|%5.3%|\n");
		//c2 = ft_printf("|%%--|%5%--|%05%--|%-5%--|%-05%--|%.5%--|%-.5%--|%03.5%--|%3.5%--|%5.3%|\n");
		error(c1, c2);

		printf("\n\n\n__________________________________________________________________________________\n");
		printf("\nTEST_CHARS\n");

		printf("\nTest with 0:\n");
		c1 = printf("|%c|%5c|%10c|%-5c|%-c|\n", 0, 0, 0, 0, 0);
		c2 = ft_printf("|%c|%5c|%10c|%-5c|%-c|\n", 0, 0, 0, 0, 0);
		error(c1, c2);

		printf("\nNormal tests without warnings:\n");
		c1 = printf("%c, %1c, %3c, %10c\n", 'a', 'a', 'a', 'a');
		c2 = ft_printf("%c, %1c, %3c, %10c\n", 'a', 'a', 'a', 'a');
		error(c1, c2);

		c1 = printf("%-c, %-1c, %-3c, %-10c\n", 'a', 'a', 'a', 'a');
		c2 = ft_printf("%-c, %-1c, %-3c, %-10c\n", 'a', 'a', 'a', 'a');
		error(c1, c2);

		printf("\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------\n\n");

		printf("Test with NULL:\n");
		c1 = printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		c2 = ft_printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		error(c1, c2);
		printf("\n");

		printf("Test with 0:\n");
		c1 = printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c--|%3.5c--|%-3.5c--|%0c|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		c2 = ft_printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c--|%3.5c--|%-3.5c--|%0c|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		error(c1, c2);
		printf("\n");

		printf("Test with nothing:\n");
		c1 = printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c--|%3.5c--|%-3.5c--|%0c|\n", 0);
		c2 = ft_printf("|%c--|%5c--|%05c--|%-5c--|%-05c--|%.5c--|%-.5c--|%03.5c--|%3.5c--|%-3.5c--|%0c|\n", 0);
		error(c1, c2);
		printf("\n");

		c1 = printf("%0c, %1.0c, %3.1c, %10.1c\n", 'a', 'a', 'a', 'a');
		c2 = ft_printf("%0c, %1.0c, %3.1c, %10.1c\n", 'a', 'a', 'a', 'a');
		error(c1, c2);

		c1 = printf("%0c, %01.0c, %03.1c, %010.1c\n", 'a', 'a', 'a', 'a');
		c2 = ft_printf("%00c, %01.0c, %03.1c, %010.1c\n", 'a', 'a', 'a', 'a');
		error(c1, c2);

		c1 = printf("%-0c, %-01c, %-03c, %-010c\n", 'a', 'a', 'a', 'a');
		c2 = ft_printf("%-0c, %-01c, %-03c, %-010c\n", 'a', 'a', 'a', 'a');
		error(c1, c2);



	//printf("\n%d\n", printf("%s$", str));

}
