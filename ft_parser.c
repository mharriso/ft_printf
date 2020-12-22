/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 00:20:02 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/23 00:00:05 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ZERO	0
#define MIN		1
#define WID		2
#define ACC		3
#define IS_ACC	4


// cspdiuxX%
// -0.*
//%-0-----21.42d

int	*ft_parser(const char **format, va_list args)
{
	int *flags;

	flags = ft_calloc(5, sizeof(int));
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
	if(**format == '*')
		flags[WID] = va_arg(args, int);
	while(ft_isdigit(**format))
		(*format)++;
	if(**format == '.')
	{
		flags[IS_ACC] = 1;
		(*format)++;
	}
	if (**format == '*')
		flags[ACC] = va_arg(args, int);
	else
		flags[ACC] = ft_atoi(*format);
	while(ft_isdigit(**format))
		(*format)++;
	return (flags);
}
