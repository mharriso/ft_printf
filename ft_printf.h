/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:59:20 by mharriso          #+#    #+#             */
/*   Updated: 2020/12/24 17:37:45 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define ZERO	0
#define MIN		1
#define WID		2
#define ACC		3
#define IS_ACC	4

#define SPACE	32
#define ZEROS	48

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //delete
#include <limits.h> //delete
#include "libft/libft.h"
// cspdiuxX%
// -0.*
typedef struct s_flags
{
	char *str;
	int minus;
	int zero;
	int width;
	int acc;
	int is_acc;
	int len;


} t_flags;

int		ft_printf(const char *format, ...);
int	ft_parser(char **format, va_list args, t_flags *flags);
char	*converter(unsigned long n, int base, int reg);
int		print_format_arg(char s, va_list args, t_flags *flags);
int		ft_abs(int n);

#endif
