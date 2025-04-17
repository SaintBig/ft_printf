/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:50:21 by jleal             #+#    #+#             */
/*   Updated: 2025/04/17 17:57:30 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

#define HEX "0123456789abcdef"
#define HEXU "0123456789ABCDEF"
#define DEC "0123456789"

static int	ft_putstr(char *str)
{
	int	tot;

	tot = 0;
	while (*str)
		tot += write(1, str++, 1);
	return (tot);
}

static int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	size_t		total;
	long int	num;
	char		*str;
	void		*ptr;

	va_start(args, format);
	total = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				num = va_arg(args, int);
				total += ft_putnbr_base(num, DEC);
			}
			else if (*format == 'u')
			{
				num = va_arg(args, unsigned int);
				total += ft_putnbr_base(num, DEC);
			}
			else if (*format == 'i')
			{
				num = va_arg(args, int);
				total += ft_putnbr_base(num, DEC);
			}
			else if (*format == 'x')
			{
				num = va_arg(args, int);
				total += ft_putnbr_base(num, HEX);
			}
			else if (*format == 'X')
			{
				num = va_arg(args, int);
				total += ft_putnbr_base(num, HEXU);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str)
					total += ft_putstr(str);
				else
					total += write(1, "(null)", 7);
			}
			else if (*format == 'c')
			{
				num = va_arg(args, int);
				total += write(1, &num, 1);
			}
			else if (*format == 'p')
			{
				ptr = va_arg(args, void *);
				if (!ptr)
					total += write(1, "(nil)", 5);
				else
				{
					total += write(1, "0x", 2);
					total += ft_putnbr_base((long int)ptr, HEX);
				}
			}
			else if (*format == '%')
			{
				total += write(1, "%", 1);
			}
			format++;
		}
		else
		{
			total += write(1, format++, 1);
		}
	}
	va_end(args);
	return (total);
}
