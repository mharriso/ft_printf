/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 22:15:30 by mharriso          #+#    #+#             */
/*   Updated: 2021/01/10 20:21:19 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char c, t_flags *flags)
{
	flags->acc = 0;
	set_order(&c, flags, 1);
	return (0);
}

int		print_string(va_list args, t_flags *flags)
{
	int		len;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		flags->str = ft_strdup("(null)");
	else
		flags->str = ft_strdup(str);
	if (!flags->str)
		return (-1);
	len = ft_strlen(flags->str);
	if (flags->is_acc && flags->acc < len)
		len = flags->acc;
	flags->acc = 0;
	set_order(flags->str, flags, len);
	return (0);
}
