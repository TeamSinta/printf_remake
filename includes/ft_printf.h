/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 16:10:26 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/13 16:10:29 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_hex(unsigned int num, const char conversion);
int	print_nbr(int num);
int	print_ptr(unsigned long long ptr);
int	print_str(char *str);
int	print_unsigned(unsigned int i);

#endif