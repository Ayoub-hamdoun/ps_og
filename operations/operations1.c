/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:57:49 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/02 17:39:48 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **head_a, t_list **head_b)
{
	if (push(head_a, head_b))
		write(1, "pa\n", 3);
}

void	pb(t_list **head_b, t_list **head_a)
{
	if (push(head_b, head_a))
		write(1, "pb\n", 3);
}

void	sa(t_list **head_a)
{
	if (swap(head_a))
		write(1, "sa\n", 3);
}

void	sb(t_list **head_b)
{
	if (swap(head_b))
		write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b)
{
	if (swap(head_a) && swap(head_b))
		write(1, "ss\n", 3);
}
