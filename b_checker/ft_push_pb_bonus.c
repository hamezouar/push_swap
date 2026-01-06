/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_pb_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:54:06 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:08:51 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}
