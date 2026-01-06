/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:59:41 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:15:10 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#define BUFFER_SIZE 4

static char	*fill_stash(int fd, char *stash, char *buf)
{
	ssize_t	bfs;
	size_t	i;
	char	*temp;

	bfs = read(fd, buf, BUFFER_SIZE);
	while (bfs > 0)
	{
		buf[bfs] = '\0';
		temp = stash;
		stash = ft_strjoin_line(temp, buf);
		free(temp);
		i = 0;
		while (stash[i])
		{
			if (stash[i] == '\n')
			{
				free(buf);
				return (stash);
			}
			i++;
		}
		bfs = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (stash);
}

static char	*extractline(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = fill_stash(fd, stash, buf);
	temp = stash;
	if (!stash || stash[0] == '\0')
	{
		free(temp);
		return (NULL);
	}
	line = extractline(stash);
	stash = ft_strdup(stash + ft_strlen(line));
	free(temp);
	if (!stash)
		return (NULL);
	return (line);
}
