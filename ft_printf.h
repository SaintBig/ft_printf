/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:40:55 by jleal             #+#    #+#             */
/*   Updated: 2025/04/26 19:39:16 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

int	ft_printf(const char *format, ...);

int	print_ptr(void *ptr);

int	ft_putnbr_base(long int nbr, char *base);

int	ft_strlen_new(char *s);

int	ft_printchar(int c);

int	ft_printstr(char *str);

#endif