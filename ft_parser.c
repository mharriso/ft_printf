/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:20:02 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/29 18:44:28 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// cspdiuxX%
// -0.*
//%-0-----21.42d

static	void	save_flags(char **format, t_flags *flags)
{
	while (ft_strchr("-0#+ ", **format))
	{
		if (**format == '0')
			flags->zero = 16;
		else if (**format == '-')
			flags->minus = 1;
		(*format)++;
	}
}

static	void	save_width(char **format, t_flags *flags, va_list args)
{
	if (ft_isdigit(**format))
		flags->width = ft_atoi(*format);
	if (**format == '*')
	{
		flags->width = va_arg(args, int);
		(*format)++;
	}
	if (flags->width < 0)
	{
		flags->width = -flags->width;
		flags->minus = 1;
	}
}

static	void	save_accuracy(char **format, t_flags *flags, va_list args)
{
	if (**format == '.')
	{
		flags->is_acc = 1;
		(*format)++;
	}
	if (**format == '*')
	{
		flags->acc = va_arg(args, int);
		(*format)++;
	}
	else
		flags->acc = ft_atoi(*format);
	if (**format == '-')
		(*format)++;
	if (flags->acc < 0)
		flags->is_acc = 0;
}

int				ft_parser(char **format, va_list args, t_flags *flags)
{
	ft_memset(flags, 0, sizeof(t_flags) - 8);
	flags->prefix = "";
	save_flags(format, flags);
	save_width(format, flags, args);
	while (ft_isdigit(**format))
		(*format)++;
	save_accuracy(format, flags, args);
	while (ft_isdigit(**format))
		(*format)++;
	return (0);
}
