#include "libftprintf.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char c = 'a';
	char *s = "Hello World!";
	int d = 42;
	void *p = &d;
	size_t tot = 0;

	tot = printf("___printf\t%%c:\t%c\n", c);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%c:\t%c\n", c);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%s:\t %s\n", s);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%s:\t %s\n", s);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%p:\t %p null: %p\n", p, NULL);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%p:\t %p null: %p\n", p, NULL);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%d:\t min %d max %d\n", INT_MIN, INT_MAX);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%d:\t min %d max %d\n", INT_MIN, INT_MAX);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%i:\t min %i max %i\n", INT_MIN, INT_MAX);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%i:\t min %i max %i\n", INT_MIN, INT_MAX);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%u:\t %u\n", UINT_MAX);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%u:\t %u\n", UINT_MAX);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%xX:\t %x %X\n", INT_MAX, INT_MAX);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%xX:\t %x %X\n", INT_MAX, INT_MAX);
	ft_printf("total: %d\n\n", tot);
}