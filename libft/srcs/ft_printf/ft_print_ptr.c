/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:07:21 by loribeir          #+#    #+#             */
/*   Updated: 2024/11/24 15:19:23 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long ptr, int *count)
{
	char	hex[16];
	int		i;

	i = 0;
	if (!ptr)
		(*count) += write(1, "(nil)", 5);
	if (ptr != 0)
	{
		while (ptr > 0)
		{
			hex[i++] = HEX_LOWER[ptr % 16];
			ptr = ptr / 16;
		}
		(*count) += write(1, "0x", 2);
		while (i > 0)
			(*count) += write(1, &hex[--i], 1);
	}
}
