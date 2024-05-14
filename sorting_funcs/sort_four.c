/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:15:13 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/02 17:39:35 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_of_four(t_list **stack_a, t_list **stack_b)
{
	int		index;
	long	smallest_value;

	if (check_if_sorted(*stack_a))
	{
		free_list(stack_a);
		return ;
	}
	index = 0;
	smallest_value = 0;
	min_in_list(*stack_a, &index, &smallest_value);
	if (index <= (list_len(*stack_a) / 2))
	{
		if (move_min_to_top(stack_a, smallest_value, 1)
			&& !check_if_sorted(*stack_a))
			sort_it(stack_a, stack_b, 0);
	}
	else if (index > (list_len(*stack_a) / 2))
	{
		if (move_min_to_top(stack_a, smallest_value, 0)
			&& !check_if_sorted(*stack_a))
			sort_it(stack_a, stack_b, 0);
	}
	free_list(stack_a);
}

void	min_in_list(t_list *stack_a, int *i, long *smallest_value)
{
	t_list	*tmp;

	*i = stack_a->index;
	*smallest_value = stack_a->data;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->data < *smallest_value)
		{
			*i = tmp->index;
			*smallest_value = tmp->data;
		}
		tmp = tmp->next;
	}
}

void	add_fix_index(t_list **stack)
{
	int		i;
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

int	move_min_to_top(t_list **stack_a, long smallest_value, int isUpper)
{
	if (isUpper)
	{
		while ((*stack_a)->data != smallest_value)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->data != smallest_value)
			rra(stack_a);
	}
	return (1);
}
