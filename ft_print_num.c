/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:03:23 by jleal             #+#    #+#             */
/*   Updated: 2025/04/26 18:42:15 by jleal            ###   ########.fr       */
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
		tot += ft_printchar("-");
		nbr = -nbr;
	}
	tot += print_nbr_base(nbr, base);
	return (tot);
}
