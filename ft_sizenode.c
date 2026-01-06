/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizenode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:23:24 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/02 15:14:53 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sizenode(t_stack *head)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = head;
	if (!head)
		return (0);
	while (temp->next != head)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
