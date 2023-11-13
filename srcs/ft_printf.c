/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 12:08:05 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/13 16:11:02 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	arg_conversion(va_list args, const char conversion)
{
	int	len;

	len = 1;
	if (conversion == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (conversion == 's')
		len = print_str(va_arg(args, char *));
	else if (conversion == 'p')
		len = print_ptr(va_arg(args, unsigned long long));
	else if (conversion == 'd' || conversion == 'i')
		len = print_nbr(va_arg(args, int));
	else if (conversion == 'u')
		len = print_unsigned(va_arg(args, unsigned int));
	else if (conversion == 'x' || conversion == 'X')
		len = print_hex(va_arg(args, unsigned int), conversion);
	else if (conversion == '%')
		ft_putstr_fd("%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += arg_conversion(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], i);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
