/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:02:46 by loribeir          #+#    #+#             */
/*   Updated: 2024/12/03 15:04:13 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| ((c >= '0' && c <= '9')))
	{
		return (1);
	}
	return (0);
}
/*int main(void)
{
    int i = '+';
    printf("%d\n", isalnum(i));
    printf("%d\n", ft_isalnum(i));
    return (0);
}*/
