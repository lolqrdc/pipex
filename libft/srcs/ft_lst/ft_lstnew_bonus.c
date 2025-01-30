/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:13:11 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/30 21:56:58 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
/*int main(void)
{
	char *str = "Bonjour";
	t_list *node1 = ft_lstnew(str);

	if (node1)
	{
		printf("Content : %s\n", (char *) node1->content);
		printf("Next : %p\n\n", (void *)node1->next);
	}
	free(node1);
	return (0);
}*/