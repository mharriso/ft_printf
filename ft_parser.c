/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:20:02 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/23 04:12:23 by mharriso         ###   ########.fr       */
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
int	*ft_parser(const char **format, va_list args)
{
	int *flags;

	flags = ft_calloc(5, sizeof(int));
	while (**format == '-' || **format == '0')
	{
		if (**format == '0')
			flags[ZERO] = 16;
		if (**format == '-')
			flags[MIN] = 1;
		(*format)++;
	}
	if (ft_isdigit(**format))
		flags[WID] = ft_atoi(*format);
	if (**format == '*')
	{
		flags[WID] = va_arg(args, int);
		(*format)++;
	}
	if (flags[WID] < 0)
	{
		flags[WID] = ft_abs(flags[WID]);
		flags[MIN] = 1;
	}
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
	{
		flags[IS_ACC] = 1;
		(*format)++;
	}
	if (**format == '*')
	{
		flags[ACC] = va_arg(args, int);
		(*format)++;
	}
	else
		flags[ACC] = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	return (flags);
}
