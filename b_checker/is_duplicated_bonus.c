/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicated_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:48:47 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:14:40 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_duplicate(t_stack *head)
{
	t_stack	*temp;
	t_stack	*count;

	temp = head;
	while (temp->next != head)
	{
		count = temp->next;
		while (count != head)
		{
			if ((temp->value == count->value))
				return (1);
			count = count->next;
		}
		temp = temp->next;
	}
	return (0);
}

t_stack	*is_duplicated(t_stack *head)
{
	if (!head)
		return (NULL);
	if (ft_duplicate(head))
	{
		write(2, "Error\n", 6);
		freelist(head);
		return (NULL);
	}
	return (head);
}
