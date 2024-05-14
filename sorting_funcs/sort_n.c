/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:54:34 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/10 16:21:28 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_sorted_index(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->data > tmp1->data)
				(tmp->sorted_index)++;
			else
				(tmp1->sorted_index)++;
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

void	sort_of_n(t_list **stack_a, t_list **stack_b, int len)
{
	int	chunk_len;
	int	max_i;
	int	max_i_pos;

	max_i = 0;
	max_i_pos = 0;
	chunk_len = which_chunk(len);
	add_sorted_index(stack_a);
	move_to_b(stack_a, stack_b, len, chunk_len);
	move_a(stack_a, stack_b, &max_i, &max_i_pos);
	free_list(stack_a);
}

int	move_max_top(t_list **stack_b, int isUpper, int max_index)
{
	if (isUpper)
	{
		while ((*stack_b)->sorted_index != max_index)
			rb(stack_b);
	}
	else
	{
		while ((*stack_b)->sorted_index != max_index)
			rrb(stack_b);
	}
	return (1);
}

void	max_index_in_list(t_list *stack, int *max_i, int *pos)
{
	t_list	*tmp;

	tmp = stack;
	*max_i = stack->sorted_index;
	while (tmp)
	{
		if (tmp->sorted_index > *max_i)
		{
			*max_i = tmp->sorted_index;
			*pos = tmp->index;
		}
		tmp = tmp->next;
	}
}

int	which_chunk(int len)
{
	if (len <= 100)
		return (15);
	else if (len <= 500)
		return (30);
	else
		return (45);
}
