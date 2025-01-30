/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:07:27 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/19 18:46:09 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (s);
}
/*int main(void)
{
    char str[] = "Hello, World.";
    printf("%s\n", (char *)memset(str,  '-', 1));
    printf("%s\n", (char *)ft_memset(str, '*', 1));
    return (0);
}*/