/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelist_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:32:43 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:06:50 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	freelist(t_stack *head)
{
	t_stack	*temp;
	t_stack	*current;

	temp = head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	while (temp != NULL)
	{
		current = temp;
		temp = temp->next;
		free(current);
	}
}
