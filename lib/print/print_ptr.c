/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 14:53:21 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/09 16:04:32 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

.

int	ptr_len(unsigned int *num)
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


int	put_ptr(unsigned int *num)
{
	if (num >= 16)
	{
		put_ptr(num / 16);
		put_ptr(num % 16);
	}
	else
	{
		if(num <= 9)
			ft_putchar_fd((num + '0'), 1)
		else
			ft_putchar_fd((num - 10 + 'a'))
	}
}