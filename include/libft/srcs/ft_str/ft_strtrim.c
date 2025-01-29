/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:50:39 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/30 09:09:20 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	char	*str;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}
/*int main(void)
{
	char	*str;
	char	*set;
	str = "*+*+ Bonjour*Le+M0nde -*-*-";
	set = "*-+";
	char	*trim;
	trim = ft_strtrim(str,set);
	printf("Avant ft_strtrim :%s\n", str);
	printf("Apres ft_strtrim: %s\n", trim);
	free(trim);
	return (0);
}*/