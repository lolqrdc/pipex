/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:15:10 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/22 17:41:01 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	if (nmemb * size > 2147483647)
	{
		return (NULL);
	}
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
/*int main(void)
{
	char *str;
	char *str1;
	
	str1 = calloc(8, 20);
	str = ft_calloc(8, 20);
	printf("ft_calloc : %s\n", str);
	printf("calloc : %s\n", str1);
	while ()
	free(str);
	free(str1);
	return (0);
}*/