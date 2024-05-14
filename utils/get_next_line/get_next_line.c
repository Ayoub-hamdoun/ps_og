/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayhamdou <ayhamdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:31:33 by ayhamdou          #+#    #+#             */
/*   Updated: 2024/05/04 16:07:56 by ayhamdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../push_swap.h"

int	check_newline(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*extract_line(char *str, int read)
{
	int		j;
	int		count;
	char	*res;

	if (!str || read == -1)
		return (NULL);
	j = check_newline(str);
	if (j == -1)
		return (ft_strdup(str));
	count = 0;
	res = (char *)malloc((j + 2) * sizeof(char));
	if (!res)
		return (ft_error(str));
	while (count < j)
	{
		res[count] = str[count];
		count++;
	}
	res[count] = '\n';
	res[count + 1] = '\0';
	return (res);
}

char	*edit_original_array(char *str, char *ourline)
{
	int			count;
	int			len;
	int			nlp;
	char		*newarray;

	if (!str)
		return (NULL);
	count = 0;
	nlp = check_newline(str);
	len = ft_strlen(str);
	if (nlp == -1 || len == nlp + 1)
		return (free(str), NULL);
	newarray = (char *)malloc((len - nlp) * sizeof(char));
	if (!newarray)
	{
		free(str);
		return (ft_error(ourline));
	}
	while (count < len - nlp)
	{
		newarray[count] = str[nlp + 1 + count];
		count++;
	}
	str[count] = '\0';
	return (free(str), newarray);
}

char	*get_next_line(int fd)
{
	static char	*arr;
	char		*tmp;
	char		*ourline;
	int			char_read;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE == SIZE_T_MAX)
		return (ft_error(arr));
	while (check_newline(arr) == -1)
	{
		tmp = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (!tmp)
			return (ft_error(arr));
		char_read = read(fd, tmp, BUFFER_SIZE);
		if (char_read < 1)
		{
			free(tmp);
			break ;
		}
		tmp[char_read] = '\0';
		arr = ft_strjoin(arr, tmp);
		free(tmp);
	}
	ourline = extract_line(arr, char_read);
	arr = edit_original_array(arr, ourline);
	return (ourline);
}
