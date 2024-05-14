/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:10:37 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/02 17:39:51 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **head_a)
{
	if (rotate(head_a))
		write(1, "ra\n", 3);
}

void	rb(t_list **head_b)
{
	if (rotate(head_b))
		write(1, "rb\n", 3);
}

void	rr(t_list **head_a, t_list **head_b)
{
	if (rotate(head_a) && rotate(head_b))
		write (1, "rr\n", 3);
}

void	rra(t_list **head_a)
{
	if (rev_rotate(head_a))
		write(1, "rra\n", 4);
}

void	rrb(t_list **head_b)
{
	if (rev_rotate(head_b))
		write(1, "rrb\n", 4);
}
