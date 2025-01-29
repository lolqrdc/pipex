/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:16:08 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/28 11:46:47 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, (s + i));
		i++;
	}
}
/*void	to_lower(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'A' && *c <= 'Z') 
		*c = *c + 32;
}
int main(void)
{
	char s[] = "BJR";
	printf("str de base : %s\n", s);
	ft_striteri(s, to_lower);
	printf("newstr : %s\n", s);
	return (0);
}*/
