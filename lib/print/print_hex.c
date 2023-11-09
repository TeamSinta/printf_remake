/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 16:09:12 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/09 16:34:16 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	hex_len(unsigned int num)
{
	int		len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

void	put_hex(unsigned int num, const char conversion)
{
	if(num >= 16)
	{
		put_hex(num/16, conversion);
		put_hex(num % 16, conversion);
	}
	else
	{
		
	}
}



int	print_hex(unsigned int num, const char conversion)
{
	if(num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else
		put_hex(num, conversion);
	return (hex_len(num));
}