/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:40:55 by jleal             #+#    #+#             */
/*   Updated: 2025/04/17 17:41:33 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
//#include "libft.h"

# define HEX "0123456789abcdef"
# define HEXU "0123456789ABCDEF"
# define DEC "0123456789"

int	ft_printf(const char *format, ...);

#endif