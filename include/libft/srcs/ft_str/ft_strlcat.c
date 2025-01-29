/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:17:03 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/24 11:44:01 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	while (src[i] && (i < size - len_dst - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*int main(void)
{
	char	dst[50] = "42";
	char	dst2[50] = "42";
	char 	*src = "Cursus";
	printf("\n~%s~\n", dst) ;
	printf("ft_strlcat : %zu\n", ft_strlcat(dst, src, 50));
	printf("\n~%s~\n", dst) ;
	printf("strlcat : %zu\n", strlcat(dst2, src, 50));
	printf("\n~%s~\n", dst) ;
	return(0);
}*/