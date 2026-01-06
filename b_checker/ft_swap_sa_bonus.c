/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_sa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:51:03 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:12:39 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		return ;
	}
	return ;
}
