/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:50:21 by jleal             #+#    #+#             */
/*   Updated: 2025/04/17 12:58:36 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "libftprintf.h"

#define HEX "0123456789abcdef"
#define HEXU "0123456789ABCDEF"
#define DEC "0123456789"

static int	ft_putchar(char c)
{
	int tot;

	tot = write(1, &c, 1);
	return (tot);
}

static int	ft_putstr(char *str)
{
	int tot;
	
	tot = 0;
	while (*str)
		tot += write(1, str++, 1);
	return (tot);
}

static int	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* static int	ft_putnbr(long int n) {
	size_t	tot;

	tot = 0;
	if (n == -2147483648) {
		tot += ft_putstr("-2147483648");
		return (tot);
	}
	if (n < 0) {
		tot += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		tot += ft_putnbr(n / 10);
	tot += ft_putchar(n % 10 + '0');
	return (tot);
} */

static int	print_nbr_base(long int nb, char *base)
{
	int		base_val;
	char	output;
	size_t	tot;

	tot = 0;
	base_val = ft_strlen(base);
	if (nb >= base_val)
		tot += print_nbr_base(nb / base_val, base);
	output = base[nb % base_val];
	tot += write(1, &output, 1);
	return (tot);
}

static int	ft_putnbr_base(long int nbr, char *base)
{
	size_t	tot;

	tot = 0;
	if (nbr == -9223372036854775807L -1L)
	{
		tot += write(1, "-9", 2);
		tot += print_nbr_base(223372036854775807, base);
		return (tot);
	}
	if (nbr < 0)
	{
		tot += write(1, "-", 1);
		nbr = -nbr;
	}
	tot += print_nbr_base(nbr, base);
	return (tot);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	va_start(args, format);
	size_t		total;
	long int	num;
	char		*str;
	char		c;
	void		*ptr;

	total = 0;
	while (*format) {
		if (*format == '%') {
			format++;
			if (*format == 'd') {
				num = va_arg(args, int);
				total += ft_putnbr_base(num, DEC);
			}
			else if (*format == 'u')
			{
				num = va_arg(args, unsigned int);
				total += ft_putnbr_base(num, DEC);
			}
			else if (*format == 'i') {
				num = va_arg(args, int);
				total += ft_putnbr_base(num, DEC);
			}
			else if (*format == 'x') {
				num = va_arg(args, int);
				total += ft_putnbr_base(num, HEX);
			}
			else if (*format == 'X') {
				num = va_arg(args, int);
				total += ft_putnbr_base(num, HEXU);
			}
			else if (*format == 's') {
				str = va_arg(args, char *);
				if (str)
					total += ft_putstr(str ? str : "(null)");
				else
					total += write(1, "(null)", 8);
			}
			else if (*format == 'c') {
				c = va_arg(args, int);
				total += ft_putchar(c);
			}
			else if (*format == 'p') {
				ptr = va_arg(args, void*);
				if (!ptr)
					total += write(1, "0x0", 3);
				else
				{
					total += write(1, "0x", 2);
					total += ft_putnbr_base((long int)ptr, HEX);
				}
			}
			else if (*format == '%') {
				total += ft_putchar('%');
			}
			format++;
		} else {
			ft_putchar(*format++);
			total++;
		}
	}
	va_end(args);
	return (total);
}
