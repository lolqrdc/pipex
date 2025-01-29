/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:39:44 by loribeir          #+#    #+#             */
/*   Updated: 2024/11/24 13:57:05 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_sign(int *count)
{
	ft_putchar('%');
	(*count)++;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
