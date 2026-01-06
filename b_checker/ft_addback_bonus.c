/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addback_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:53:32 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:07:25 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_newnode(int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

t_stack	*ft_addback(t_stack *head, int data)
{
	t_stack	*new;
	t_stack	*tail;

	new = ft_newnode(data);
	if (!new)
		return (head);
	if (!head)
		return (new);
	tail = head->prev;
	tail->next = new;
	new->next = head;
	new->prev = tail;
	head->prev = new;
	return (head);
}
