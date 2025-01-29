/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:41:32 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/21 07:55:26 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tofind;
	unsigned char	*src;
	size_t			i;	

	tofind = (unsigned char)c;
	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == tofind)
			return ((void *) src + i);
		i++;
	}
	return (NULL);
}
/*int main(void)
{
	char src[] = "Hello, bonjour";
	char *result = ft_memchr(src, 'o', 15);
	char *resultv = memchr(src, 'o', 15);
	printf("ft_memchr : %s\n", result);
	printf("memchr : %s\n", resultv);
	return (0);
}*/