/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mshegow <mshegow@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 12:08:05 by mshegow       #+#    #+#                 */
/*   Updated: 2023/11/13 18:29:05 by mshegow       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

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
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int main() {
//     // Test cases for ft_printf with limited format specifiers
//     printf("Test Case 1 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("Hello, World!\n"), printf("Hello, World!\n"));
//     printf("Test Case 2 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("This is a number: %d\n", 42), 
				// printf("This is a number: %d\n", 42));
//     printf("Test Case 3 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("String: %s\n", "success"), 
			// printf("String: %s\n", "success"));
//     printf("Test Case 4 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("Pointer: %p\n", (void *)0x12345678), 

			// printf("Pointer: %p\n", (void *)0x12345678));
//     printf("Test Case 5 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("Decimal: %d\n", 123), printf("Decimal: %d\n", 123));
//     printf("Test Case 6 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("Unsigned: %u\n", 456), printf("Unsigned: %u\n", 456));
//     printf("Test Case 7 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("Hexadecimal: %x\n", 255), 
				// printf("Hexadecimal: %x\n", 255));
//     printf("Test Case 8 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("Uppercase Hexadecimal: %X\n", 255), 
			// printf("Uppercase Hexadecimal: %X\n", 255));
//     printf("Test Case 9 - ft_printf: %d, printf: %d\n", 
// 			ft_printf("Percent sign: %%\n"), printf("Percent sign: %%\n"));

//     return 0;
// }