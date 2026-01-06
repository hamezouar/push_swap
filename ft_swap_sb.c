/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_sb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:02:00 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 11:11:14 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack **head)
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
		write(1, "sb\n", 3);
		return ;
	}
	return ;
}
