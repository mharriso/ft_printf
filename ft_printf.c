/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:53 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/29 16:52:55 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_fill(char c, int amt, int *len)
{
	(*len) += amt;
	while (amt--)
		write(1, &c, 1);
}

void	set_format(t_flags *flags, int len)
{
	if ((flags->acc = flags->acc - len) < 0)
		flags->acc = 0;
	len += flags->acc + flags->p_len;
	if ((flags->width = flags->width - len) < 0)
		flags->width = 0;
}

void	set_order(char *s, t_flags *flags, size_t len)
{
	set_format(flags, len);
	if (flags->minus)
	{
		flags->len += write(1, flags->prefix, flags->p_len);
		print_fill(ZERO, flags->acc, &(flags->len));
		flags->len += (write(1, s, len));
		print_fill(SPACE + flags->zero, flags->width, &(flags->len));
	}
	else
	{
		print_fill(SPACE + flags->zero, flags->width, &(flags->len));
		flags->len += write(1, flags->prefix, flags->p_len);
		print_fill(ZERO, flags->acc, &(flags->len));
		flags->len += (write(1, s, len));
	}
}

int		print_char(char c, t_flags *flags)
{
	flags->acc = 0;
	set_order(&c, flags, 1);
	if (!(flags->str = malloc(1)))
		return (-1);
	return (0);
}

int		print_string(va_list args, t_flags *flags)
{
	size_t	len;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		flags->str = strdup("(null)");
	else
		flags->str = strdup(str);
	if (!flags->str)
		return (-1);
	len = ft_strlen(flags->str);
	if (flags->is_acc && flags->acc < len)
		len = flags->acc;
	flags->acc = 0;
	set_order(flags->str, flags, len);
	return (0);
}

int		print_pointer(va_list args, t_flags *flags)
{
	flags->str = converter((unsigned long)va_arg(args, unsigned int*), 16, 0, flags);
	if (!flags->str)
		return (-1);
	flags->prefix = "0x";
	flags->p_len = 2;
	set_order(flags->str, flags, ft_strlen(flags->str));
	return (0);
}

int		print_hex(va_list args, t_flags *flags, int reg)
{

	flags->str = converter(va_arg(args, unsigned int), 16, reg, flags);
	if (!flags->str)
		return (-1);
	set_order(flags->str, flags, ft_strlen(flags->str));
	return (0);
}

int		print_int(va_list args, t_flags *flags)
{
	long int		n;

	n = va_arg(args, int);
	if (n < 0)
	{
		flags->prefix = "-";
		flags->p_len = 1;
		n = -n;
	}
	flags->str = converter(n, 10, 0, flags);
	if (!flags->str)
		return (-1);
	set_order(flags->str, flags, ft_strlen(flags->str));
	return (0);
}

int		print_unsigned(va_list args, t_flags *flags)
{
	flags->str = converter(va_arg(args, unsigned int), 10, 0, flags);
	if (!flags->str)
		return (-1);
	set_order(flags->str, flags, ft_strlen(flags->str));
	return (0);
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

int	parse_and_print(char **format, va_list args, t_flags *flags)
{
	if (!**format)
		return (0);
	if (ft_parser(format, args, flags) == -1)
		return (-1);
	*(format++);
	if (print_format_arg(**format, args, flags) == -1)
		return (-1);
	free(flags->str);
}

int	ft_printf(const char *format, ...)
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
			{
				ft_parser(&format, args, &flags);
				print_format_arg(*(format++), args, &flags);
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
