/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 16:09:12 by mshegow       #+#    #+#                 */
/*   Updated: 2023/12/04 16:34:43 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/**
* calculates the length of the hexadecimal representation of an unsigned num.
* @return	int					The lenght of characters of the pointer.
*/
int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

/**
* recursive function that prints the hexadecimal representation of an unsigned
* num. 
* if num is greater than 9, it checks the format argument. 
* if format is 'x', it prints the corresponding lowercase hexadecimal character; 
* if format is 'X', it prints the corresponding uppercase hexadecimal character.
*/

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

/**
* prints the hexadecimal representation of an unsigned integer num.
* @return	int					The lenght of characters of the hex.
*/

int	print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}
