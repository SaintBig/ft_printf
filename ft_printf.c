/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:50:21 by jleal             #+#    #+#             */
/*   Updated: 2025/04/19 17:29:36 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

static int	ft_printstr(char *str)
{
	int	tot;

	tot = 0;
	if (!str)
		return (tot += write(1, "(null)", 6));
	while (*str)
		tot += write(1, str++, 1);
	return (tot);
}

static int	ft_findf(va_list args, const char format)
{
	int	tot;

	tot = 0;
	if (format == 's')
		tot += ft_printstr(va_arg(args, char *));
	else if (format == 'c')
		tot += ft_printchar(va_arg(args, int));
	else if (format == 'd')
		tot += ft_putnbr_base((va_arg(args, int)), "0123456789");
	else if (format == 'u')
		tot += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (format == 'i')
		tot += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (format == 'x')
		tot += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		tot += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
		tot += print_ptr(va_arg(args, void *));
	else if (format == '%')
		tot += write(1, "%", 1);
	return (tot);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			tot;

	va_start(args, format);
	tot = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tot += ft_findf(args, *format);
			format++;
		}
		else
			tot += write(1, format++, 1);
	}
	va_end(args);
	return (tot);
}
