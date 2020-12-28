/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:53 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/28 19:17:23 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putch(char *s, int l, int *len)
{
	(*len) += write(1, s, l);
}
//ft_putch(&c, &(flags->len));
void print_fill(char c, int amt, size_t str_len, int *len)
{
	if ((amt = amt - str_len) < 0)
		amt = 0;
	(*len) += amt;
	while(amt--)
		write(1, &c, 1);
}

void set_order(char *s, t_flags *flags, size_t len)
{
	int a;

	if ((a = flags->acc - len) < 0)
			a = 0;
	if (flags->minus)
	{
		flags->len += write(1, flags->prefix, flags->p_len);
		print_fill(ZERO, flags->acc, len, &(flags->len));
		flags->len += (write(1, s, len));
		print_fill(SPACE + flags->zero, flags->width, len + flags->p_len + a, &(flags->len));
	}
	else
	{
		print_fill(SPACE + flags->zero, flags->width, len + flags->p_len + a, &(flags->len));
		flags->len += write(1, flags->prefix, flags->p_len);
		print_fill(ZERO, flags->acc, len, &(flags->len));
		flags->len += (write(1, s, len));
	}
}

int	print_char(char c, t_flags *flags)
{
	flags->acc = 0;
	set_order(&c, flags, 1);
	if(!(flags->str = malloc(1)))
		return (-1);
	return (0);
}

int	print_string(va_list args, t_flags *flags)
{
	size_t	len;
	char *str;

	str = va_arg(args, char *);
	if (!str)
		flags->str = strdup("(null)");
	else
		flags->str = strdup(str);
	if(!flags->str)
		return (-1);
	len = ft_strlen(flags->str);
	if(flags->is_acc && flags->acc < len)
		len = flags->acc;
	flags->acc = 0;
	set_order(flags->str, flags, len);
	return (0);
}

int	print_pointer(va_list args, t_flags *flags)
{
	unsigned long p;

	p = (unsigned long)va_arg(args, unsigned int*);
	if(flags->is_acc && flags->acc == 0 && p == 0)
		flags->str = strdup("");
	else
		flags->str = converter(p, 16, 0);
	if(!flags->str)
		return (-1);
	if(flags->is_acc)
		flags->zero = 0;
	flags->prefix = "0x";
	flags->p_len = 2;
	set_order(flags->str, flags, ft_strlen(flags->str));
	return (0);
}

int	print_hex(va_list args, t_flags *flags, int reg)
{
	unsigned	long	hex;

	hex = va_arg(args, unsigned int);
	if(flags->is_acc && flags->acc == 0 && hex == 0)
		flags->str = strdup("");
	else
		flags->str = converter(hex, 16, reg);
	if(!flags->str)
		return (-1);
	if(flags->is_acc)
		flags->zero = 0;
	set_order(flags->str, flags, ft_strlen(flags->str));
	return (0);
}

int	print_int(va_list args, t_flags *flags)
{
	long int		n;

	n = va_arg(args, int);
	if (n < 0)
	{
		flags->prefix = "-";
		flags->p_len = 1;
		n = -n;
	}
	if(flags->is_acc && flags->acc == 0 && n == 0)
		flags->str = strdup("");
	else
		flags->str = converter(n, 10, 0);
	if(!flags->str)
		return (-1);
	if(flags->is_acc)
		flags->zero = 0;
	set_order(flags->str, flags, ft_strlen(flags->str));
	return (0);
}

int	print_unsigned(va_list args, t_flags *flags)
{

	unsigned	long	u;

	u = va_arg(args, unsigned int);
	if(flags->is_acc && flags->acc == 0 && u == 0)
		flags->str = strdup("");
	else
		flags->str = converter(u, 10, 0);
	if(!flags->str)
		return (-1);
	if(flags->is_acc)
		flags->zero = 0;
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
				ft_parser(&format, args, &flags);
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
