/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:46:32 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/19 18:45:28 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*tmp++ = '\0';
		i++;
	}
}
/*int main(void)
{
    char str[] = "Hello World.";
    printf("str : %s\n", str);

    size_t i = 0;
    size_t l = strlen(str);
    ft_bzero(str, 2);
    while (i < l)
    {
        printf("%c", str[i]);
        i++;
    }
    return(0);
}*/