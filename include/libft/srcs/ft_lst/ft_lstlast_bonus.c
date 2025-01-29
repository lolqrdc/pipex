/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:19:53 by loribeir          #+#    #+#             */
/*   Updated: 2024/10/31 07:47:26 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
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
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
int main(void)
{
	t_list	*list = NULL;
	t_list	*last;

	last = ft_lstlast(list);
	printf("Actuellement la chaine est vide : %p\n", (void*)last);

	ft_lstadd_front(&list, ft_lstnew("un element"));
	last = ft_lstlast(list);
	printf("+1 element : %s\n",(char*)last->content);
	return (0);
}*/