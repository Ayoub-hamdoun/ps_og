/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_n_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:35:16 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/03 19:56:39 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_to_b(t_list **stack_a, t_list **stack_b, int len, int chunk_len)
{
	int	i;

	i = 1;
	if (!len || !(*stack_a))
		return ;
	while (len)
	{
		if ((*stack_a)->sorted_index < (i + chunk_len))
		{
			pb(stack_b, stack_a);
			if ((*stack_b)->sorted_index < i)
				rb(stack_b);
			i++;
			len--;
		}
		else
			ra(stack_a);
		if (list_len(*stack_b) > 1 && (*stack_b)->data < (*stack_b)->next->data)
			sb(stack_b);
	}
}

void	move_a(t_list **stack_a, t_list **stack_b, int *max_i, int *max_i_pos)
{
	int	len;

	len = list_len(*stack_b);
	while (len)
	{
		add_fix_index(stack_b);
		max_index_in_list(*stack_b, max_i, max_i_pos);
		if (move_max_top(stack_b, *max_i_pos <= len / 2, *max_i))
			pa(stack_a, stack_b);
		len--;
	}
}
