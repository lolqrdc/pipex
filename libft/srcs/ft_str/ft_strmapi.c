/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:51:07 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/28 10:29:54 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*char	to_lower(unsigned int index, char c)
{
	(void)index;
	if (c >= 'A' && c <= 'Z') 
		return(c + 32);
	return (c);
}
int main(void)
{
	char *s = "BONJOUR";
	char *newstr = ft_strmapi(s, to_lower);
	printf("str de base : %s\n", s);
	printf("nouvelle str : %s\n", newstr);
	free(newstr);
	return(0);
}*/
