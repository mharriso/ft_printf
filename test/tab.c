#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define RESET   "\033[0m"  //все атрибуты по умолчанию
#define BLACK   "\033[30m"  //30-37 цвет текста
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33;1m"
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

#define REVERSE  "\033[7;1m" /*жирный шрифт и реверсия,
знаки приобретают цвет фона, а фон цвет знаков*/
#define DOLLAR GREEN"$"RESET

// cspdiuxX%
// -0.*

void print_title(char type)
{
	int size = 15;
	int line = size*5-3;
	printf("\n"YELLOW);
	for(int i = 0; i < line; i++)
		printf("-");
	printf("\n");
	for(int i = 0; i < size; i++)
		printf("%%%c   ", type);
	printf("\n");
	for(int i = 0; i < line; i++)
		printf("-");
	printf("\n    M    |    Z    |    W    |    P    |            R E S U L T  \n"RESET);
}

void	clean(char **arr)
{
	for(int i = 0; arr[i]; i++)
		free(arr[i]);
	//free(arr);
}
char **create_format(char type)
{
	print_title(type);
	char **format;
	int j = 0;

	int	 w[5] = {-30, 0 , 25};
	int	 p[5] = {-35, 0 , 25};

	format = calloc(100, sizeof(char *));
	for(int i = 0; i < 3; i++, j++)
		asprintf(&format[j], "%9s|%9s| %7d |%9s| %%%d%c%s\n","","", w[i],"",  w[i], type, DOLLAR);
	for(int i = 0; i < 3; i++, j++)
		asprintf(&format[j], "%9s|%9s|%9s| %7d | %%.%d%c%s\n","","","", p[i], p[i], type, DOLLAR);
	for(int i = 0; i < 3; i++, j++)
		asprintf(&format[j], "%9s|%9s| %7d | %7d | %%%d.%d%c%s\n","","", w[i], p[i], w[i], p[i], type, DOLLAR);
	return format;
}

#define STR 's'
#define CHR 'c'
#define INT 'd'
#define PTR 'p'
#define UNS 'u'
#define hex 'x'
#define HEX 'X'

void	print_tab(char type, void *data)
{
	char **format;

	switch (type)
	{
	case 's':
	case 'p':
		format = create_format(type);
		for(int i = 0; format[i]; i++)
			printf(format[i], data);
		clean(format);
		break;

	default:
		format = create_format(type);
		for(int i = 0; format[i]; i++)
			printf(format[i], *(int*)data);
		clean(format);
		break;
	}
}

int main()
{
	char		**format;
	int			i = 11;
	char		c = 'u';
	unsigned	u = INT_MAX + (unsigned)66;

	print_tab(STR, "string");
	// print_tab(PTR, &i);
	// print_tab(HEX, &i);
	//aaa(INT, &i);
	//aaa(CHR, &c);
	//aaa('X', &i);

	// format = create_format('p');
	// for(int i = 0; format[i]; i++)
	// 	printf(format[i], &i);

}
