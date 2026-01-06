/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_sa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:10:50 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 11:11:05 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **head)
{
	t_stack	*temp;
	int		number;

	temp = *head;
	if (!head)
		return ;
	if ((*head)->next != *head)
	{
		number = temp->next->value;
		temp->next->value = temp->value;
		temp->value = number;
		number = temp->next->index;
		temp->next->index = temp->index;
		temp->index = number;
		write(1, "sa\n", 3);
		return ;
	}
	return ;
}
