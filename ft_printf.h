#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //delete
#include "libft/libft.h"

int ft_printf(const char *format, ...);
int	ft_parser(const char **format);

#endif
