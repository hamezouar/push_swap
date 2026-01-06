/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:45:41 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 11:09:08 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_helper(t_stack **head, int a, int b, int c)
{
	if (b > a && b > c)
	{
		if (a > c)
			ft_rra(head);
		else
		{
			ft_rra(head);
			ft_sa(head);
		}
	}
	else if (c > a && c > b && b > a)
		return ;
	else
		ft_sa(head);
}

void	ft_swap_three(t_stack **head)
{
	int	a;
	int	b;
	int	c;

	if (!head || !*head)
		return ;
	a = (*head)->index;
	b = (*head)->next->index;
	c = (*head)->next->next->index;
	if (a > b && a == c)
	{
		ft_sa(head);
		return ;
	}
	if (a > b && a > c)
	{
		ft_ra(head);
		if ((*head)->index > (*head)->next->index)
			ft_sa(head);
	}
	else
		ft_helper(head, a, b, c);
}
