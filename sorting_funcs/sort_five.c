/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:16:18 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/09 16:49:29 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_of_five(t_list **stack_a, t_list **stack_b)
{
	long	smallest_value;
	int		index;

	index = 0;
	smallest_value = 0;
	min_in_list(*stack_a, &index, &smallest_value);
	if (index <= (list_len(*stack_a) / 2))
	{
		if (move_min_to_top(stack_a, smallest_value, 1)
			&& !check_if_sorted(*stack_a))
			sort_it(stack_a, stack_b, 1);
	}
	else if (index > (list_len(*stack_a) / 2))
	{
		if (move_min_to_top(stack_a, smallest_value, 0)
			&& !check_if_sorted(*stack_a))
			sort_it(stack_a, stack_b, 1);
	}
	free_list(stack_a);
}

void	sort_it(t_list **stack_a, t_list **stack_b, int isFive)
{
	if (isFive)
	{
		pb(stack_b, stack_a);
		add_fix_index(stack_a);
		sort_of_four(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		pb(stack_b, stack_a);
		sort_of_three(stack_a);
		pa(stack_a, stack_b);
	}
}
