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
	printf("\n"YELLOW);
	for(int i = 0; i < size*4-2; i++)
		printf("-");
	printf("\n");
	for(int i = 0; i < size; i++)
		printf("%%%c  ", type);
	printf("\n");
	for(int i = 0; i < size*4-2; i++)
		printf("-");
	printf(RESET"\n\n");
}

char **create_format(char type)
{
	print_title(type);
	char **format;
	int j = 0;

	int	 width[5] = {-10, 0 , 10};
	int	 precision[5] = {-15, 0 , 15};

	format = calloc(100, sizeof(char *));
	for(int i = 0; i < 3; i++, j++)
		asprintf(&format[j], " W = %4d |          | RES: |%%%d%c%s\n", width[i], width[i], type, DOLLAR);
	for(int i = 0; i < 3; i++, j++)
		asprintf(&format[j], "          | P = %4d | RES: |%%.%d%c%s\n", precision[i], precision[i], type, DOLLAR);
	for(int i = 0; i < 3; i++, j++)
		asprintf(&format[j], " W = %4d | P = %4d | RES: |%%%d.%d%c%s\n", width[i], precision[i], width[i], precision[i], type, DOLLAR);
	return format;

}

int main()
{
	char **format;

	format = create_format('c');
	for(int i = 0; format[i]; i++)
		printf(format[i], 'A');

	format = create_format('s');
	for(int i = 0; format[i]; i++)
		printf(format[i], "string");

	format = create_format('d');
	for(int i = 0; format[i]; i++)
		printf(format[i], 123);

	format = create_format('X');
	for(int i = 0; format[i]; i++)
		printf(format[i], 12345678);
}
