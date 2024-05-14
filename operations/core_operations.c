/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:14:40 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/02 18:06:43 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!(*head) || !(*head)->next)
		return (0);
	first = *head;
	second = (*head)->next;
	third = (*head)->next->next;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	*head = second;
	return (1);
}

int	push(t_list **head_d, t_list **head_s)
{
	t_list	*tmp;
	t_list	*top_2;

	tmp = *head_s;
	if (!tmp)
		return (0);
	(*head_s) = (*head_s)->next;
	if (*head_s)
		(*head_s)->prev = NULL;
	if (!(*head_d))
	{
		*head_d = ft_lstnew(tmp->data);
		(*head_d)->sorted_index = tmp->sorted_index;
		free(tmp);
		return (1);
	}
	top_2 = ft_lstnew(tmp->data);
	top_2->sorted_index = tmp->sorted_index;
	free(tmp);
	ft_lstadd_front(head_d, top_2);
	return (1);
}

int	rotate(t_list **head)
{
	t_list	*to_b_shifted;
	t_list	*tmp;

	if (!(*head) || !(*head)->next)
		return (0);
	to_b_shifted = *head;
	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	endoflist(&tmp);
	tmp->next = to_b_shifted;
	to_b_shifted->prev = tmp;
	to_b_shifted->next = NULL;
	return (1);
}

int	rev_rotate(t_list **head)
{
	t_list	*to_b_shfted;
	t_list	*last;

	if (!(*head) || !(*head)->next)
		return (0);
	to_b_shfted = *head;
	endoflist(&to_b_shfted);
	last = to_b_shfted->prev;
	to_b_shfted->next = (*head);
	to_b_shfted->prev = NULL;
	(*head)->prev = to_b_shfted;
	last->next = NULL;
	*head = to_b_shfted;
	return (1);
}
