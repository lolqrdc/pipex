/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:55:21 by loribeir          #+#    #+#             */
/*   Updated: 2024/11/24 14:15:31 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
		(*count) += write(1, "(null)", 6);
	while (str != NULL && str[i] != '\0')
	{
		(*count) += write(1, &str[i], 1);
		i++;
	}
}
