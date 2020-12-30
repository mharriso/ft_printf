/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:53 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/30 22:56:11 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_format_arg(char s, va_list args, t_flags *flags)
{
	char c;

	if (s == 'c' || s == '%')
	{
		c = (s == '%') ? '%' : (char)va_arg(args, int);
		return (print_char(c, flags));
	}
	if (s == 's')
		return (print_string(args, flags));
	if (flags->is_acc)
		flags->zero = 0;
	if (s == 'p')
		return (print_pointer(args, flags));
	if (s == 'd' || s == 'i')
		return (print_int(args, flags));
	if (s == 'u')
		return (print_unsigned(args, flags));
	if (s == 'x' || s == 'X')
		return (print_hex(args, flags, s == 'X'));
	return (0);
}

int		parse_and_print(char **format, va_list args, t_flags *flags)
{
	int		res;

	ft_parser(format, args, flags);
	if ((res = print_format_arg(**format, args, flags)) == -1)
	{
		va_end(args);
		return (res);
	}
	if (res)
		free(flags->str);
	if (**format)
		(*format)++;
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_flags		flags;
	char		*percent;

	flags.len = 0;
	va_start(args, format);
	while (*format)
	{
		if ((percent = ft_strchr(format, '%')))
		{
			flags.len += write(1, format, percent - format);
			format = percent + 1;
			if (*format)
				if (parse_and_print((char **)&format, args, &flags) == -1)
					return (-1);
		}
		else
		{
			flags.len += write(1, format, ft_strlen(format));
			break ;
		}
	}
	va_end(args);
	return (flags.len);
}
