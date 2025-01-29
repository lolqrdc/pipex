/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:33:32 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/28 07:46:26 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencheck(long int i)
{
	int	size;

	size = 0;
	if (i <= 0)
	{
		size = 1;
		i = i * -1;
	}
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	tmp;
	int		len;

	tmp = n;
	len = ft_lencheck(tmp);
	str = malloc(sizeof(char ) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (tmp < 0)
	{
		tmp = tmp * -1;
		str[0] = '-';
	}
	str[len] = '\0';
	while (--len >= (n < 0))
	{
		str[len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (str);
}
/*int main(void)
{
	int		n = -214783648;
	char	*itoa;
	
	itoa = ft_itoa(n);
	printf("%s\n", itoa);
	free(itoa);
	return(0);
}*/
