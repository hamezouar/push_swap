/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:01:58 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/01 11:00:24 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long	ft_atoi(char *str)
{
	long	i;
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		if (((res * sign) > 2147483647) || ((res * sign) < -2147483648))
			return (2147483649);
		i++;
	}
	return (res * sign);
}
