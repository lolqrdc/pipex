/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:35:01 by loribeir          #+#    #+#             */
/*   Updated: 2025/02/04 09:06:20 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnbr(const char *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

static void	ft_freetab(char **str, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free (str[i]);
		i++;
	}
	free (str);
}

static char	**ft_cpystr(char **str, char const *s, char c, int nbwords)
{
	int	start;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && j < nbwords)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			str[j] = ft_substr(s, start, i - start);
			if (!str[j])
				return (ft_freetab(str, j), NULL);
		}
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		nbrwords;
	char	**str;

	if (!s)
		return (NULL);
	nbrwords = ft_countnbr(s, c);
	str = malloc((nbrwords + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (ft_cpystr(str, s, c, nbrwords));
}

/*int main(void)
{
	char *str = "             ";
	char **tab = ft_split(str, ' ');
	
	int i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	//printf("%s\n",tab[i]);
	return(0);
}*/