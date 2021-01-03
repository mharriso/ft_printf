/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:59:42 by mharriso          #+#    #+#             */
/*   Updated: 2021/01/03 19:06:32 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	save_len(va_list args, int len)
{
	int *n;

	n = va_arg(args, int *);
	*n = len;
	return (0);
}
