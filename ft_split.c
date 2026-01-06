/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 13:43:12 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/02 15:16:55 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_count_word(char const *str, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

int	ft_start(char const *str, size_t i, char c)
{
	while (str[i] && str[i] == c)
		i++;
	return (i);
}

int	ft_end(char const *str, size_t i, char c)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**free_all(char **ptr, int i)
{
	int	x;

	x = i - 1;
	while (x >= 0)
	{
		free(ptr[x]);
		x--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	count_word;
	size_t	i;
	size_t	start;
	size_t	len;
	char	**ptr;

	if (!s)
		return (NULL);
	count_word = ft_count_word(s, c);
	ptr = ft_calloc(count_word + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	len = 0;
	while (i < count_word)
	{
		start = ft_start(s, len, c);
		len = ft_end(s, start, c);
		ptr[i] = ft_substr(s, start, len - start);
		if (!ptr[i])
			return (free_all(ptr, i));
		i++;
	}
	ptr[i] = (NULL);
	return (ptr);
}
