/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 14:53:21 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/14 18:13:01 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

/**
* This function counts the lenght of a pointer.
* @return	int					The lenght of characters of the pointer.
*/

int	ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

/**
* This function converts a pointer.
* @return	void				No return value needed now.
*/

void	put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

/**
*This function checks the pointer of something, converts it, prints
*			it and counts its pointer lenght.
* @param	unsigned_long_long	The unsigned integer pointer to print.
* @return	int					The lenght of characters of the printed
*								pointer.
*/

int	print_ptr(unsigned long long ptr)
{
	int	len;

	len = 2;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (len += 3);
	}
	ft_putstr_fd("0x", 1);
	put_ptr(ptr);
	len += ptr_len(ptr);
	return (len);
}
