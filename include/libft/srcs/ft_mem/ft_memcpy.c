/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:41:58 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/19 18:46:03 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*de;
	const unsigned char	*sr;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	de = (unsigned char *) dest;
	sr = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		de[i] = sr[i];
		i++;
	}
	return (dest);
}
/*int main(void)
{
    char dest[20];
    char src[] = "Bonjour.";

    printf("%s\n", (char *)memcpy(dest, src, 5));
    printf("%s\n", (char *)ft_memcpy(dest, src, 5));
    return (0);    
}*/