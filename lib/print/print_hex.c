/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 16:09:12 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/09 16:14:12 by mshegow       ########   odam.nl         */
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

