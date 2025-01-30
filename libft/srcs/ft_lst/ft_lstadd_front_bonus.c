/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolq <lolq@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:53:54 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/30 21:56:54 by lolq             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
int main(void)
{
	t_list	*new = NULL;
	ft_lstadd_front(&new, ft_lstnew("Bonjour"));
	if (new && strcmp((char*)new->content, "Bonjour") == 0 && new->next == NULL)
		printf("Bonjour added\n");
	return(0);
}*/