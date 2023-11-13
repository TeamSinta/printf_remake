/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_nbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 14:41:37 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/13 15:43:26 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_nbr(int num)
{
	int		len;
	char	*numchar;

	len = 0;
	numchar = ft_itoa(num);
	len = print_str(numchar);
	free(numchar);
	return (len);
}
