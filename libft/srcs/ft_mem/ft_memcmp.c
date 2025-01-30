/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:18:55 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/21 07:55:30 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (st1[i] != st2[i])
		{
			if (st1[i] > st2[i])
				return (st1[i] - st2[i]);
			if (st1[i] < st2[i])
				return (st1[i] - st2[i]);
		}
		i++;
	}
	return (0);
}
/*int main(void)
{
	char src1[] = "Hellobonjour";
	char src2[] = "Hello";
	printf("ft_memcmp : %d\n", ft_memcmp(src1, src2, 30));
	printf("memcmp : %d\n", memcmp(src1, src2, 30));
	return (0);
}*/