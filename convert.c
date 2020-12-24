#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

// n    - decimal number
// base - number from 2 to 36(included)
// reg  - register, 1 uppercase, 0 lowercase (isupper('X'))
char *converter(unsigned long n, int base, int reg)
{
  char			*num;
  int			len;
  int			digit;
  unsigned long n_copy;

  if (n == 0)
    return ft_strdup("0");
  len = 1;
  n_copy = n;
  while(n_copy /= base)
  	len++;
  num = ft_calloc(len-- + 1, 1);
  reg = 97 - reg * 32; //switch register
  while(n)
  {
    digit = n % base;
    if(digit > 9)
      num[len--] = reg + digit - 10; // ascii code
    else
      num[len--] = digit + '0';
    n /= base;
  }
  return num;
}



