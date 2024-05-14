/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:49:45 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/11 18:33:14 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

long	ft_atoi(char *str, int *error)
{
	int		i;
	long	signe;
	long	res;
	long	temp;

	i = 0;
	signe = 1;
	res = 0;
	temp = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (temp > res)
			return ((*error)++);
		temp = res;
	}
	return (res * signe);
}

int	list_len(t_list	*lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	my_strcmp(char *str0, char *str1)
{
	int	i;

	i = 0;
	while (str0[i] && str1[i] && (str0[i] == str1[i]))
		i++;
	return (str0[i] - str1[i]);
}

int	ft_isws(char *str, int *error)
{
	size_t	i;
	size_t	wlen;

	i = 0;
	wlen = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			break ;
	}
	if (i == wlen)
	{
		(*error)++;
		return (1);
	}
	return (0);
}
