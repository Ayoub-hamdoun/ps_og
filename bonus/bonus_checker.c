/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:59:21 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/11 14:29:44 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/get_next_line/get_next_line.h"
#include "../push_swap.h"

void	double_ops(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!my_strcmp(line, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!my_strcmp(line, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!my_strcmp(line, "rrr\n"))
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
}

int	badargs(t_list **stack_a)
{
	write(2, "Error\n", 6);
	free_list(stack_a);
	exit (1);
}

int	decesion(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b) && check_if_sorted(*stack_a))
	{
		free_list(stack_a);
		write(1, "OK\n", 3);
		exit (0);
	}
	else
	{
		free_list(stack_a);
		free_list(stack_b);
		write(1, "KO\n", 3);
		exit (0);
	}
}

int	which_op(char *line, t_list **stack_a, t_list **stack_b)
{
	if (my_strcmp(line, "sa\n") == 0)
		swap(stack_a);
	else if (my_strcmp(line, "sb\n") == 0)
		swap(stack_b);
	else if (my_strcmp(line, "ss\n") == 0)
		double_ops(stack_a, stack_b, line);
	else if (my_strcmp(line, "pa\n") == 0)
		push(stack_a, stack_b);
	else if (my_strcmp(line, "pb\n") == 0)
		push(stack_b, stack_a);
	else if (my_strcmp(line, "ra\n") == 0)
		rotate(stack_a);
	else if (my_strcmp(line, "rb\n") == 0)
		rotate(stack_b);
	else if (my_strcmp(line, "rr\n") == 0)
		double_ops(stack_a, stack_b, line);
	else if (my_strcmp(line, "rra\n") == 0)
		rev_rotate(stack_a);
	else if (my_strcmp(line, "rrb\n") == 0)
		rev_rotate(stack_b);
	else if (my_strcmp(line, "rrr\n") == 0)
		double_ops(stack_a, stack_b, line);
	else
		badargs(stack_a);
	return (1);
}

int	main(int ac, char *av[])
{
	int		error;
	int		len;
	char	*line;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	error = 0;
	create_list(av, ac, &stack_a, &error);
	len = list_len(stack_a);
	is_valid_b(&stack_a, &error, len);
	line = get_next_line(0);
	while (line)
	{
		which_op(line, &stack_a, &stack_b);
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	free(line);
	decesion(&stack_a, &stack_b);
}
