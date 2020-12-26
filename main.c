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
void github_test_string(
{
	char str[100];
	char str1[100];
	int c1;
	int c2;

	strcpy(str, "hello");
	strcpy(str1, "a");

	printf("\n\n\n__________________________________________________________________________________\n");
	printf("\nTEST_STRINGS\n\n");


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





	printf("\n\n-------------------------------\n|  Undefined behavior tests:  |\n-------------------------------\n\n");

	printf("Test with 0:\n");
	c1 = printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	c2 = ft_printf("%s|%-s|%10s|%.5s|%.10s|%-10s|%-.5s|%-.10s|%10.5s|%7.10s|%-10.5s|%-7.10s|\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%5-s|%%5-1s|%%5-2s|%%5-5s|%%5-10s|          *|%5-s|%5-1s|%5-2s|%5-5s|%5-10s|\n", str, str, str, str, str);
	c1 = printf("|%%5-s|%%5-1s|%%5-2s|%%5-5s|%%5-10s|           |%5-s|%5-1s|%5-2s|%5-5s|%5-10s|\n", str, str, str, str, str);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-5-s|%%-5-1s|%%-5-2s|%%-5-5s|%%-5-10s|     *|%-5-s|%-5-1s|%-5-2s|%-5-5s|%-5-10s|\n", str, str, str, str, str);
	c1 = printf("|%%-5-s|%%-5-1s|%%-5-2s|%%-5-5s|%%-5-10s|      |%-5-s|%-5-1s|%-5-2s|%-5-5s|%-5-10s|\n", str, str, str, str, str);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%-0-s|%%-0-1s|%%-0-2s|%%-0-5s|%%-0-10s|     *|%-0-s|%-0-1s|%-0-2s|%-0-5s|%-0-10s|\n", str, str, str, str, str);
	c1 = printf("|%%-0-s|%%-0-1s|%%-0-2s|%%-0-5s|%%-0-10s|      |%-0-s|%-0-1s|%-0-2s|%-0-5s|%-0-10s|\n", str, str, str, str, str);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%.-s|%%.-1s|%%.-2s|%%.-5s|%%.-10s|          *|%.-s|%.-1s|%.-2s|%.-5s|%.-10s|\n", str, str, str, str, str);
	c1 = printf("|%%.-s|%%.-1s|%%.-2s|%%.-5s|%%.-10s|           |%.-s|%.-1s|%.-2s|%.-5s|%.-10s|\n", str, str, str, str, str);
	error(c1, c2);

	printf("\n");
	c2 = ft_printf("|%%0s|%%09s|%%00s|%%0.s|%%0.0s|%%0.7s|         *|%0s|%09s|%00s|%0.s|%0.0s|%0.7s|\n", str, str, str, str, str, str);
	c1 = printf("|%%0s|%%09s|%%00s|%%0.s|%%0.0s|%%0.7s|          |%0s|%09s|%00s|%0.s|%0.0s|%0.7s|\n", str, str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|   *|%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str, str, str, str, str, str);
	c1 = printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|    |%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str, str, str, str, str, str);
	error(c1, c2);
	c2 = ft_printf("|%%0s|%%05s|%%00s|%%0.s|%%0.0s|%%0.7s|         *|%0s|%05s|%00s|%0.s|%0.0s|%0.7s|\n", str1, str1, str1, str1, str1, str1);
	c1 = printf("|%%0s|%%05s|%%00s|%%0.s|%%0.0s|%%0.7s|          |%0s|%05s|%00s|%0.s|%0.0s|%0.7s|\n", str1, str1, str1, str1, str1, str1);
	error(c1, c2);
	c2 = ft_printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|   *|%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str1, str1, str1, str1, str1, str1);
	c1 = printf("|%%-0s|%%-05s|%%-00s|%%-0.s|%%-0.0s|%%-0.7s|    |%-0s|%-05s|%-00s|%-0.s|%-0.0s|%-0.7s|\n", str1, str1, str1, str1, str1, str1);
	error(c1, c2);
}

int main()
{
	//ft_printf("%*c$\n", INT_MIN, 'A');
	// test_basic();
	// test_char();
	test_string();
	// github_test_char();
	//check();
}
