/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:53 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/23 04:40:30 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void print_fill(char c, int len)
{
	while(len--)
		write(1, &c, 1);
}
int	print_char(char c, int *flags)
{
	if (flags[WID])
		flags[WID] = flags[WID] - 1;
	if (flags[MIN])
	{
		(write(1, &c, 1));
		print_fill(SPACE, flags[WID]);
	}
	else
	{
		print_fill(SPACE + flags[ZERO], flags[WID]);
		(write(1, &c, 1));
	}
	return (flags[WID] + 1);
}

int	print_string(va_list args, int *flags)
{
	char	*str;
	size_t	len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	print_pointer(va_list args, int *flags)
{
	char	*str;
	size_t	len;

	str = converter((unsigned long)va_arg(args, unsigned int*), 16, 0);
	len = ft_strlen(str);
	write(1, "0x", 2);
	//add zeros
	return (2 + write(1, str, len));
}

int	print_hex(va_list args, int *flags, int reg)
{
	char			*str;
	size_t			len;

	str = converter(va_arg(args, unsigned int), 16, reg);
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	print_int(va_list args, int *flags)
{
	char			*str;
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
	str = converter(n, 10, 0);
	len = ft_strlen(str);
	// add zeros
	return (minus + write(1, str, len));
}

int	print_unsigned(va_list args, int *flags)
{
	char			*str;
	size_t			len;

	str = converter(va_arg(args, unsigned int), 10, 0);
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	print_format_arg(char s, va_list args, int *flags)
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
	int		len;
	char	*percent;
	int		*flags;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if ((percent = ft_strchr(format, '%')))
		{
			len += write(1, format, percent - format);
			format = percent + 1;
			if (*format)
			{
				flags = ft_parser(&format, args);
				len += print_format_arg(*(format++), args, flags);
			}
		}
		else
		{
			len += write(1, format, ft_strlen(format));
			break ;
		}
	}
	va_end(args);
	return (len);
}
