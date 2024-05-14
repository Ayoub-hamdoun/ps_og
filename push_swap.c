/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:00:38 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/03 20:01:15 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_of_two(t_list **stack_a)
{
	sa(stack_a);
	free_list(stack_a);
}

void	main_sort(t_list **stack_a, t_list **stack_b, int len)
{
	if (len == 2)
		sort_of_two(stack_a);
	if (len == 3)
		sort_of_three(stack_a);
	else if (len == 4)
		sort_of_four(stack_a, stack_b);
	else if (len == 5)
		sort_of_five(stack_a, stack_b);
	else
		sort_of_n(stack_a, stack_b, len);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		e;
	int		len;

	e = 0;
	stack_a = NULL;
	stack_b = NULL;
	create_list(av, ac, &stack_a, &e);
	len = list_len(stack_a);
	is_valid(&stack_a, &e, len);
	add_fix_index(&stack_a);
	main_sort(&stack_a, &stack_b, len);
	return (0);
}
