/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:53 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/24 17:41:29 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void ft_putch(char *s, int l, int *len)
{
	(*len) += write(1, s, l);
}

void print_fill(char c, int len)
{
	while(len--)
		write(1, &c, 1);
}

int	print_char(char c,t_flags *flags)
{
	if (flags->width)
		flags->width = flags->width - 1;
	if (flags->minus)
	{
		//ft_putch(&c, &(flags->len));
		(write(1, &c, 1));
		print_fill(SPACE, flags->width);
	}
	else
	{
		print_fill(SPACE + flags->zero, flags->width);
		(write(1, &c, 1));
	}
	if(!(flags->str = malloc(1)))
		return (-1);
	flags->len += flags->width + 1;
	return (0);
}

int	print_string(va_list args, t_flags *flags)
{
	size_t	len;
	char *str;

	str= va_arg(args, char *);
	if (!str)
		flags->str = strdup("(null)");
	else
		flags->str = strdup(str);
	len = ft_strlen(flags->str);
	return (write(1, flags->str, len));
}

int	print_pointer(va_list args, t_flags *flags)
{
	size_t	len;

	flags->str= converter((unsigned long)va_arg(args, unsigned int*), 16, 0);
	len = ft_strlen(flags->str);
	write(1, "0x", 2);
	//add zeros
	return (2 + write(1, flags->str, len));
}

int	print_hex(va_list args, t_flags *flags, int reg)
{
	size_t			len;

	if(!(flags->str = converter(va_arg(args, unsigned int), 16, reg)))
		return (-1);
	len = ft_strlen(flags->str);
	flags->len += write(1, flags->str, len);
	return (0);
}

int	print_int(va_list args, t_flags *flags)
{
	size_t			len;
	long int		n;
	int				minus;

	n = va_arg(args, int);
	minus = n < 0;
	if (minus)
	{
		write(1, "-", 1);
		n = -n;
	}
	flags->str= converter(n, 10, 0);
	len = ft_strlen(flags->str);
	// add zeros
	return (minus + write(1, flags->str, len));
}

int	print_unsigned(va_list args, t_flags *flags)
{
	size_t			len;

	flags->str= converter(va_arg(args, unsigned int), 10, 0);
	len = ft_strlen(flags->str);
	return (write(1, flags->str, len));
}

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
int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*percent;
	t_flags		flags;
	char 	*form;

	form = (char*)format;
	flags.len = 0;
	va_start(args, format);
	while (*format)
	{
		if ((percent = ft_strchr(format, '%')))
		{
			flags.len += write(1, format, percent - format);
			format = percent + 1;
			if (*format)
			{
				ft_parser(&form, args, &flags);
				flags.len += print_format_arg(*(format++), args, &flags);
				free(flags.str);
			}
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
