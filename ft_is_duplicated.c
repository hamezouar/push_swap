/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_duplicated.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:11:32 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 14:32:18 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_not_duplicate(t_stack *head)
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
				return (0);
			count = count->next;
		}
		temp = temp->next;
	}
	return (1);
}

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

t_stack	*ft_is_sorted(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp->next != head)
	{
		if (temp->value > temp->next->value)
			return (head);
		temp = temp->next;
	}
	freelist(head);
	return (NULL);
}

t_stack	*ft_is_duplicated(t_stack *head)
{
	if (!head)
		return (NULL);
	if (has_not_duplicate(head))
		return (ft_is_sorted(head));
	write(2, "Error\n", 6);
	freelist(head);
	return (NULL);
}
