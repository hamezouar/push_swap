/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:18:02 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 11:06:26 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_helperfunb(t_stack *to_push, t_stack **dst)
{
	to_push->prev = (*dst)->prev;
	to_push->next = (*dst);
	(*dst)->prev->next = to_push;
	(*dst)->prev = to_push;
	*dst = to_push;
}

void	ft_pb(t_stack **src, t_stack **dst)
{
	t_stack	*to_push;

	to_push = *src;
	if (!src || !*src)
		return ;
	if (to_push->next == to_push)
		*src = NULL;
	else
	{
		to_push->prev->next = to_push->next;
		to_push->next->prev = to_push->prev;
		*src = to_push->next;
	}
	if (!*dst)
	{
		*dst = to_push;
		(*dst)->next = *dst;
		(*dst)->prev = *dst;
	}
	else
		ft_helperfunb(to_push, dst);
	write(1, "pb\n", 3);
}
