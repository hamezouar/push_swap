/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:31:45 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/01 12:07:03 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_intmax(long a)
{
	if ((a > INT_MAX) || (a < INT_MIN))
		return (0);
	return (1);
}

int	ft_valid_number(char **str)
{
	size_t	i;
	long	x;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			x = ft_atoi(str[i]);
			if (ft_intmax(x))
				i++;
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}
