/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:53 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/19 05:30:58 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int	len;
	char *percent;

	len = 0;
	//len = write(1, format, strlen(format));
	while(*format)
	{
		if((percent = ft_strchr(format, '%')))
		{
			len += write(1, format, percent - format);
			format = percent;
			len += ft_parser(&format);
		}
		else
			len += write(1, format, ft_strlen(format));
		format++;
	}
	va_end(args);
	return (len);
}
