/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:20:02 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/24 17:37:36 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// cspdiuxX%
// -0.*
//%-0-----21.42d

int ft_abs(int n)
{
	return (n < 0 ? -n : n);
}
int	ft_parser(char **format, va_list args, t_flags *flags)
{
	ft_memset(flags, 0, sizeof(t_flags) - 4);
	while (**format == '-' || **format == '0')
	{
		if (**format == '0')
			flags->zero = 16;
		if (**format == '-')
			flags->minus = 1;
		(*format)++;
	}
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
	while (ft_isdigit(**format))
		(*format)++;
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
	while (ft_isdigit(**format))
		(*format)++;
	return (0);
}
