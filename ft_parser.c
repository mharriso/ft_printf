/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:20:02 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/22 05:19:42 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ZERO 0
#define MIN  1
#define WID  2
#define ACC  3


// cspdiuxX%
// -0.*
//%-0-----21.42d
int print_char(char c, int *flags)
{
	return (write(1, &c, 1));
}

int print_string(va_list args, int *flags)
{
	char 	*str;
	size_t 	len;
	str = va_arg(args, char *);
	len = ft_strlen(str);
	return (write(1, str, len));
}

int print_pointer(va_list args, int *flags)
{
	char 	*str;
	size_t 	len;
	str = converter((unsigned long)va_arg(args, unsigned int*), 16, 0);
	len = ft_strlen(str);
	write(1, "0x", 2);
    //add zeros
	return (2 + write(1, str, len));
}

int print_hex(va_list args, int *flags, int reg)
{
	char 			*str;
	size_t 			len;

	str = converter(va_arg(args, unsigned int), 16, reg);
	len = ft_strlen(str);
	return (write(1, str, len));

}
int	print_int(va_list args, int *flags)
{
	char 			*str;
	size_t 			len;
	int 			n;
	int 			minus;

	n = va_arg(args, int);
	minus = n < 0;
	if (minus)
	{
		write(1, "-", 1);
		n = -n;
	}
	str = converter(n, 10, 0);
	len = ft_strlen(str);
	// add zeros
	return (minus + write(1, str, len));
}
int print_unsigned(va_list args, int *flags)
{
	char 			*str;
	size_t 			len;

	str = converter(va_arg(args, unsigned int), 10, 0);
	len = ft_strlen(str);
	return (write(1, str, len));
}
int print_format_arg(char s, va_list args, int *flags)
{
	char c;

	if (s == 'c' || s == '%')
	{
		c = (s == '%') ? '%' : va_arg(args, int);
		return (print_char(c, flags));
	}
	if (s == 's')
		return (print_string(args, flags));
	if (s == 'p')
		return (print_pointer(args, flags));
	if (s == 'd' || s == 'i')
		return print_int(args, flags);
	if (s == 'u')
		return (print_unsigned(args, flags));
	if (s == 'x' || s == 'X')
		return (print_hex(args, flags, s == 'X'));
	return (0);
}
int	ft_parser(const char **format, va_list args)
{
	int flags[5];
	ft_memset(flags, 0, 20);
	flags[ACC] = -1;
	while(**format)
	{
		while(**format == '-' || **format == '0')
		{
			if(**format == '0')
				flags[ZERO] = 1;
			if(**format == '-')
				flags[MIN] = 1;
			(*format)++;
		}
		if(ft_isdigit(**format))
			flags[WID] = ft_atoi(*format);
		while(ft_isdigit(**format))
			(*format)++;
		if(**format == '.')
			flags[ACC] = ft_atoi(++(*format));
		while(ft_isdigit(**format))
			(*format)++;
		(*format)++;
		return print_format_arg(*(*format - 1), args, flags);
	}
	return (0);
}
