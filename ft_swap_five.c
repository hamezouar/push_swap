/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:08:58 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 14:44:31 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexpos(t_stack *head, int number)
{
	int		i;
	t_stack	*temp;

	temp = head;
	i = 0;
	while (head->index != number)
	{
		head = head->next;
		i++;
		if (head == temp)
			return (-1);
	}
	return (i);
}

void	swap_five(t_stack **head, t_stack **stack_b, int i)
{
	if (i <= 2)
	{
		while ((*head)->index != 0)
			ft_ra(head);
	}
	else
	{
		while ((*head)->index != 0)
			ft_rra(head);
	}
	ft_pb(head, stack_b);
	i = indexpos(*head, 1);
	if (i < 2)
	{
		while ((*head)->index != 1)
			ft_ra(head);
	}
	else
	{
		while ((*head)->index != 1)
			ft_rra(head);
	}
	ft_pb(head, stack_b);
}

void	ft_swapfour(t_stack **head, t_stack **stack_b)
{
	int	i;

	i = indexpos(*head, 0);
	if (i <= 2)
	{
		while ((*head)->index != 0)
			ft_ra(head);
	}
	else
	{
		while ((*head)->index != 0)
			ft_rra(head);
	}
	ft_pb(head, stack_b);
	ft_swap_three(head);
	ft_pa(stack_b, head);
}

void	ft_swap_five(t_stack **head, int size)
{
	int		x;
	t_stack	*stack_b;

	x = indexpos(*head, 0);
	if (!head || !*head)
		return ;
	stack_b = NULL;
	if (size == 3)
		ft_swapfour(head, &stack_b);
	else
	{
		swap_five(head, &stack_b, x);
		ft_swap_three(head);
		ft_pa(&stack_b, head);
		ft_pa(&stack_b, head);
	}
}
