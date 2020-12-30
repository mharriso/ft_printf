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

void	error(int c1, int c2)
{
	if (c1 != c2)
		printf(RED"******************************** ERROR! ********************************\nprintf_%d | ft_printf_%d"RESET"\n\n", c1, c2);
}
void	check()
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
	int n = 1;
	ft_printf(NULL);
	printf(NULL);
	printf("%+d\n", -12345);
	printf("%+d\n", 12345);
	printf("%+p\n", &n);
	printf("%+p\n", NULL);
	printf("%+u\n", 42);
	printf("%+u\n", -1);
	printf("%+x\n", 42);
	printf("%+X\n", -1);
	printf("% +d\n", -12345);
	printf("% +d\n", 12345);
	printf("% +p\n", &n);
	printf("% +p\n", NULL);
	printf("% +u\n", 42);
	printf("% +u\n", -1);
	printf("% +x\n", 42);
	printf("% +X\n", -1);
	printf("%# +d\n", -12345);
	printf("%# +d\n", 12345);
	printf("%# +p\n", &n);
	printf("%# +p\n", NULL);
	printf("%# +u\n", 42);
	printf("%# +u\n", -1);
	printf("%# +x\n", 42);
	printf("%# +X\n", -1);
	printf("%                  d\n", 12345);
	printf("% +#5X$\n", 1234);
}
void	char_test()
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
void	string_test()
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
	// a = printf("%.-10s$\n", s);
	// b = ft_printf("%.-10s$\n", s);
	// error(a, b);
}
void	pointer_test()
{
	int a, b;
	char *s = "Happy new year!:)";
	printf("\n"GREEN"----------------------------------POINTER---------------------------------"RESET"\n");
	a = printf("%-40.23p$\n", &s);
	b = ft_printf("%-40.23p$\n", &s);
	error(a, b);
	a = printf("%40.23p$\n", &s);
	b = ft_printf("%40.23p$\n", &s);
	error(a, b);
	a = printf("%40.23p$\n", NULL);
	b = ft_printf("%40.23p$\n", NULL);
	error(a, b);
	a = printf("%-40.23p$\n", NULL);
	b = ft_printf("%-40.23p$\n", NULL);
	a = printf("%-4.2p$\n", &s);
	b = ft_printf("%-4.2p$\n", &s);
	error(a, b);
	a = printf("%4.2p$\n", &s);
	b = ft_printf("%4.2p$\n", &s);
	error(a, b);
	a = printf("NULL %4.2p$\n", NULL);
	b = ft_printf("NULL %4.2p$\n", NULL);
	error(a, b);

}
void	test_basic()
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
void	char_github_test()
{
	int c1;
	int c2;

	printf(GREEN"\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_%%"RESET"\n\n");

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

	printf(MAGENTA"\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------"RESET"\n\n");

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
void	string_github_test()
{
	char str[100];
	char str1[100];
	int c1;
	int c2;

	strcpy(str, "hello");
	strcpy(str1, "a");

	printf(GREEN"\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_STRINGS"RESET"\n\n");


	c2 = ft_printf("*|%.0s|\n", "Hello");
	c1 = printf(">|%.0s|\n", "Hello");
	error(c1, c2);

	c2 = ft_printf("*|%3.s|\n", NULL);
	c1 = printf(">|%3.s|\n", NULL);
	error(c1, c2);

	c2 = ft_printf("**|%10.s|\n", NULL);
	c1 = printf("88|%10.0s|\n", NULL);
	error(c1, c2);

	c2 = ft_printf("**|%-3.s|\n", "Hello");
	c1 = printf("92|%-3.s|\n", "Hello");
	error(c1, c2);

	c2 = ft_printf("**|%-3.s|\n", NULL);
	c1 = printf("94|%-3.s|\n", NULL);
	error(c1, c2);

	c2 = ft_printf("***|%-.00s|\n", "Hello");
	c1 = printf("121|%-.00s|\n", "Hello");
	error(c1, c2);

	c2 = ft_printf("***|%-09s|\n", "Hello");
	c1 = printf("132|%-09s|\n", "Hello");
	error(c1, c2);

	c2 = ft_printf("***|%0-9s|\n", "Hello");
	c1 = printf("132|%0-9s|\n", "Hello");
	error(c1, c2);

	c2 = ft_printf("***|%c|\n", '\0');
	c1 = printf("457|%c|\n", '\0');
	error(c1, c2);

	c2 = ft_printf("***|%5c|\n", '\0');
	c1 = printf("458|%5c|\n", '\0');
	error(c1, c2);

	c2 = ft_printf("***|%-5c|\n", '\0');
	c1 = printf("459|%-5c|\n", '\0');
	error(c1, c2);

	c2 = ft_printf("***|%c|\n", -0);
	c1 = printf("645|%c|\n", -0);
	error(c1, c2);

	c2 = ft_printf("***|%c|\n", 0);
	c1 = printf("646|%c|\n", 0);
	error(c1, c2);

	c2 = ft_printf("***|%.*s|\n", 0, "hello");
	c1 = printf("730|%.*s|\n", 0, "hello");
	error(c1, c2);

	c2 = ft_printf("***|%*i|\n", -4, 94827);
	c1 = printf("741|%*i|\n", -4, 94827);
	error(c1, c2);

		printf("\n####################################### Test with NULL:\n");
	printf("\nTest with NULL:\n");
	c1 = printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	c2 = ft_printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	error(c1, c2);

	printf("\n\nTest with \"\":\n");
	c1 = printf(">|%s|%-s|%5s|%-5s|%2.4s|\n", "", "", "", "", "");
	c2 = ft_printf("*|%s|%-s|%5s|%-5s|%2.4s|\n", "", "", "", "", "");
	error(c1, c2);

	c2 = ft_printf("*|{%.*s}\n", -5, "42");
	c1 = printf(">|{%.*s}\n", -5, "42");
	error(c1, c2);




	printf("\n\nTests with *:\n"); //NEGATIVE PRECISION

	c2 = ft_printf("{%%.*s}|* = -5|                           *|{%.*s}\n", -5, "42");
	c1 = printf("{%%.*s}|* = -5|                            |{%.*s}\n", -5, "42");
	error(c1, c2);

	c2 = ft_printf("{%%*s}|* = -5|                            *|{%*s}\n", -5, "42");
	c1 = printf("{%%*s}|* = -5|                             |{%*s}\n", -5, "42");
	error(c1, c2);
	c2 = ft_printf("{%%3.*s}|* = -5|                          *|{%3.*s}\n", -5, "42");
	c1 = printf("{%%3.*s}|* = -5|                           |{%3.*s}\n", -5, "42");
	error(c1, c2);
	c2 = ft_printf("{%%20.*s}|* = -5|                         *|{%020.*s}\n", -5, "42");
	c1 = printf("{%%20.*s}|* = -5|                          |{%020.*s}\n", -5, "42");
	error(c1, c2);
	c2 = ft_printf("{%%-3.*s}|* = -5|                         *|{%-3.*s}\n", -5, "42");
	c1 = printf("{%%-3.*s}|* = -5|                          |{%-3.*s}\n", -5, "42");
	error(c1, c2);
	c2 = ft_printf("|%%*.*s|%%10.15s|* = 10, 15|               *|%*.*s|%10.15s|\n", 10, 15, str, str1);
	c1 = printf("|%%*.*s|%%10.15s|* = 10, 15|                |%*.*s|%10.15s|\n", 10, 15, str, str1);
	error(c1, c2);
	c2 = ft_printf("|%%-*.*s|%%-10.15s|* = 10, 15|             *|%-*.*s|%-10.15s|\n", 10, 15, str, str1);
	c1 = printf("|%%-*.*s|%%-10.15s|* = 10, 15|              |%-*.*s|%-10.15s|\n", 10, 15, str, str1);
	error(c1, c2);




	printf("\n\nNormal tests without warnings:\n");

	c2 = ft_printf("|%%s|%%s|                                  *|%s|%s|\n", str, str1);
	c1 = printf("|%%s|%%s|                                   |%s|%s|\n", str, str1);
	error(c1, c2);
	c2 = ft_printf("|%%-s|%%s|                                 *|%-s|%s|\n", str, str1);
	c1 = printf("|%%-s|%%s|                                  |%-s|%s|\n", str, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%s|%%1s|%%2s|%%5s|%%10s|                    *|%s|%1s|%2s|%5s|%10s|\n", str, str, str, str, str);
	c1 = printf("|%%s|%%1s|%%2s|%%5s|%%10s|                     |%s|%1s|%2s|%5s|%10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%s|%%1s|%%2s|%%5s|%%10s|                    *|%s|%1s|%2s|%5s|%10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%s|%%1s|%%2s|%%5s|%%10s|                     |%s|%1s|%2s|%5s|%10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-s|%%-1s|%%-2s|%%-5s|%%-10s|               *|%-s|%-1s|%-2s|%-5s|%-10s|\n", str, str, str, str, str);
	c1 = printf("|%%-s|%%-1s|%%-2s|%%-5s|%%-10s|                |%-s|%-1s|%-2s|%-5s|%-10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-s|%%-1s|%%-2s|%%-5s|%%-10s|               *|%-s|%-1s|%-2s|%-5s|%-10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-s|%%-1s|%%-2s|%%-5s|%%-10s|                |%-s|%-1s|%-2s|%-5s|%-10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");

	c2 = ft_printf("*|%.s|\n", "Hello");
	c1 = printf(">|%.s|\n", "Hello");
	error(c1, c2);

	c2 = ft_printf("|%%.s|%%.1s|%%.2s|%%.5s|%%.10s|               *|%.s|%.1s|%.2s|%.5s|%.10s|\n", str, str, str, str, str);
	c1 = printf("|%%.s|%%.1s|%%.2s|%%.5s|%%.10s|                |%.s|%.1s|%.2s|%.5s|%.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%.s|%%.1s|%%.2s|%%.5s|%%.10s|               *|%.s|%.1s|%.2s|%.5s|%.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%.s|%%.1s|%%.2s|%%.5s|%%.10s|                |%.s|%.1s|%.2s|%.5s|%.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%--s|%%--1s|%%--2s|%%--5s|%%--10s|          *|%--s|%--1s|%--2s|%--5s|%--10s|\n", str, str, str, str, str);
	c1 = printf("|%%--s|%%--1s|%%--2s|%%--5s|%%--10s|           |%--s|%--1s|%--2s|%--5s|%--10s|\n", str, str, str, str, str);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-.s|%%-.1s|%%-.2s|%%-.5s|%%-.10s|          *|%-.s|%-.1s|%-.2s|%-.5s|%-.10s|\n", str, str, str, str, str);
	c1 = printf("|%%-.s|%%-.1s|%%-.2s|%%-.5s|%%-.10s|           |%-.s|%-.1s|%-.2s|%-.5s|%-.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-.s|%%-.1s|%%-.2s|%%-.5s|%%-.10s|          *|%-.s|%-.1s|%-.2s|%-.5s|%-.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-.s|%%-.1s|%%-.2s|%%-.5s|%%-.10s|           |%-.s|%-.1s|%-.2s|%-.5s|%-.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%.s|%%1.s|%%2.s|%%5.s|%%10.s|               *|%.s|%1.s|%2.s|%5.s|%10.s|\n", str, str, str, str, str);
	c1 = printf("|%%.s|%%1.s|%%2.s|%%5.s|%%10.s|                |%.s|%1.s|%2.s|%5.s|%10.s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%.s|%%1.s|%%2.s|%%5.s|%%10.s|               *|%.s|%1.s|%2.s|%5.s|%10.s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%.s|%%1.s|%%2.s|%%5.s|%%10.s|                |%.s|%1.s|%2.s|%5.s|%10.s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-.s|%%-1.s|%%-2.s|%%-5.s|%%-10.s|          *|%-.s|%-1.s|%-2.s|%-5.s|%-10.s|\n", str, str, str, str, str);
	c1 = printf("|%%-.s|%%-1.s|%%-2.s|%%-5.s|%%-10.s|           |%-.s|%-1.s|%-2.s|%-5.s|%-10.s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-.s|%%-1.s|%%-2.s|%%-5.s|%%-10.s|          *|%-.s|%-1.s|%-2.s|%-5.s|%-10.s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-.s|%%-1.s|%%-2.s|%%-5.s|%%-10.s|           |%-.s|%-1.s|%-2.s|%-5.s|%-10.s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%.0s|%%1.0s|%%2.0s|%%5.0s|%%10.0s|          *|%.0s|%1.0s|%2.0s|%5.0s|%10.0s|\n", str, str, str, str, str);
	c1 = printf("|%%.0s|%%1.0s|%%2.0s|%%5.0s|%%10.0s|           |%.0s|%1.0s|%2.0s|%5.0s|%10.0s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%.0s|%%1.0s|%%2.0s|%%5.0s|%%10.0s|          *|%.0s|%1.0s|%2.0s|%5.0s|%10.0s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%.0s|%%1.0s|%%2.0s|%%5.0s|%%10.0s|           |%.0s|%1.0s|%2.0s|%5.0s|%10.0s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-.0s|%%-1.0s|%%-2.0s|%%-5.0s|%%-10.0s|     *|%-.0s|%-1.0s|%-2.0s|%-5.0s|%-10.0s|\n", str, str, str, str, str);
	c1 = printf("|%%-.0s|%%-1.0s|%%-2.0s|%%-5.0s|%%-10.0s|      |%-.0s|%-1.0s|%-2.0s|%-5.0s|%-10.0s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-.0s|%%-1.0s|%%-2.0s|%%-5.0s|%%-10.0s|     *|%-.0s|%-1.0s|%-2.0s|%-5.0s|%-10.0s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-.0s|%%-1.0s|%%-2.0s|%%-5.0s|%%-10.0s|      |%-.0s|%-1.0s|%-2.0s|%-5.0s|%-10.0s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%1.s|%%1.1s|%%1.2s|%%1.5s|%%1.10s|          *|%1.s|%1.1s|%1.2s|%1.5s|%1.10s|\n", str, str, str, str, str);
	c1 = printf("|%%1.s|%%1.1s|%%1.2s|%%1.5s|%%1.10s|           |%1.s|%1.1s|%1.2s|%1.5s|%1.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%1.s|%%1.1s|%%1.2s|%%1.5s|%%1.10s|          *|%1.s|%1.1s|%1.2s|%1.5s|%1.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%1.s|%%1.1s|%%1.2s|%%1.5s|%%1.10s|           |%1.s|%1.1s|%1.2s|%1.5s|%1.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-1.s|%%-1.1s|%%-1.2s|%%-1.5s|%%-1.10s|     *|%-1.s|%-1.1s|%-1.2s|%-1.5s|%-1.10s|\n", str, str, str, str, str);
	c1 = printf("|%%-1.s|%%-1.1s|%%-1.2s|%%-1.5s|%%-1.10s|      |%-1.s|%-1.1s|%-1.2s|%-1.5s|%-1.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-1.s|%%-1.1s|%%-1.2s|%%-1.5s|%%-1.10s|     *|%-1.s|%-1.1s|%-1.2s|%-1.5s|%-1.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-1.s|%%-1.1s|%%-1.2s|%%-1.5s|%%-1.10s|      |%-1.s|%-1.1s|%-1.2s|%-1.5s|%-1.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%5.s|%%5.1s|%%5.2s|%%5.5s|%%5.10s|          *|%5.s|%5.1s|%5.2s|%5.5s|%5.10s|\n", str, str, str, str, str);
	c1 = printf("|%%5.s|%%5.1s|%%5.2s|%%5.5s|%%5.10s|           |%5.s|%5.1s|%5.2s|%5.5s|%5.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%5.s|%%5.1s|%%5.2s|%%5.5s|%%5.10s|          *|%5.s|%5.1s|%5.2s|%5.5s|%5.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%5.s|%%5.1s|%%5.2s|%%5.5s|%%5.10s|           |%5.s|%5.1s|%5.2s|%5.5s|%5.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-5.s|%%-5.1s|%%-5.2s|%%-5.5s|%%-5.10s|     *|%-5.s|%-5.1s|%-5.2s|%-5.5s|%-5.10s|\n", str, str, str, str, str);
	c1 = printf("|%%-5.s|%%-5.1s|%%-5.2s|%%-5.5s|%%-5.10s|      |%-5.s|%-5.1s|%-5.2s|%-5.5s|%-5.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-5.s|%%-5.1s|%%-5.2s|%%-5.5s|%%-5.10s|     *|%-5.s|%-5.1s|%-5.2s|%-5.5s|%-5.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-5.s|%%-5.1s|%%-5.2s|%%-5.5s|%%-5.10s|      |%-5.s|%-5.1s|%-5.2s|%-5.5s|%-5.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%10.s|%%10.1s|%%10.2s|%%10.5s|%%10.10s|     *|%10.s|%10.1s|%10.2s|%10.5s|%10.10s|\n", str, str, str, str, str);
	c1 = printf("|%%10.s|%%10.1s|%%10.2s|%%10.5s|%%10.10s|      |%10.s|%10.1s|%10.2s|%10.5s|%10.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%10.s|%%10.1s|%%10.2s|%%10.5s|%%10.10s|     *|%10.s|%10.1s|%10.2s|%10.5s|%10.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%10.s|%%10.1s|%%10.2s|%%10.5s|%%10.10s|      |%10.s|%10.1s|%10.2s|%10.5s|%10.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-10.s|%%-10.1s|%%-10.2s|%%-10.5s|%%-10.10s|*|%-10.s|%-10.1s|%-10.2s|%-10.5s|%-10.10s|\n", str, str, str, str, str);
	c1 = printf("|%%-10.s|%%-10.1s|%%-10.2s|%%-10.5s|%%-10.10s| |%-10.s|%-10.1s|%-10.2s|%-10.5s|%-10.10s|\n", str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-10.s|%%-10.1s|%%-10.2s|%%-10.5s|%%-10.10s|*|%-10.s|%-10.1s|%-10.2s|%-10.5s|%-10.10s|\n", str1, str1, str1, str1, str1);
	c1 = printf("|%%-10.s|%%-10.1s|%%-10.2s|%%-10.5s|%%-10.10s| |%-10.s|%-10.1s|%-10.2s|%-10.5s|%-10.10s|\n", str1, str1, str1, str1, str1);
	error(c1, c2);





	// printf(MAGENTA"\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------"RESET"\n\n");

	// printf("Test with 0:\n");
	// c1 = printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	// c2 = ft_printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	// error(c1, c2);

	// // printf("\n");
	// // c2 = ft_printf("|%%5-s|%%5-1s|%%5-2s|%%5-5s|%%5-10s|          *|%5-s|%5-1s|%5-2s|%5-5s|%5-10s|\n", str, str, str, str, str);
	// // c1 = printf("|%%5-s|%%5-1s|%%5-2s|%%5-5s|%%5-10s|           |%5-s|%5-1s|%5-2s|%5-5s|%5-10s|\n", str, str, str, str, str);
	// // error(c1, c2);

	// // printf("\n");
	// // c2 = ft_printf("|%%-5-s|%%-5-1s|%%-5-2s|%%-5-5s|%%-5-10s|     *|%-5-s|%-5-1s|%-5-2s|%-5-5s|%-5-10s|\n", str, str, str, str, str);
	// // c1 = printf("|%%-5-s|%%-5-1s|%%-5-2s|%%-5-5s|%%-5-10s|      |%-5-s|%-5-1s|%-5-2s|%-5-5s|%-5-10s|\n", str, str, str, str, str);
	// // error(c1, c2);

	// printf("\n");
	// c2 = ft_printf("|%%-0-s|%%-0-1s|%%-0-2s|%%-0-5s|%%-0-10s|     *|%-0-s|%-0-1s|%-0-2s|%-0-5s|%-0-10s|\n", str, str, str, str, str);
	// c1 = printf("|%%-0-s|%%-0-1s|%%-0-2s|%%-0-5s|%%-0-10s|      |%-0-s|%-0-1s|%-0-2s|%-0-5s|%-0-10s|\n", str, str, str, str, str);
	// error(c1, c2);

	// // printf("\n");
	// // c2 = ft_printf("|%%.-s|%%.-1s|%%.-2s|%%.-5s|%%.-10s|          *|%.-s|%.-1s|%.-2s|%.-5s|%.-10s|\n", str, str, str, str, str);
	// // c1 = printf("|%%.-s|%%.-1s|%%.-2s|%%.-5s|%%.-10s|           |%.-s|%.-1s|%.-2s|%.-5s|%.-10s|\n", str, str, str, str, str);
	// // error(c1, c2);

	// printf("\n");
	// c2 = ft_printf("|%%0s|%%09s|%%00s|%%0.s|%%0.0s|%%0.7s|         *|%0s|%09s|%00s|%0.s|%0.0s|%0.7s|\n", str, str, str, str, str, str);
	// c1 = printf("|%%0s|%%09s|%%00s|%%0.s|%%0.0s|%%0.7s|          |%0s|%09s|%00s|%0.s|%0.0s|%0.7s|\n", str, str, str, str, str, str);
	// error(c1, c2);
	// c2 = ft_printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|   *|%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str, str, str, str, str, str);
	// c1 = printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|    |%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str, str, str, str, str, str);
	// error(c1, c2);
	// c2 = ft_printf("|%%0s|%%05s|%%00s|%%0.s|%%0.0s|%%0.7s|         *|%0s|%05s|%00s|%0.s|%0.0s|%0.7s|\n", str1, str1, str1, str1, str1, str1);
	// c1 = printf("|%%0s|%%05s|%%00s|%%0.s|%%0.0s|%%0.7s|          |%0s|%05s|%00s|%0.s|%0.0s|%0.7s|\n", str1, str1, str1, str1, str1, str1);
	// error(c1, c2);
	// c2 = ft_printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|   *|%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str1, str1, str1, str1, str1, str1);
	// c1 = printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|    |%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str1, str1, str1, str1, str1, str1);
	// error(c1, c2);
}
void	pointer_github_test()
{
	int c1;
	int c2;

	printf(GREEN"\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_ADDRESS"RESET"\n\n");
	char a;
	char *ptr = NULL;
	a = 0;
	printf("\n\nTest with NULL:\n");
	c1 = printf(">|%p|%5p|%10p|%.p|\n", NULL, NULL, NULL, NULL);
	c2 = ft_printf("*|%p|%5p|%10p|%.p|\n", NULL, NULL, NULL, NULL);
	error(c1, c2);

	printf("\n\nTest with 0:\n");
	c1 = printf("|%p|%5p|%10p|%.p|\n", 0, 0, 0, 0);
	c2 = ft_printf("|%p|%5p|%10p|%.p|\n", 0, 0, 0, 0);
	error(c1, c2);

	printf("\n\nTest with 2:\n");
	c1 = printf("|%p|%5p|%10p|%.p|\n", 12, 12, 12, 12);
	c2 = ft_printf("|%p|%5p|%10p|%.p|\n", 12, 12, 12, 12);
	error(c1, c2);

	printf("\n\nNormal tests without warnings:\n");
	c1 = printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", &a, &a, &a, &a, &a, &a);
	c2 = ft_printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", &a, &a, &a, &a, &a, &a);
	error(c1, c2);

	c1 = printf("|%.p|%.10p|%.20p|%.5p|%-20.6p|-%6.20p|\n", &a, &a, &a, &a, &a, &a);
	c2 = ft_printf("|%.p|%.10p|%.20p|%.5p|%-20.6p|-%6.20p|\n", &a, &a, &a, &a, &a, &a);
	error(c1, c2);


	printf("\n");
	c1 = printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	c2 = ft_printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	//c2 = ft_printf("|%p\n", ptr);
	error(c1, c2);

	printf("\n");
	c1 = printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	c2 = ft_printf("|%p|%10p|%20p|%-20p|%-10p|-%p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	error(c1, c2);
	printf("\n");
	c1 = printf("|%.p|%p|%3p|%5p|\n", NULL, NULL, NULL, NULL);
	c2 = ft_printf("|%.p|%p|%3p|%5p|\n", NULL, NULL, NULL, NULL);
	error(c1, c2);

	printf("\n\nUndefined behavior tests:\n");
	c1 = printf("|%0p|%010p|%020p|%0-20p|%0-10p|-%0p|\n", &a, &a, &a, &a, &a, &a);
	c2 = ft_printf("|%0p|%010p|%020p|%0-20p|%0-10p|-%0p|\n", &a, &a, &a, &a, &a, &a);
	error(c1, c2);
	printf("\n");
	c1 = printf("|%0p|%010p|%020p|%0-20p|%0-10p|-%0p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	c2 = ft_printf("|%0p|%010p|%020p|%0-20p|%0-10p|-%0p|\n", ptr, ptr, ptr, ptr, ptr, ptr);
	error(c1, c2);
	printf("\n");
	c1 = printf("|%.p|%.3p|%.5p|%5.10p|\n", NULL, NULL, NULL, NULL);
	c2 = ft_printf("|%.p|%.3p|%.5p|%5.10p|\n", NULL, NULL, NULL, NULL);
	error(c1, c2);
}
void	int_github_test()
{
	int c1;
	int c2;

	printf(GREEN"\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_SIGNED_NUMBERS"RESET"\n\n");

	printf("Test min max\n");
	c1 = printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", 2147483647, 2147483647, 2147483647, 2147483647);
	c2 = ft_printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", 2147483647, 2147483647, 2147483647, 2147483647);
	error(c1, c2);
	c1 = printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", -2147483648, -2147483648, -2147483648, -2147483648);
	c2 = ft_printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", -2147483648, -2147483648, -2147483648, -2147483648);
	error(c1, c2);
	printf("\n");

	printf("Test larger min max\n");
	c1 = printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	c2 = ft_printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	error(c1, c2);
	c1 = printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	c2 = ft_printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	error(c1, c2);
	c1 = printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	c2 = ft_printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	error(c1, c2);
	c1 = printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", -2147483650, -2147483650, -2147483650, -2147483650);
	c2 = ft_printf("|%%i|%%15i|%%-15i|%%015i|                |%i|%15i|%-15i|%015i|\n", -2147483650, -2147483650, -2147483650, -2147483650);
	error(c1, c2);
	printf("\n");

	printf("Normal tests\n");
	c1 = printf("{%%*d}|* = -5|                              |{%*d}\n", -5, 42);
	c2 = ft_printf("{%%*d}|* = -5|                             *|{%*d}\n", -5, 42);
	error(c1, c2);
	c1 = printf("%%05.*i|* = -15|                            |{%05.*d}\n", -15, 42);
	c2 = ft_printf("%%05.*i|* = -15|                           *|{%05.*d}\n", -15, 42);
	error(c1, c2);

	c1 = printf("%%d_%%0d_%%3d_%%5d_%%10i|                       |%i|%0i|%3i|%5i|%10i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%d_%%0d_%%3d_%%5d_%%10i|                      *|%i|%0i|%3i|%5i|%10i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%d_%%0d_%%3d_%%5d_%%10i|                       |%i|%0i|%3i|%5i|%10i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%d_%%0d_%%3d_%%5d_%%10i|                      *|%i|%0i|%3i|%5i|%10i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%d_%%0d_%%3d_%%5d_%%10i|                       |%i|%0i|%3i|%5i|%10i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%d_%%0d_%%3d_%%5d_%%10i|                      *|%i|%0i|%3i|%5i|%10i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-d_%%-0d_%%-3d_%%-5d_%%-10i|                  |%-i|%-0i|%-3i|%-5i|%-10i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-d_%%-0d_%%-3d_%%-5d_%%-10i|                 *|%-i|%-0i|%-3i|%-5i|%-10i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-d_%%-0d_%%-3d_%%-5d_%%-10i|                  |%-i|%-0i|%-3i|%-5i|%-10i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-d_%%-0d_%%-3d_%%-5d_%%-10i|                 *|%-i|%-0i|%-3i|%-5i|%-10i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-d_%%-0d_%%-3d_%%-5d_%%-10i|                  |%-i|%-0i|%-3i|%-5i|%-10i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-d_%%-0d_%%-3d_%%-5d_%%-10i|                 *|%-i|%-0i|%-3i|%-5i|%-10i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02d_%%03d_%%05d_%%07d_%%010i|                 |%02i|%03i|%05i|%07i|%010i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02d_%%03d_%%05d_%%07d_%%010i|                *|%02i|%03i|%05i|%07i|%010i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02d_%%03d_%%05d_%%07d_%%010i|                 |%02i|%03i|%05i|%07i|%010i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02d_%%03d_%%05d_%%07d_%%010i|                *|%02i|%03i|%05i|%07i|%010i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02d_%%03d_%%05d_%%07d_%%010i|                 |%02i|%03i|%05i|%07i|%010i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02d_%%03d_%%05d_%%07d_%%010i|                *|%02i|%03i|%05i|%07i|%010i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.0d_%%0.0d_%%3.0d_%%5.0d_%%10.0i|             |%.0i|%0.0i|%3.0i|%5.0i|%10.0i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.0d_%%0.0d_%%3.0d_%%5.0d_%%10.0i|            *|%.0i|%0.0i|%3.0i|%5.0i|%10.0i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.0d_%%0.0d_%%3.0d_%%5.0d_%%10.0i|             |%.0i|%0.0i|%3.0i|%5.0i|%10.0i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.0d_%%0.0d_%%3.0d_%%5.0d_%%10.0i|            *|%.0i|%0.0i|%3.0i|%5.0i|%10.0i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%d.0_%%0.0d_%%3.0d_%%5.0d_%%10.0i|             |%.0i|%0.0i|%3.0i|%5.0i|%10.0i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%d.0_%%0.0d_%%3.0d_%%5.0d_%%10.0i|            *|%.0i|%0.0i|%3.0i|%5.0i|%10.0i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.0d_%%-0.0d_%%-3.0d_%%-5.0d_%%-10.0i|        |%-.0i|%-0.0i|%-3.0i|%-5.0i|%-10.0i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.0d_%%-0.0d_%%-3.0d_%%-5.0d_%%-10.0i|       *|%-.0i|%-0.0i|%-3.0i|%-5.0i|%-10.0i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.0d_%%-0.0d_%%-3.0d_%%-5.0d_%%-10.0i|        |%-.0i|%-0.0i|%-3.0i|%-5.0i|%-10.0i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.0d_%%-0.0d_%%-3.0d_%%-5.0d_%%-10.0i|       *|%-.0i|%-0.0i|%-3.0i|%-5.0i|%-10.0i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.0d_%%-0.0d_%%-3.0d_%%-5.0d_%%-10.0i|        |%-.0i|%-0.0i|%-3.0i|%-5.0i|%-10.0i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.0d_%%-0.0d_%%-3.0d_%%-5.0d_%%-10.0i|       *|%-.0i|%-0.0i|%-3.0i|%-5.0i|%-10.0i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	c1 = printf("%%.0d_%%0-.0d_%%03-.0d_%%0-5.0d_%%10-.0i|        |%-.0i|%-0.0i|%-3.0i|%-5.0i|%-10.0i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.0d_%%0-.0d_%%03-.0d_%%0-5.0d_%%10-.0i|       *|%-.0i|%-0.0i|%-3.0i|%-5.0i|%-10.0i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.0d_%%03.0d_%%05.0d_%%07.0d_%%010.0i|       |%02.0i|%03.0i|%05.0i|%07.0i|%010.0i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.0d_%%03.0d_%%05.0d_%%07.0d_%%010.0i|      *|%02.0i|%03.0i|%05.0i|%07.0i|%010.0i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.0d_%%03.0d_%%05.0d_%%07.0d_%%010.0i|       |%02.0i|%03.0i|%05.0i|%07.0i|%010.0i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.0d_%%03.0d_%%05.0d_%%07.0d_%%010.0i|      *|%02.0i|%03.0i|%05.0i|%07.0i|%010.0i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.0d_%%03.0d_%%05.0d_%%07.0d_%%010.0i|       |%02.0i|%03.0i|%05.0i|%07.0i|%010.0i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.0d_%%03.0d_%%05.0d_%%07.0d_%%010.0i|      *|%02.0i|%03.0i|%05.0i|%07.0i|%010.0i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.3d_%%0.3d_%%3.3d_%%5.3d_%%10.3i|             |%.3i|%0.3i|%3.3i|%5.3i|%10.3i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.3d_%%0.3d_%%3.3d_%%5.3d_%%10.3i|            *|%.3i|%0.3i|%3.3i|%5.3i|%10.3i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.3d_%%0.3d_%%3.3d_%%5.3d_%%10.3i|             |%.3i|%0.3i|%3.3i|%5.3i|%10.3i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.3d_%%0.3d_%%3.3d_%%5.3d_%%10.3i|            *|%.3i|%0.3i|%3.3i|%5.3i|%10.3i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.3d_%%0.3d_%%3.3d_%%5.3d_%%10.4i|             |%.3i|%0.3i|%3.3i|%5.3i|%10.4i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.3d_%%0.3d_%%3.3d_%%5.3d_%%10.4i|            *|%.3i|%0.3i|%3.3i|%5.3i|%10.4i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.2d_%%-0.2d_%%-3.2d_%%-5.2d_%%-10.2i|        |%-.2i|%-0.2i|%-3.2i|%-5.2i|%-10.2i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.2d_%%-0.2d_%%-3.2d_%%-5.2d_%%-10.2i|       *|%-.2i|%-0.2i|%-3.2i|%-5.2i|%-10.2i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.2d_%%-0.2d_%%-3.2d_%%-5.2d_%%-10.2i|        |%-.2i|%-0.2i|%-3.2i|%-5.2i|%-10.2i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.2d_%%-0.2d_%%-3.2d_%%-5.2d_%%-10.2i|       *|%-.2i|%-0.2i|%-3.2i|%-5.2i|%-10.2i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.2d_%%-0.2d_%%-3.2d_%%-5.2d_%%-10.2i|        |%-.2i|%-0.2i|%-3.2i|%-5.2i|%-10.2i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.2d_%%-0.2d_%%-3.2d_%%-5.2d_%%-10.2i|       *|%-.2i|%-0.2i|%-3.2i|%-5.2i|%-10.2i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.2d_%%03.2d_%%05.2d_%%07.2d_%%010.2i|       |%02.2i|%03.2i|%05.2i|%07.2i|%010.2i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.2d_%%03.2d_%%05.2d_%%07.2d_%%010.2i|      *|%02.2i|%03.2i|%05.2i|%07.2i|%010.2i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.2d_%%03.2d_%%05.2d_%%07.2d_%%010.2i|       |%02.2i|%03.2i|%05.2i|%07.2i|%010.2i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.2d_%%03.2d_%%05.2d_%%07.2d_%%010.2i|      *|%02.2i|%03.2i|%05.2i|%07.2i|%010.2i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.2d_%%03.2d_%%05.2d_%%07.2d_%%010.2i|       |%02.2i|%03.2i|%05.2i|%07.2i|%010.2i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.2d_%%03.2d_%%05.2d_%%07.2d_%%010.2i|      *|%02.2i|%03.2i|%05.2i|%07.2i|%010.2i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.5d_%%0.5d_%%3.5d_%%5.5d_%%10.5i|             |%.5i|%0.5i|%3.5i|%5.5i|%10.5i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.5d_%%0.5d_%%3.5d_%%5.5d_%%10.5i|            *|%.5i|%0.5i|%3.5i|%5.5i|%10.5i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.5d_%%0.5d_%%3.5d_%%5.5d_%%10.5i|             |%.5i|%0.5i|%3.5i|%5.5i|%10.5i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.5d_%%0.5d_%%3.5d_%%5.5d_%%10.5i|            *|%.5i|%0.5i|%3.5i|%5.5i|%10.5i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.5d_%%0.5d_%%3.5d_%%5.5d_%%6.5i|              |%.5i|%0.5i|%3.5i|%5.5i|%6.5i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.5d_%%0.5d_%%3.5d_%%5.5d_%%6.5i|             *|%.5i|%0.5i|%3.5i|%5.5i|%6.5i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.5d_%%-0.5d_%%-3.5d_%%-5.5d_%%-10.5i|        |%-.5i|%-0.5i|%-3.5i|%-5.5i|%-10.5i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.5d_%%-0.5d_%%-3.5d_%%-5.5d_%%-10.5i|       *|%-.5i|%-0.5i|%-3.5i|%-5.5i|%-10.5i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.5d_%%-0.5d_%%-3.5d_%%-5.5d_%%-10.5i|        |%-.5i|%-0.5i|%-3.5i|%-5.5i|%-10.5i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.5d_%%-0.5d_%%-3.5d_%%-5.5d_%%-10.5i|       *|%-.5i|%-0.5i|%-3.5i|%-5.5i|%-10.5i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.5d_%%-0.5d_%%-3.5d_%%-5.5d_%%-10.5i|        |%-.5i|%-0.5i|%-3.5i|%-5.5i|%-10.5i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.5d_%%-0.5d_%%-3.5d_%%-5.5d_%%-10.5i|       *|%-.5i|%-0.5i|%-3.5i|%-5.5i|%-10.5i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.5d_%%03.5d_%%05.5d_%%07.5d_%%010.5i|       |%02.5i|%03.5i|%05.5i|%07.5i|%010.5i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.5d_%%03.5d_%%05.5d_%%07.5d_%%010.5i|      *|%02.5i|%03.5i|%05.5i|%07.5i|%010.5i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.5d_%%03.5d_%%05.5d_%%07.5d_%%010.5i|       |%02.5i|%03.5i|%05.5i|%07.5i|%010.5i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.5d_%%03.5d_%%05.5d_%%07.5d_%%010.5i|      *|%02.5i|%03.5i|%05.5i|%07.5i|%010.5i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.5d_%%03.5d_%%05.5d_%%07.5d_%%010.5i|       |%02.5i|%03.5i|%05.5i|%07.5i|%010.5i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.5d_%%03.5d_%%05.5d_%%07.5d_%%010.5i|      *|%02.5i|%03.5i|%05.5i|%07.5i|%010.5i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%0-2.5d_%%0-3.5d_%%0-5.5d_%%0-7.5d_%%0-10.5i|  |%0-2.5i|%0-3.5i|%0-5.5i|%0-7.5i|%0-10.5i|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%0-2.5d_%%0-3.5d_%%0-5.5d_%%0-7.5d_%%0-10.5i| *|%0-2.5i|%0-3.5i|%0-5.5i|%0-7.5i|%0-10.5i|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%0-2.5d_%%0-3.5d_%%0-5.5d_%%0-7.5d_%%0-10.5i|  |%0-2.5i|%0-3.5i|%0-5.5i|%0-7.5i|%0-10.5i|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%0-2.5d_%%0-3.5d_%%0-5.5d_%%0-7.5d_%%0-10.5i| *|%0-2.5i|%0-3.5i|%0-5.5i|%0-7.5i|%0-10.5i|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%0-2.5d_%%0-3.5d_%%0-5.5d_%%0-7.5d_%%0-10.5i|  |%0-2.5i|%0-3.5i|%0-5.5i|%0-7.5i|%0-10.5i|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%0-2.5d_%%0-3.5d_%%0-5.5d_%%0-7.5d_%%0-10.5i| *|%0-2.5i|%0-3.5i|%0-5.5i|%0-7.5i|%0-10.5i|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	// printf(MAGENTA"\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------"RESET"\n\n");

	// c1 = printf("%%0-8.3i|%%0-8.5i|%%10|                         |%0-8.3i|%0-8.5i|%10|\n", -8473);
	// c2 = ft_printf("%%0-8.3i|%%0-8.5i|%%10|                        *|%0-8.3i|%0-8.5i|%10|\n", -8473);
	// error(c1, c2);
	// printf("\n");

	// c1 = printf("%%2-2.5d_%%2-3.5d_%%2-5.5d_%%2-7.5d_%%2-10.5i|    |%2-2.5i|%2-3.5i|%2-5.5i|%2-7.5i|%2-10.5i|\n", 0, 0, 0, 0, 0);
	// c2 = ft_printf("%%2-2.5d_%%2-3.5d_%%2-5.5d_%%2-7.5d_%%2-10.5i|   *|%2-2.5i|%2-3.5i|%2-5.5i|%2-7.5i|%2-10.5i|\n", 0, 0, 0, 0, 0);
	// error(c1, c2);
	// c1 = printf("%%2-2.5d_%%2-3.5d_%%2-5.5d_%%2-7.5d_%%2-10.5i|    |%2-2.5i|%2-3.5i|%2-5.5i|%2-7.5i|%2-10.5i|\n", 234, 234, 234, 234, 234);
	// c2 = ft_printf("%%2-2.5d_%%2-3.5d_%%2-5.5d_%%2-7.5d_%%2-10.5i|   *|%2-2.5i|%2-3.5i|%2-5.5i|%2-7.5i|%2-10.5i|\n", 234, 234, 234, 234, 234);
	// error(c1, c2);
	// c1 = printf("%%2-2.5d_%%2-3.5d_%%2-5.5d_%%2-7.5d_%%2-10.5i|    |%2-2.5i|%2-3.5i|%2-5.5i|%2-7.5i|%2-10.5i|\n", -234, -234, -234, -234, -234);
	// c2 = ft_printf("%%2-2.5d_%%2-3.5d_%%2-5.5d_%%2-7.5d_%%2-10.5i|   *|%2-2.5i|%2-3.5i|%2-5.5i|%2-7.5i|%2-10.5i|\n", -234, -234, -234, -234, -234);
	// error(c1, c2);
	// printf("\n");
}
void	hex_github_test()
{
		int c1;
	int c2;

	printf(GREEN"\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_HEX\n\n");
	printf("\n\n\n\n______________________TEST_HEX___________________________________"RESET"\n\n\n");



	printf("Test min max\n");
	c1 = printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", 2147483647, 2147483647, 2147483647, 2147483647);
	c2 = ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", 2147483647, 2147483647, 2147483647, 2147483647);
	error(c1, c2);
	c1 = printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483648, -2147483648, -2147483648, -2147483648);
	c2 = ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483648, -2147483648, -2147483648, -2147483648);
	error(c1, c2);
	printf("\n");

	printf("Test larger min max\n");

	c1 = printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	c2 = ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	error(c1, c2);
	c1 = printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	c2 = ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	error(c1, c2);
	c1 = printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	c2 = ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	error(c1, c2);
	c1 = printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483650, -2147483650, -2147483650, -2147483650);
	c2 = ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", -2147483650, -2147483650, -2147483650, -2147483650);
	error(c1, c2);
	c1 = printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	c2 = ft_printf("|%%x|%%15x|%%-15x|%%015x|                |%x|%15x|%-15x|%015x|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	error(c1, c2);
	printf("\n");

	printf("\nNormal tests\n");
	c1 = printf("%%x_%%0x_%%3x_%%5x_%%10x|                    |%x|%0x|%3x|%5x|%10x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%x_%%0x_%%3x_%%5x_%%10x|                   *|%x|%0x|%3x|%5x|%10x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%x_%%0x_%%3x_%%5x_%%10x|                    |%x|%0x|%3x|%5x|%10x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%x_%%0x_%%3x_%%5x_%%10x|                   *|%x|%0x|%3x|%5x|%10x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%x_%%0x_%%3x_%%5x_%%10x|                    |%x|%0x|%3x|%5x|%10x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%x_%%0x_%%3x_%%5x_%%10x|                   *|%x|%0x|%3x|%5x|%10x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-x_%%-0x_%%-3x_%%-5x_%%-10x|               |%-x|%-0x|%-3x|%-5x|%-10x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-x_%%-0x_%%-3x_%%-5x_%%-10x|              *|%-x|%-0x|%-3x|%-5x|%-10x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-x_%%-0x_%%-3x_%%-5x_%%-10x|               |%-x|%-0x|%-3x|%-5x|%-10x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-x_%%-0x_%%-3x_%%-5x_%%-10x|              *|%-x|%-0x|%-3x|%-5x|%-10x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-x_%%-0x_%%-3x_%%-5x_%%-10x|               |%-x|%-0x|%-3x|%-5x|%-10x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-x_%%-0x_%%-3x_%%-5x_%%-10x|              *|%-x|%-0x|%-3x|%-5x|%-10x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02x_%%03x_%%05x_%%07x_%%010x|              |%02x|%03x|%05x|%07x|%010x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02x_%%03x_%%05x_%%07x_%%010x|             *|%02x|%03x|%05x|%07x|%010x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02x_%%03x_%%05x_%%07x_%%010x|              |%02x|%03x|%05x|%07x|%010x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02x_%%03x_%%05x_%%07x_%%010x|             *|%02x|%03x|%05x|%07x|%010x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02x_%%03x_%%05x_%%07x_%%010x|              |%02x|%03x|%05x|%07x|%010x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02x_%%03x_%%05x_%%07x_%%010x|             *|%02x|%03x|%05x|%07x|%010x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.0x_%%0.0x_%%3.0x_%%5.0x_%%10.0x|          |%.0x|%0.0x|%3.0x|%5.0x|%10.0x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.0x_%%0.0x_%%3.0x_%%5.0x_%%10.0x|         *|%.0x|%0.0x|%3.0x|%5.0x|%10.0x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.0x_%%0.0x_%%3.0x_%%5.0x_%%10.0x|          |%.0x|%0.0x|%3.0x|%5.0x|%10.0x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.0x_%%0.0x_%%3.0x_%%5.0x_%%10.0x|         *|%.0x|%0.0x|%3.0x|%5.0x|%10.0x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%x.0_%%0.0x_%%3.0x_%%5.0x_%%10.0x|          |%.0x|%0.0x|%3.0x|%5.0x|%10.0x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%x.0_%%0.0x_%%3.0x_%%5.0x_%%10.0x|         *|%.0x|%0.0x|%3.0x|%5.0x|%10.0x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.0x_%%-0.0x_%%-3.0x_%%-5.0x_%%-10.0x|     |%-.0x|%-0.0x|%-3.0x|%-5.0x|%-10.0x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.0x_%%-0.0x_%%-3.0x_%%-5.0x_%%-10.0x|    *|%-.0x|%-0.0x|%-3.0x|%-5.0x|%-10.0x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.0x_%%-0.0x_%%-3.0x_%%-5.0x_%%-10.0x|     |%-.0x|%-0.0x|%-3.0x|%-5.0x|%-10.0x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.0x_%%-0.0x_%%-3.0x_%%-5.0x_%%-10.0x|    *|%-.0x|%-0.0x|%-3.0x|%-5.0x|%-10.0x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.0x_%%-0.0x_%%-3.0x_%%-5.0x_%%-10.0x|     |%-.0x|%-0.0x|%-3.0x|%-5.0x|%-10.0x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.0x_%%-0.0x_%%-3.0x_%%-5.0x_%%-10.0x|    *|%-.0x|%-0.0x|%-3.0x|%-5.0x|%-10.0x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.0x_%%03.0x_%%05.0x_%%07.0x_%%010.0x|    |%02.0x|%03.0x|%05.0x|%07.0x|%010.0x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.0x_%%03.0x_%%05.0x_%%07.0x_%%010.0x|   *|%02.0x|%03.0x|%05.0x|%07.0x|%010.0x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.0x_%%03.0x_%%05.0x_%%07.0x_%%010.0x|    |%02.0x|%03.0x|%05.0x|%07.0x|%010.0x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.0x_%%03.0x_%%05.0x_%%07.0x_%%010.0x|   *|%02.0x|%03.0x|%05.0x|%07.0x|%010.0x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.0x_%%03.0x_%%05.0x_%%07.0x_%%010.0x|    |%02.0x|%03.0x|%05.0x|%07.0x|%010.0x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.0x_%%03.0x_%%05.0x_%%07.0x_%%010.0x|   *|%02.0x|%03.0x|%05.0x|%07.0x|%010.0x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.3x_%%0.3x_%%3.3x_%%5.3x_%%10.3x|          |%.3x|%0.3x|%3.3x|%5.3x|%10.3x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.3x_%%0.3x_%%3.3x_%%5.3x_%%10.3x|         *|%.3x|%0.3x|%3.3x|%5.3x|%10.3x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.3x_%%0.3x_%%3.3x_%%5.3x_%%10.3x|          |%.3x|%0.3x|%3.3x|%5.3x|%10.3x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.3x_%%0.3x_%%3.3x_%%5.3x_%%10.3x|         *|%.3x|%0.3x|%3.3x|%5.3x|%10.3x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.3x_%%0.3x_%%3.3x_%%5.3x_%%10.4x|          |%.3x|%0.3x|%3.3x|%5.3x|%10.4x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.3x_%%0.3x_%%3.3x_%%5.3x_%%10.4x|         *|%.3x|%0.3x|%3.3x|%5.3x|%10.4x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.2x_%%-0.2x_%%-3.2x_%%-5.2x_%%-10.2x|     |%-.2x|%-0.2x|%-3.2x|%-5.2x|%-10.2x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.2x_%%-0.2x_%%-3.2x_%%-5.2x_%%-10.2x|    *|%-.2x|%-0.2x|%-3.2x|%-5.2x|%-10.2x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.2x_%%-0.2x_%%-3.2x_%%-5.2x_%%-10.2x|     |%-.2x|%-0.2x|%-3.2x|%-5.2x|%-10.2x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.2x_%%-0.2x_%%-3.2x_%%-5.2x_%%-10.2x|    *|%-.2x|%-0.2x|%-3.2x|%-5.2x|%-10.2x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.2x_%%-0.2x_%%-3.2x_%%-5.2x_%%-10.2x|     |%-.2x|%-0.2x|%-3.2x|%-5.2x|%-10.2x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.2x_%%-0.2x_%%-3.2x_%%-5.2x_%%-10.2x|    *|%-.2x|%-0.2x|%-3.2x|%-5.2x|%-10.2x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.2x_%%03.2x_%%05.2x_%%07.2x_%%010.2x|    |%02.2x|%03.2x|%05.2x|%07.2x|%010.2x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.2x_%%03.2x_%%05.2x_%%07.2x_%%010.2x|   *|%02.2x|%03.2x|%05.2x|%07.2x|%010.2x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.2x_%%03.2x_%%05.2x_%%07.2x_%%010.2x|    |%02.2x|%03.2x|%05.2x|%07.2x|%010.2x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.2x_%%03.2x_%%05.2x_%%07.2x_%%010.2x|   *|%02.2x|%03.2x|%05.2x|%07.2x|%010.2x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.2x_%%03.2x_%%05.2x_%%07.2x_%%010.2x|    |%02.2x|%03.2x|%05.2x|%07.2x|%010.2x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.2x_%%03.2x_%%05.2x_%%07.2x_%%010.2x|   *|%02.2x|%03.2x|%05.2x|%07.2x|%010.2x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.5x_%%0.5x_%%3.5x_%%5.5x_%%10.5x|          |%.5x|%0.5x|%3.5x|%5.5x|%10.5x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.5x_%%0.5x_%%3.5x_%%5.5x_%%10.5x|         *|%.5x|%0.5x|%3.5x|%5.5x|%10.5x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.5x_%%0.5x_%%3.5x_%%5.5x_%%10.5x|          |%.5x|%0.5x|%3.5x|%5.5x|%10.5x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.5x_%%0.5x_%%3.5x_%%5.5x_%%10.5x|         *|%.5x|%0.5x|%3.5x|%5.5x|%10.5x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.5x_%%0.5x_%%3.5x_%%5.5x_%%6.5x|           |%.5x|%0.5x|%3.5x|%5.5x|%6.5x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.5x_%%0.5x_%%3.5x_%%5.5x_%%6.5x|          *|%.5x|%0.5x|%3.5x|%5.5x|%6.5x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.5x_%%-0.5x_%%-3.5x_%%-5.5x_%%-10.5x|     |%-.5x|%-0.5x|%-3.5x|%-5.5x|%-10.5x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.5x_%%-0.5x_%%-3.5x_%%-5.5x_%%-10.5x|    *|%-.5x|%-0.5x|%-3.5x|%-5.5x|%-10.5x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.5x_%%-0.5x_%%-3.5x_%%-5.5x_%%-10.5x|     |%-.5x|%-0.5x|%-3.5x|%-5.5x|%-10.5x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.5x_%%-0.5x_%%-3.5x_%%-5.5x_%%-10.5x|    *|%-.5x|%-0.5x|%-3.5x|%-5.5x|%-10.5x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.5x_%%-0.5x_%%-3.5x_%%-5.5x_%%-10.5x|     |%-.5x|%-0.5x|%-3.5x|%-5.5x|%-10.5x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.5x_%%-0.5x_%%-3.5x_%%-5.5x_%%-10.5x|    *|%-.5x|%-0.5x|%-3.5x|%-5.5x|%-10.5x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.5x_%%03.5x_%%05.5x_%%07.5x_%%010.5x|    |%02.5x|%03.5x|%05.5x|%07.5x|%010.5x|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.5x_%%03.5x_%%05.5x_%%07.5x_%%010.5x|   *|%02.5x|%03.5x|%05.5x|%07.5x|%010.5x|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.5x_%%03.5x_%%05.5x_%%07.5x_%%010.5x|    |%02.5x|%03.5x|%05.5x|%07.5x|%010.5x|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.5x_%%03.5x_%%05.5x_%%07.5x_%%010.5x|   *|%02.5x|%03.5x|%05.5x|%07.5x|%010.5x|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.5x_%%03.5x_%%05.5x_%%07.5x_%%010.5x|    |%02.5x|%03.5x|%05.5x|%07.5x|%010.5x|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.5x_%%03.5x_%%05.5x_%%07.5x_%%010.5x|   *|%02.5x|%03.5x|%05.5x|%07.5x|%010.5x|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%x|%x|%x\n", 2, 16, 30);
	c2 = ft_printf("%x|%x|%x\n", 2, 16, 30);
	error(c1, c2);

	// printf(MAGENTA"\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------"RESET"\n\n");

	// c1 = printf("%%0-8.3x|%%0-8.5x|%%10|                         |%0-8.3x|%0-8.5x|%10|\n", -8473);
	// c2 = ft_printf("%%0-8.3x|%%0-8.5x|%%10|                        *|%0-8.3x|%0-8.5x|%10|\n", -8473);
	// error(c1, c2);
	// printf("\n");

	// c1 = printf("%%2-2.5x_%%2-3.5x_%%2-5.5x_%%2-7.5x_%%2-10.5x|    |%2-2.5x|%2-3.5x|%2-5.5x|%2-7.5x|%2-10.5x|\n", 0, 0, 0, 0, 0);
	// c2 = ft_printf("%%2-2.5x_%%2-3.5x_%%2-5.5x_%%2-7.5x_%%2-10.5x|   *|%2-2.5x|%2-3.5x|%2-5.5x|%2-7.5x|%2-10.5x|\n", 0, 0, 0, 0, 0);
	// error(c1, c2);
	// c1 = printf("%%2-2.5x_%%2-3.5x_%%2-5.5x_%%2-7.5x_%%2-10.5x|    |%2-2.5x|%2-3.5x|%2-5.5x|%2-7.5x|%2-10.5x|\n", 234, 234, 234, 234, 234);
	// c2 = ft_printf("%%2-2.5x_%%2-3.5x_%%2-5.5x_%%2-7.5x_%%2-10.5x|   *|%2-2.5x|%2-3.5x|%2-5.5x|%2-7.5x|%2-10.5x|\n", 234, 234, 234, 234, 234);
	// error(c1, c2);
	// c1 = printf("%%2-2.5x_%%2-3.5x_%%2-5.5x_%%2-7.5x_%%2-10.5x|    |%2-2.5x|%2-3.5x|%2-5.5x|%2-7.5x|%2-10.5x|\n", -234, -234, -234, -234, -234);
	// c2 = ft_printf("%%2-2.5x_%%2-3.5x_%%2-5.5x_%%2-7.5x_%%2-10.5x|   *|%2-2.5x|%2-3.5x|%2-5.5x|%2-7.5x|%2-10.5x|\n", -234, -234, -234, -234, -234);
	// error(c1, c2);
	// printf("\n");

	// c1 = printf("%%2.6-8x_%%3.6-8x_%%5.6-8x_%%7.6-8x_%%10x|              |%2.6-8x|%3.6-8x|%5.6-8x|%7.6-8x|%10.6-8x|\n", 0, 0, 0, 0, 0);
	// c2 = ft_printf("%%2.6-8x_%%3.6-8x_%%5.6-8x_%%7.6-8x_%%10.6-8x|             *|%2.6-8x|%3.6-8x|%5.6-8x|%7.6-8x|%10.6-8x|\n", 0, 0, 0, 0, 0);
	// error(c1, c2);
	// c1 = printf("%%2.6-8x_%%3.6-8x_%%5.6-8x_%%7.6-8x_%%10.6-8x|              |%2.6-8x|%3.6-8x|%5.6-8x|%7.6-8x|%10.6-8x|\n", 234, 234, 234, 234, 234);
	// c2 = ft_printf("%%2.6-8x_%%3.6-8x_%%5.6-8x_%%7.6-8x_%%10.6-8x|             *|%2.6-8x|%3.6-8x|%5.6-8x|%7.6-8x|%10.6-8x|\n", 234, 234, 234, 234, 234);
	// error(c1, c2);
	// c1 = printf("%%2.6-8x_%%3.6-8x_%%5.6-8x_%%7.6-8x_%%10.6-8x|              |%2.6-8x|%3.6-8x|%5.6-8x|%7.6-8x|%10.6-8x|\n", -234, -234, -234, -234, -234);
	// c2 = ft_printf("%%2.6-8x_%%3.6-8x_%%5.6-8x_%%7.6-8x_%%10.6-8x|             *|%2.6-8x|%3.6-8x|%5.6-8x|%7.6-8x|%10.6-8x|\n", -234, -234, -234, -234, -234);
	// error(c1, c2);
	// printf("\n");
}
void	uint_github_test()
{
		int c1;
	int c2;

	printf(GREEN"\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_UNSIGNEu_NUMBERS"RESET"\n\n");

	printf("Test min max\n");

	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 4294967295, 4294967295, 4294967295, 4294967295);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 4294967295, 4294967295, 4294967295, 4294967295);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", -4294967295, -4294967295, -4294967295, -4294967295);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", -4294967295, -4294967295, -4294967295, -4294967295);
	error(c1, c2);
	printf("\n");

	printf("Test larger min max\n");
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 2147483648, 2147483648, 2147483648, 2147483648);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", -2147483649, -2147483649, -2147483649, -2147483649);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 2147483650, 2147483650, 2147483650, 2147483650);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 4294967296, 4294967296, 4294967296, 4294967296);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 4294967296, 4294967296, 4294967296, 4294967296);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 4294967297, 4294967297, 4294967297, 4294967297);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 4294967297, 4294967297, 4294967297, 4294967297);
	error(c1, c2);
	c1 = printf("|%%u|%%15u|%%-15u|%%015u|                    |%u|%15u|%-15u|%015u|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	c2 = ft_printf("|%%u|%%15u|%%-15u|%%015u|                   *|%u|%15u|%-15u|%015u|\n", 140737488355327, 140737488355327, 140737488355327, 140737488355327);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%u_%%0u_%%3u_%%5u_%%10u|                    |%u|%0u|%3u|%5u|%10u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%u_%%0u_%%3u_%%5u_%%10u|                   *|%u|%0u|%3u|%5u|%10u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%u_%%0u_%%3u_%%5u_%%10u|                    |%u|%0u|%3u|%5u|%10u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%u_%%0u_%%3u_%%5u_%%10u|                   *|%u|%0u|%3u|%5u|%10u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%u_%%0u_%%3u_%%5u_%%10u|                    |%u|%0u|%3u|%5u|%10u|\n", -234u, -234u, -234u, -234u, -234u);
	c2 = ft_printf("%%u_%%0u_%%3u_%%5u_%%10u|                   *|%u|%0u|%3u|%5u|%10u|\n", -234u, -234u, -234u, -234u, -234u);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|               |%-u|%-0u|%-3u|%-5u|%-10u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|              *|%-u|%-0u|%-3u|%-5u|%-10u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|               |%-u|%-0u|%-3u|%-5u|%-10u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|              *|%-u|%-0u|%-3u|%-5u|%-10u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|               |%-u|%-0u|%-3u|%-5u|%-10u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-u_%%-0u_%%-3u_%%-5u_%%-10u|              *|%-u|%-0u|%-3u|%-5u|%-10u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%2u_%%3u_%%5u_%%7u_%%10u|              |%2u|%3u|%5u|%7u|%10u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%2u_%%3u_%%5u_%%7u_%%10u|             *|%2u|%3u|%5u|%7u|%10u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%2u_%%3u_%%5u_%%7u_%%10u|              |%2u|%3u|%5u|%7u|%10u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%2u_%%3u_%%5u_%%7u_%%10u|             *|%2u|%3u|%5u|%7u|%10u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%2u_%%3u_%%5u_%%7u_%%10u|              |%2u|%3u|%5u|%7u|%10u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%2u_%%3u_%%5u_%%7u_%%10u|             *|%2u|%3u|%5u|%7u|%10u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02u_%%03u_%%05u_%%07u_%%010u|              |%02u|%03u|%05u|%07u|%010u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02u_%%03u_%%05u_%%07u_%%010u|             *|%02u|%03u|%05u|%07u|%010u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02u_%%03u_%%05u_%%07u_%%010u|              |%02u|%03u|%05u|%07u|%010u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02u_%%03u_%%05u_%%07u_%%010u|             *|%02u|%03u|%05u|%07u|%010u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02u_%%03u_%%05u_%%07u_%%010u|              |%02u|%03u|%05u|%07u|%010u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02u_%%03u_%%05u_%%07u_%%010u|             *|%02u|%03u|%05u|%07u|%010u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.0u_%%0.0u_%%3.0u_%%5.0u_%%10.0u|          |%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.0u_%%0.0u_%%3.0u_%%5.0u_%%10.0u|         *|%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.0u_%%0.0u_%%3.0u_%%5.0u_%%10.0u|          |%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.0u_%%0.0u_%%3.0u_%%5.0u_%%10.0u|         *|%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%u.0_%%0.0u_%%3.0u_%%5.0u_%%10.0u|          |%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%u.0_%%0.0u_%%3.0u_%%5.0u_%%10.0u|         *|%.0u|%0.0u|%3.0u|%5.0u|%10.0u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|     |%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|    *|%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|     |%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|    *|%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|     |%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.0u_%%-0.0u_%%-3.0u_%%-5.0u_%%-10.0u|    *|%-.0u|%-0.0u|%-3.0u|%-5.0u|%-10.0u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|    |%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|   *|%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|    |%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|   *|%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|    |%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.0u_%%03.0u_%%05.0u_%%07.0u_%%010.0u|   *|%02.0u|%03.0u|%05.0u|%07.0u|%010.0u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.3u|          |%.3u|%0.3u|%3.3u|%5.3u|%10.3u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.3u|         *|%.3u|%0.3u|%3.3u|%5.3u|%10.3u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.3u|          |%.3u|%0.3u|%3.3u|%5.3u|%10.3u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.3u|         *|%.3u|%0.3u|%3.3u|%5.3u|%10.3u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.4u|          |%.3u|%0.3u|%3.3u|%5.3u|%10.4u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.3u_%%0.3u_%%3.3u_%%5.3u_%%10.4u|         *|%.3u|%0.3u|%3.3u|%5.3u|%10.4u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|     |%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|    *|%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|     |%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|    *|%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|     |%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.2u_%%-0.2u_%%-3.2u_%%-5.2u_%%-10.2u|    *|%-.2u|%-0.2u|%-3.2u|%-5.2u|%-10.2u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|    |%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|   *|%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|    |%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|   *|%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|    |%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.2u_%%03.2u_%%05.2u_%%07.2u_%%010.2u|   *|%02.2u|%03.2u|%05.2u|%07.2u|%010.2u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%10.5u|          |%.5u|%0.5u|%3.5u|%5.5u|%10.5u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%10.5u|         *|%.5u|%0.5u|%3.5u|%5.5u|%10.5u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%10.5u|          |%.5u|%0.5u|%3.5u|%5.5u|%10.5u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%10.5u|         *|%.5u|%0.5u|%3.5u|%5.5u|%10.5u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%6.5u|           |%.5u|%0.5u|%3.5u|%5.5u|%6.5u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%.5u_%%0.5u_%%3.5u_%%5.5u_%%6.5u|          *|%.5u|%0.5u|%3.5u|%5.5u|%6.5u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|     |%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|    *|%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|     |%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|    *|%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|     |%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%-.5u_%%-0.5u_%%-3.5u_%%-5.5u_%%-10.5u|    *|%-.5u|%-0.5u|%-3.5u|%-5.5u|%-10.5u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");

	c1 = printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|    |%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", 0, 0, 0, 0, 0);
	c2 = ft_printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|   *|%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", 0, 0, 0, 0, 0);
	error(c1, c2);
	c1 = printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|    |%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", 234, 234, 234, 234, 234);
	c2 = ft_printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|   *|%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", 234, 234, 234, 234, 234);
	error(c1, c2);
	c1 = printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|    |%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", -234, -234, -234, -234, -234);
	c2 = ft_printf("%%02.5u_%%03.5u_%%05.5u_%%07.5u_%%010.5u|   *|%02.5u|%03.5u|%05.5u|%07.5u|%010.5u|\n", -234, -234, -234, -234, -234);
	error(c1, c2);
	printf("\n");



	// c1 = printf("   |%llu|%25llu|%-25llu|%025llu|\n", 18446744073709551614, 18446744073709551614, 18446744073709551614, -18446744073709551614);
	// c2 = ft_printf("  *|%llu|%25llu|%-25llu|%025llu|\n",  18446744073709551614, 18446744073709551614, 18446744073709551614, -18446744073709551614);


	// printf("\n\n-------------------------------\n|  Big number tests:  |\n-------------------------------\n\n");
	// c1 = printf("   |%llu|%25llu|%-25llu|%025llu|\n", 18446744073709551614, 18446744073709551614, 18446744073709551614, -18446744073709551614);
	// c2 = ft_printf("  *|%llu|%25llu|%-25llu|%025llu|\n",  18446744073709551614, 18446744073709551614, 18446744073709551614, -18446744073709551614);
	// error(c1, c2);

	// c1 = printf("   |%lu|%25lu|%-25lu|%025lu|\n", 9223372036854775807, 9223372036854775807, 9223372036854775807, 9223372036854775809);
	// c2 = ft_printf("  *|%lu|%25lu|%-25lu|%025lu|\n", 9223372036854775807, 9223372036854775807, 9223372036854775807, 9223372036854775809);
	// error(c1, c2);

	// c1 = printf("   |%hu|%25hu|%-25hu|%025hu|\n", 18446744073709551614, 18446744073709551614, 18446744073709551614, -18446744073709551614);
	// c2 = ft_printf("  *|%hu|%25hu|%-25hu|%025hu|\n",  18446744073709551614, 18446744073709551614, 18446744073709551614, -18446744073709551614);
	// error(c1, c2);

	// c1 = printf("   |%hhu|%25hhu|%-25hhu|%025hhu|\n", 18446744073709551614, 18446744073709551614, 18446744073709551614, -18446744073709551614);
	// c2 = ft_printf("  *|%hhu|%25hhu|%-25hhu|%025hhu|\n",  18446744073709551614, 18446744073709551614, 18446744073709551614, -18446744073709551614);
	// error(c1, c2);



	// printf(MAGENTA"\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------"RESET"\n\n");

	// c1 = printf("%%0-8.3u|%%0-8.5u|%%10|                         |%0-8.3u|%0-8.5u|%10|\n", -8473);
	// c2 = ft_printf("%%0-8.3u|%%0-8.5u|%%10|                        *|%0-8.3u|%0-8.5u|%10|\n", -8473);
	// error(c1, c2);
	// printf("\n");

	// c1 = printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|    |%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", 0, 0, 0, 0, 0);
	// c2 = ft_printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|   *|%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", 0, 0, 0, 0, 0);
	// error(c1, c2);
	// c1 = printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|    |%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", 234, 234, 234, 234, 234);
	// c2 = ft_printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|   *|%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", 234, 234, 234, 234, 234);
	// error(c1, c2);
	// c1 = printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|    |%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", -234, -234, -234, -234, -234);
	// c2 = ft_printf("%%2-2.5u_%%2-3.5u_%%2-5.5u_%%2-7.5u_%%2-10.5u|   *|%2-2.5u|%2-3.5u|%2-5.5u|%2-7.5u|%2-10.5u|\n", -234, -234, -234, -234, -234);
	// error(c1, c2);
	// printf("\n");

	// c1 = printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10u|              |%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", 0, 0, 0, 0, 0);
	// c2 = ft_printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|             *|%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", 0, 0, 0, 0, 0);
	// error(c1, c2);
	// c1 = printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|              |%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", 234, 234, 234, 234, 234);
	// c2 = ft_printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|             *|%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", 234, 234, 234, 234, 234);
	// error(c1, c2);
	// c1 = printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|              |%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", -234, -234, -234, -234, -234);
	// c2 = ft_printf("%%2.6-8u_%%3.6-8u_%%5.6-8u_%%7.6-8u_%%10.6-8u|             *|%2.6-8u|%3.6-8u|%5.6-8u|%7.6-8u|%10.6-8u|\n", -234, -234, -234, -234, -234);
	// error(c1, c2);
	// printf("\n");
}
void	tree(int n, char *shift)
{
	char *spaces;

	ft_printf(YELLOW"%s%*s%s\n", shift, n + 1, "*", RESET);
	ft_printf(YELLOW"%s%*s%s\n", shift, n + 2, "***", RESET);
	for(int i = 0; i < n; i++)
	{
		ft_printf("%s%*s", shift, n - i, "");
		for(int j = 0; j < i * 2 + 1; j++)
			ft_printf(BGREEN" "RESET);
		ft_printf("\n");
	}
	asprintf(&spaces, "%s%*s", shift, n - 1, "");
	ft_printf("%s%s%s%s\n", spaces, BYELLOW, "   ", RESET);
	ft_printf("%s%s%s%s\n", spaces, BYELLOW, "   ", RESET);

}
void	new_year()
{
	int n = 10;
	char *shift;
	for(int i = 0; i < 5000; i++)
	{

		asprintf(&shift,"%*s", n * i%6 * n * 3, "");
		tree(n, shift);
		sleep(1);
	}
}

int main()
{


	//test_basic();
	//int a = 0, b = 0;
	// char_test();
	// string_test();
	// pointer_test();
	// pointer_github_test();
	// char_github_test();
	// string_github_test();
	// int_github_test();
	// hex_github_test();
	// uint_github_test();
	//new_year();
	// ft_printf("null: %.s$\n", NULL);
	// printf("null: %.s$\n", NULL);
	// ft_printf("null: %.0s$\n", NULL);
	// printf("null: %.0s$\n", NULL);
	// ft_printf("null: %.*s$\n", 0, NULL);
	// printf("null: %.*s$\n", 0, NULL);
	// printf("%.30p\n", NULL);
	// ft_printf("%.30p\n", NULL);
	// printf("%-------------030p\n", NULL);
	// ft_printf("HELLO %030p\n %d", &n, 12);
	// a = printf("%.*d\n", INT_MIN, 99);
	// //b = ft_printf("%*d\n", INT_MIN, 99);
	// printf("\n%d %d\n", a, b);

	printf("Hello %-------------5.3d$\n", 1);
	printf("Hello %-------------*.3d$\n", 20, 1);
	printf("Hello\n");

	//check();
}
