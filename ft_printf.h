/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:59:20 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/22 23:49:34 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //delete
#include <limits.h> //delete
#include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		*ft_parser(const char **format, va_list args);
char	*converter(unsigned long n, int base, int reg);
int		print_format_arg(char s, va_list args, int *flags);

#endif
