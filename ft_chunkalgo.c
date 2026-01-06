/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunkalgo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:52:59 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 11:09:32 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushto_a(t_stack **stack_b, t_stack **stack_a)
{
	int	i;
	int	current_size;

	while (*stack_b)
	{
		current_size = ft_sizenode(*stack_b);
		i = indexpos(*stack_b, current_size);
		if (i <= current_size / 2)
		{
			while ((*stack_b)->index != current_size)
				ft_rb(stack_b);
			ft_pa(stack_b, stack_a);
		}
		else
		{
			while ((*stack_b)->index != current_size)
				ft_rrb(stack_b);
			ft_pa(stack_b, stack_a);
		}
	}
}

void	ft_pushto_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	range;
	int	i;

	i = 0;
	if (size <= 101 && size > 50)
		range = 10;
	else
		range = 28;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i + range)
		{
			ft_pb(stack_a, stack_b);
			if ((*stack_b)->index < i)
				ft_rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index > i + range)
			ft_ra(stack_a);
	}
}

void	ft_sortmax(t_stack **stack_a, int size)
{
	t_stack	*stack_b;

	stack_b = NULL;
	ft_pushto_b(stack_a, &stack_b, size);
	ft_pushto_a(&stack_b, stack_a);
}
