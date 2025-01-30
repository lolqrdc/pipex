/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:26:30 by loribeir          #+#    #+#             */
/*   Updated: 2024/11/24 15:22:52 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_decimal(int nb, int *count)
{
	if (nb == -2147483648)
	{
		(*count) += write(1, "-", 1);
		(*count) += write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		(*count) += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_print_decimal(nb / 10, count);
	nb = (nb % 10) + '0';
	(*count) += write(1, &nb, 1);
}

void	ft_print_unsigned_dec(unsigned int nb, int *count)
{
	if (nb >= 10)
		ft_print_unsigned_dec(nb / 10, count);
	nb = (nb % 10) + '0';
	(*count) += write(1, &nb, 1);
}
