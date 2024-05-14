/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:24:23 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/04/24 15:54:32 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(const char *str, char delimiter)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] == delimiter)
			i++;
		if (str[i] && str[i] != delimiter)
			c++;
		while (str[i] && str[i] != delimiter)
			i++;
	}
	return (c);
}

static char	**free_tab(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	*ret_sub(const char *s1, int *index, char c)
{
	char	*copy;
	size_t	word_len;
	int		i;

	word_len = 0;
	while (s1[*index] == c)
		(*index)++;
	i = *index;
	while (s1[i] && s1[i] != c)
	{
		word_len++;
		i++;
	}
	copy = malloc(sizeof(char) * (word_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[*index] && s1[*index] != c)
		copy[i++] = s1[(*index)++];
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		index;
	int		wc;
	int		i;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = count_words(s, c);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
		arr[i] = ret_sub(s, &index, c);
		if (!arr[i])
			return (free_tab(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
