/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:49:45 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/30 08:05:57 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy((str + len_s1), s2, (len_s2 + 1));
	str[len_s1 + len_s2] = '\0';
	return (str);
}
/*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	str = malloc(sizeof(char) *(i + j + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}*/
/*int main(void)
{
	const char	*str1 = "Bonjour";
	const char	*str2 = "demain";
	char		*strjoin;
	printf("%s\n%s\n", str1, str2);
	strjoin = ft_strjoin(str1, str2);
	printf("%s\n", strjoin);
	free(strjoin);
	return (0);
}*/
