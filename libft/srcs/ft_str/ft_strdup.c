/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:22:58 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/26 18:29:12 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(source);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (source[i])
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*int main(void)
{
	const char *src;
	src = "sdfgh";
	printf("ft_strdup : %s\n", ft_strdup(src));
	printf("strdup : %s\n", strdup(src));
	return(0);
}*/