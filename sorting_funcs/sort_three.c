/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:49:05 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/02 17:38:10 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_of_three(t_list **stack_a)
{
	t_list	*tmp;

	if (check_if_sorted(*stack_a))
		return ;
	tmp = (*stack_a)->next;
	if ((*stack_a)->data < tmp->data)
		case_0(stack_a);
	else if ((*stack_a)->data > tmp->data)
		case_1(stack_a);
	free_list(stack_a);
}

void	case_0(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a)->next->next;
	if ((*stack_a)->data > tmp->data)
		rra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	case_1(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp_1;

	tmp = (*stack_a)->next->next;
	if ((*stack_a)->data < tmp->data)
		sa(stack_a);
	else
	{
		tmp_1 = tmp->prev;
		if (tmp_1->data > tmp->data)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else
			ra(stack_a);
	}
}
