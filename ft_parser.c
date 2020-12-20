/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:20:02 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/20 18:37:55 by mharriso         ###   ########.fr       */
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
int print_pointer(va_list args, int *flags)
{
	char *string;
	string = converter((unsigned long)va_arg(args, unsigned int*), 16, 0);
	write(1, "0x", 2);

	return (2 + write(1, string, ft_strlen(string)));
}
int print_args(char s, va_list args, int *flags)
{
	char c;
	char *string;
	if (s == '%')
	{
		return write(1, "%", 1);
	}
	if (s == 'c')
	{
		c = va_arg(args, int);
		return write(1, &c, 1);
	}
	if (s == 's')
	{
		string = va_arg(args, char *);
		return write(1, string, ft_strlen(string));
	}
	if (s == 'p')
	{
		return print_pointer(args, flags);
	}

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
		if(flags[MIN])
		{
			(*format)++;
			return print_args(*(*format - 1), args, flags);
		}
	}

	return (0);
}
