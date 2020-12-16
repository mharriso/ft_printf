/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:53 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/17 00:18:19 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int	len;

	len = 0;
	//len = write(1, format, strlen(format));
	while(*format)
	{
		len += write(1, format, 1);
		if(*format == '%')
			ft_parser(format);
		format++;
	}
	return (len);
}
