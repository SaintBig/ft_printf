/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:03:23 by jleal             #+#    #+#             */
/*   Updated: 2025/04/29 14:24:09 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_new(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	print_nbr_base(long int nb, char *base)
{
	int		base_val;
	char	output;
	int		tot;

	tot = 0;
	base_val = ft_strlen_new(base);
	if (nb >= base_val)
		tot += print_nbr_base(nb / base_val, base);
	output = base[nb % base_val];
	tot += ft_printchar(output);
	return (tot);
}

int	ft_putnbr_base(long int nbr, char *base)
{
	int	tot;

	tot = 0;
	if (nbr == -9223372036854775807L -1L)
		return (ft_printstr("-9223372036854775807"));
	if (nbr < 0)
	{
		tot += ft_printchar('-');
		nbr = -nbr;
	}
	tot += print_nbr_base(nbr, base);
	return (tot);
}

static int	print_ulong(size_t nb)
{
	char	*base;
	char	output;
	int		tot;

	tot = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
		tot += print_ulong(nb / 16);
	output = base[nb % 16];
	tot += ft_printchar(output);
	return (tot);
}

int	print_ptr(void *ptr)
{
	int	tot;

	tot = 0;
	if (!ptr)
		return (tot += ft_printstr("(nil)"));
	tot += ft_printstr("0x");
	tot += print_ulong((size_t) ptr);
	return (tot);
}
