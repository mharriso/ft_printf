#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int length(unsigned long n, int base)
{
  int i = 1;
  while(n /= base)
    i++;
  return i;
}
// n    - decimal number
// base - number from 2 to 36(included)
// reg  - register, 1 uppercase, 0 lowercase (isupper('X'))
char *converter(unsigned long n, int base, int reg)
{
  char *num;
  int len, digit;

  if (n == 0)
    return "0";
  len = length(n, base);
  num = calloc(len-- + 1, 1); // ft_calloc
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

//int main()
//{
//	for(unsigned n = 0; n < 99; n++)
//		printf("print %X - %s\n", n, converter(n, 16, 0));
//}
