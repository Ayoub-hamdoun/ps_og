/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:36:50 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/02 17:08:32 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(long element)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = element;
	new->sorted_index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if ((!lst || !new))
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = (*lst);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

void	endoflist(t_list **node)
{
	while ((*node) && (*node)->next)
		(*node) = (*node)->next;
}
