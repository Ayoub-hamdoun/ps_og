/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oneop_create_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:28:19 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/11 18:14:32 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_list(char *argv[], int argc, t_list **stack, int *error)
{
	int			i;
	int			j;
	static char	**tab;
	t_list		*node;

	i = 1;
	while (i < argc)
	{
		tab = ft_split(argv[i], ' ');
		if (tab == NULL || ft_isws(argv[i], error))
			break ;
		j = 0;
		while (tab[j])
		{
			if (check_non_digit(tab[j]))
				(*error)++;
			node = ft_lstnew(ft_atoi(tab[j], error));
			ft_lstadd_back(stack, node);
			j++;
		}
		free_arr(tab);
		i++;
	}
	check_doubles(stack, error);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	if (rev_rotate(head_a) && rev_rotate(head_b))
		write(1, "rrr\n", 4);
}
