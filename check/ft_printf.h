/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharriso <mharriso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:59:20 by mharriso          #+#    #+#             */
/*   Updated: 2021/01/03 19:33:04 by mharriso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define SPACE	32
# define ZERO	48

typedef	struct	s_flags
{
	char	*str;
	char	*prefix;
	int		p_len;
	int		minus;
	int		zero;
	int		width;
	int		acc;
	int		is_acc;
	int		tag;
	int		plus;
	int		space;
	int		len;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_parser(char **format, va_list args, t_flags *flags);
char			*ft_converter(unsigned long n, int base, int reg,
				t_flags *flags);
int				print_format_arg(char s, va_list args, t_flags *flags);
int				print_char(char c, t_flags *flags);
int				print_string(va_list args, t_flags *flags);
int				print_pointer(va_list args, t_flags *flags);
int				print_hex(va_list args, t_flags *flags, int reg);
int				print_int(va_list args, t_flags *flags);
int				print_unsigned(va_list args, t_flags *flags);
int				save_len(va_list args, int len);
void			set_order(char *s, t_flags *flags, size_t len);

#endif
