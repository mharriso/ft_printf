/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 21:56:26 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/29 18:18:13 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_converter(unsigned long n, int base, int reg, t_flags *flags)
{
	char			*num;
	int				len;
	int				digit;
	unsigned long	n_copy;

	if (flags->is_acc && flags->acc == 0 && n == 0)
		return (ft_strdup(""));
	if (n == 0)
		return (ft_strdup("0"));
	len = 1;
	n_copy = n;
	while (n_copy /= base)
		len++;
	num = ft_calloc(len-- + 1, 1);
	reg = 97 - reg * 32;
	while (n)
	{
		digit = n % base;
		if (digit > 9)
			num[len--] = reg + digit - 10;
		else
			num[len--] = digit + '0';
		n /= base;
	}
	return (num);
}
