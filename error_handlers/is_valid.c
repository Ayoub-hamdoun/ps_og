/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:20:05 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/11 19:56:08 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_valid(t_list **stack, int *error, int len)
{
	if (*error)
	{
		free_list(stack);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (check_if_sorted(*stack) || len <= 1)
	{
		free_list(stack);
		exit(1);
	}
}

void	is_valid_b(t_list **stack, int *error, int len)
{
	if (*error)
	{
		free_list(stack);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (len == 0)
		exit(0);
}
