/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:48:32 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/13 20:14:39 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_non_digit(char *str)
{
	int	i;
	int	e;

	i = -1;
	e = 0;
	while (str[++i])
	{
		if (i > 0 && (str[i] == '-' || str[i] == '+') && str[i - 1] != ' ')
		{
			e++;
			break ;
		}
		if (str[i] == '-' || str[i] == '+' )
			i++;
		if (str[i] < '0' || str[i] > '9')
		{
			e++;
			break ;
		}
	}
	return (e);
}

void	check_doubles(t_list **lst, int *error)
{
	t_list	*h1;
	t_list	*h2;

	h1 = *lst;
	while (h1)
	{
		if (h1->data > INT_MAX || h1->data < INT_MIN)
		{
			(*error)++;
			break ;
		}
		h2 = h1->next;
		while (h2)
		{
			if (h1->data == h2->data)
			{
				(*error)++;
				break ;
			}
			h2 = h2->next;
		}
		h1 = h1->next;
	}
}

int	check_if_sorted(t_list *head)
{
	while (head && head->next)
	{
		if (head->data < head->next->data)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

void	free_list(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void	free_arr(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}
