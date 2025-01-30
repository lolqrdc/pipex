/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsadd_back_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:57 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/31 08:21:51 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
		tmp->next = new;
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
	t_list *list = NULL;
	t_list	*node;

	ft_lstadd_back(&list, ft_lstnew(ft_strdup("Bonjour")));
	if (list && strcmp((char*)list->content, "Bonjour") == 0 
		&& list->next == NULL);
		printf("Liste vide, test bon.\n");
}*/
