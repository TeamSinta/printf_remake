/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_unsigned.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 14:54:16 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/09 14:59:51 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_unsigned(unsigned int i)
{
	int		len;
	char	*numchar;

	len = 0;

	if (i == 0)
	{

		ft_putchar_fd('0', 1);
		len++;
	}
	else
	{
		numchar = ft_unsigned_itoa(i);
		len += print_str(numchar);
		free(numchar);
	}
	return (len);
}
