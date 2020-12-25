#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //delete
#include <limits.h> //delete

int	main()
{
	int x, y;
	int *a, *b, *c;


	x = 111;
	y = 222;

	//c = &x;
	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));

	*a = x;
	*b = y;

	//free(c);
	c = a;

	*a = *b;

	printf("poiter a %p\npoiter c %p\n", a, c);
	printf("a* = %d\nc* = %d\n", *a, *c);

	free(a);
	free(b);

}
