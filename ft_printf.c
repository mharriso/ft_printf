/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 00:03:53 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/20 15:54:44 by mharriso         ###   ########.fr       */
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
	while(*format)
	{
		if((percent = ft_strchr(format, '%')))
		{
			len += write(1, format, percent - format);
			format = percent + 1;
			if(*format)
				len += ft_parser(&format, args);
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
