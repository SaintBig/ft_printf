/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:50:21 by jleal             #+#    #+#             */
/*   Updated: 2025/04/26 19:49:40 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	write(1, str, ft_strlen_new(str));
	return (ft_strlen_new(str));
}

static int	ft_findf(va_list args, const char format)
{
	if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == 'c')
		return (ft_printchar((va_arg(args, int))));
	else if (format == 'd')
		return (ft_putnbr_base((va_arg(args, int)), "0123456789"));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (format == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (format == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			tot;

	if (!format || (*format == '%' && *(format + 1) == '\0'))
		return (-1);
	va_start(args, format);
	i = 0;
	tot = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			tot += ft_findf(args, format[i + 1]);
			i++;
		}
		else
			tot += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (tot);
}

/* int	main(void)
{
	char c = 'A';
	char *s = "Hello World!";
	char *n = NULL;
	int d = 42;
	void *p = &d;
	int tot = 0;
	int tot2 = 0;

	tot = printf("___printf\t%%c:\t%c\n", c);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%c:\t%c\n", c);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%s:\t %s null: %s\n", s, n);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%s:\t %s null: %s\n", s, n);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%p:\t %p null: %p\n", p, NULL);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%p:\t %p null: %p\n", p, NULL);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%d:\t min( %d ) max( %d )\n", INT_MIN, INT_MAX);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%d:\t min( %d ) max( %d )\n", INT_MIN, INT_MAX);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%i:\t min( %i ) max( %i )\n", INT_MIN, INT_MAX);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%i:\t min( %i ) max( %i )\n", INT_MIN, INT_MAX);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%u:\t %u\n", UINT_MAX);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%u:\t %u\n", UINT_MAX);
	ft_printf("total: %d\n\n", tot);

	tot = printf("___printf\t%%xX:\t %x %X\n", -1, -1);
	ft_printf("total: %d\n", tot);
	tot = ft_printf("ft_printf\t%%xX:\t %x %X\n", -1, -1);
	ft_printf("total: %d\n\n", tot);

	printf("==EDGECASES==\n");
	ft_printf("csdixXpu%");
	ft_printf("%");
	ft_printf("");
	ft_printf("\n");
	ft_printf("closing terminal...\n\n");
	int saved_stdout = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	tot = ft_printf("%s\n", "closed the terminal!!");
	tot2 = ft_printf("%s\n", "closed the terminal!!");
	dup2(saved_stdout, STDOUT_FILENO);
	printf("ft_printf returned %d\n", tot);
	printf("   printf returned %d\n", tot);
} */