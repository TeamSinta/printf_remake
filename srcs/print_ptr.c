/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 14:53:21 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/13 16:16:08 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/**
* @notice	This function counts the lenght of a pointer.
* @param	uintptr_t			The unsigned integer pointer to count lenght.
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
* @notice	This function converts a pointer.
* @param	uintptr_t			The unsigned integer pointer to print.
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
* @notice	This function checks the pointer of something, converts it, prints
*			it and counts its pointer lenght.
* @param	unsigned_long_long	The unsigned integer pointer to print.
* @return	int					The lenght of characters of the printed
*								pointer.
*/

int	print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
	{
		len += write(1, "0", 1);
	}
	else
	{
		put_ptr(ptr);
		len += ptr_len(ptr);
	}
	return (len);
}
