/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:45:03 by loribeir          #+#    #+#             */
/*   Updated: 2024/11/24 15:30:00 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_lower_hex(int nb, int *count)
{
	char			hex_lower[16];
	unsigned int	nbr;
	int				i;

	nbr = nb;
	i = 0;
	if (nbr == 0)
		(*count) += write(1, "0", 1);
	while (nbr > 0)
	{
		hex_lower[i++] = HEX_LOWER[nbr % 16];
		nbr = nbr / 16;
	}
	while (i > 0)
		(*count) += write(1, &hex_lower[--i], 1);
}

void	ft_print_upper_hex(int nb, int *count)
{
	char			hex_upper[16];
	unsigned int	nbr;
	int				i;

	nbr = nb;
	i = 0;
	if (nbr == 0)
		(*count) += write(1, "0", 1);
	while (nbr > 0)
	{
		hex_upper[i++] = HEX_UPPER[nbr % 16];
		nbr = nbr / 16;
	}
	while (i > 0)
		(*count) += write(1, &hex_upper[--i], 1);
}
