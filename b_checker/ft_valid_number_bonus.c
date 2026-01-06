/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_number_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:56:44 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:13:35 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
