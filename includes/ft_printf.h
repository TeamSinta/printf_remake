/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 18:00:18 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/14 17:27:38 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"

# define __CONVERTER "cspdiuxX%"

int			ft_printf(const char *str, ...);
int			print_hex(unsigned int num, const char format);
int			print_nbr(int num);
int			print_ptr(unsigned long long ptr);
int			print_str(char *str);
int			print_unsigned(unsigned int i);

#endif
