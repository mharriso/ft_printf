#include "ft_printf.h"
#include <stdio.h>

#define RESET   "\033[0m"  //все атрибуты по умолчанию
#define BLACK   "\033[30m"  //30-37 цвет текста
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BBLACK   "\033[40m" //40-47 цвет фона, background colors
#define BRED     "\033[41m"
#define BGREEN   "\033[42m"
#define BYELLOW  "\033[43m"
#define BBLUE    "\033[44m"
#define BMAGENTA "\033[45m"
#define BCYAN    "\033[46m"
#define BWHITE   "\033[47;30m" //комбинация двух параметров: черный текст на белом фоне
void error(int c1, int c2)
{
	if (c1 != c2)
		printf(RED"________________!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!!__________________\nprintf_%d | ft_printf_%d"RESET"\n\n", c1, c2);
}
void check()
{
	char *str = "Hello World!:)";
	printf("%.*c$\n", 21, 'A');
	printf("%.*c$\n", -21, 'A');
	printf("%021c\n$\n", 'A');
	printf("%.*d$\n", 0, 0);
	printf("%.*u$\n", 0, 0);
	printf("%.*x$\n", 0, 0);
	printf("%.*X$\n", 0, 0);
	printf("%.*i$\n", 0, 0);
	printf("%020s$\n", str);
	printf("%20.*s$\n", -5, str);
	printf("%------------60d", 21);
}
void test_char()
{
	int a, b;
	printf("\n"GREEN"----------------------------------CHAR---------------------------------"RESET"\n");
	a = printf("char: %8c$\n", 'A');
	b = ft_printf("char: %8c$\n",'A');
	error(a, b);
	a = printf("char: %-8c$\n", 'A');
	b = ft_printf("char: %-8c$\n",'A');
	error(a, b);
	a = printf("char: %*c$\n", -8, 'A');
	b = ft_printf("char: %*c$\n", -8, 'A');
	error(a, b);
	a = printf("char: %*c$\n", 8, 'A');
	b = ft_printf("char: %*c$\n", 8, 'A');
	error(a, b);
	a = printf("char: %*c$\n", 0, 'A');
	b = ft_printf("char: %*c$\n", 0, 'A');
	error(a, b);
	a = printf("char: %*c$\n", 1, 'A');
	b = ft_printf("char: %*c$\n", 1, 'A');
	error(a, b);
	a = printf("char: %*c$\n", -1, 'A');
	a = ft_printf("char: %*c$\n", -1, 'A');
	error(a, b);
}
void test_string()
{
	int a, b;
	char *s = "Happy new year!:)";
	printf("\n"GREEN"----------------------------------STRING---------------------------------"RESET"\n");
	a = printf("%8s$\n", s);
	b = ft_printf("%8s$\n", s);
	error(a, b);
	a = printf("%-8s$\n", s);
	b = ft_printf("%-8s$\n", s);
	error(a, b);
	a = printf("%*s$\n", -20, s);
	b = ft_printf("%*s$\n", -20, s);
	error(a, b);
	a = printf("%*s$\n", 21, s);
	b = ft_printf("%*s$\n", 21, s);
	error(a, b);
	a = printf("%*s$\n", 0, s);
	b = ft_printf("%*s$\n", 0, s);
	error(a, b);
	a = printf("%0*s$\n", 42, s);
	b = ft_printf("%0*s$\n", 42, s);
	error(a, b);
	a = printf("%-30s$\n", s);
	b = ft_printf("%-30s$\n", s);
	error(a, b);	
	a = printf("%-30.5s$\n", s);
	b = ft_printf("%-30.5s$\n", s);
	error(a, b);
		a = printf("%42.5s$\n", s);
	b = ft_printf("%42.5s$\n", s);
	error(a, b);
	a = printf("%9.10s$\n", s);
	b = ft_printf("%9.10s$\n", s);
	error(a, b);
	a = printf("%-30.*s$\n", -5, s);
	b = ft_printf("%-30.*s$\n", -5, s);
	error(a, b);
	a = printf("%-30.*s$\n", 0, s);
	b = ft_printf("%-30.*s$\n", 0, s);
	error(a, b);
	a = printf("%-30.*s$\n", 50, s);
	b = ft_printf("%-30.*s$\n", 50, s);
	error(a, b);
}
void test_basic()
{
	int a, b;
	int p = 1;
	char *str = "Hello World!:)";
	printf("\n"GREEN"--------------------------------BASIC TESTS-----------------------------"RESET"\n");

	a = printf("%");
	printf("\n");
	b = ft_printf("%");
	printf("\n");
	error(a, b);
	a = printf("%%%%");
	printf("\n");
	b = ft_printf("%%%%");
	printf("\n");
	error(a, b);
	a = printf("%%: %*%$\n", -10);
	b = ft_printf("%%: %*%$\n", -10);
	error(a, b);
	a = printf("char: %c$\n", 'A');
	b = ft_printf("char: %c$\n",'A');
	error(a, b);
	a = printf("pointer: %p$\n", &p);
	b = ft_printf("pointer: %p$\n", &p);
	error(a, b);
	a = printf("null pointer: %p$\n", NULL);
	b = ft_printf("null pointer: %p$\n", NULL);
	error(a, b);
	a = printf("INT_MAX: %d$\n", INT_MAX);
	b = ft_printf("INT_MAX: %d$\n", INT_MAX);
	error(a, b);
	a = printf("INT_MIN: %i$\n", INT_MIN);
	b = ft_printf("INT_MIN: %i$\n", INT_MIN);
	error(a, b);
	a = printf("unsigned: %u$\n", -1);
	b = ft_printf("unsighed: %u$\n", -1);
	error(a, b);
	a = printf("NULL: %s$\n", NULL);
	b = ft_printf("NULL: %s$\n", NULL);
	error(a, b);
	a = printf("str: %s$\n", str);
	b = ft_printf("str: %s$\n", str);
	error(a, b);
	a = printf("empty str: %s$\n", "");
	b = ft_printf("empty str: %s$\n", "");
	error(a, b);
	a = printf("HEX: %x$ %x$ %X$\n", -1, 123456, 799999);
	b = ft_printf("HEX: %x$ %x$ %X$\n", -1,  123456, 799999);
	error(a, b);
}
void github_test_char()
{
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

	c1 = printf("%00c, %01.0c, %03.1c, %010.1c\n", 'a', 'a', 'a', 'a');
	c2 = ft_printf("%00c, %01.0c, %03.1c, %010.1c\n", 'a', 'a', 'a', 'a');
	error(c1, c2);

	c1 = printf("%-0c, %-01c, %-03c, %-010c\n", 'a', 'a', 'a', 'a');
	c2 = ft_printf("%-0c, %-01c, %-03c, %-010c\n", 'a', 'a', 'a', 'a');
	error(c1, c2);
}
int main()
{
	//ft_printf("%*c$\n", INT_MIN, 'A');
	 test_basic();
	// test_char();
	test_string();
	// github_test_char();
	//check();
}
