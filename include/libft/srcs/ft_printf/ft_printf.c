/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:08:20 by loribeir          #+#    #+#             */
/*   Updated: 2024/11/24 16:02:58 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *specifier, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, specifier);
	i = 0;
	count = 0;
	while (specifier[i])
	{
		if (specifier[i] == '%')
			check_specifier(args, specifier[++i], &count);
		else
		{
			write(1, &specifier[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	check_specifier(va_list args, char spec, int *count)
{
	if (spec == 'c')
		ft_print_char(va_arg(args, int), count);
	else if (spec == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (spec == 'p')
		ft_print_ptr(va_arg(args, unsigned long), count);
	else if (spec == 'd' || spec == 'i')
		ft_print_decimal(va_arg(args, int), count);
	else if (spec == 'u')
		ft_print_unsigned_dec(va_arg(args, unsigned int), count);
	else if (spec == 'x')
		ft_print_lower_hex(va_arg(args, int), count);
	else if (spec == 'X')
		ft_print_upper_hex(va_arg(args, int), count);
	else if (spec == '%')
		ft_print_sign(count);
	return (*count);
}
/*int main()
{
// test00 char
	ft_printf("Bonjour, %c\n", 'R');
	printf("Bonjour, %c\n", 'R');
// test01 string
	ft_printf("Bonjour, %s\n", "le monde");
	printf("Bonjour, %s\n", "le monde");
// test02 pointer
	int num = 42;
	void *ptr = &num;
	ft_printf("Bonjour, %p\n", ptr);
	printf("Bonjour, %p\n", ptr);
//test03 decimal
	ft_printf("Bonjour, %d ou %i\n", 42, -42);
	printf("Bonjour, %d ou %i\n", 42, -42);
//test04 unsigned
	ft_printf("Bonjour, %u\n", 4294967295U);
	printf("Bonjour, %u\n", 4294967295U);
//test05 hex lower
	ft_printf("Bonjour, %x\n", 255);
	printf("Bonjour, %x\n", 255);
//test06 hex upper
	ft_printf("Bonjour, %X\n", 255);
	printf("Bonjour, %X\n", 255);
//test07 percent
	ft_printf("Bonjour, %%\n");
	printf("Bonjour, %%\n");
}*/