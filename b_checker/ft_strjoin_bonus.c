/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:58:32 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 10:37:26 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*join_strings(char *dest, const char *s)
{
	int	i;
	int	j;

	j = 0;
	while (dest[j] != '\0')
		j++;
	i = 0;
	while (s[i] != '\0')
	{
		dest[j + i] = s[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(s1_len + s2_len + 3);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	join_strings(ptr, s1);
	ptr[s1_len] = ' ';
	ptr[s1_len + 1] = '\0';
	join_strings(ptr, s2);
	s1_len = ft_strlen(ptr);
	ptr[s1_len] = ' ';
	ptr[s1_len + 1] = '\0';
	return (ptr);
}
