/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:16:36 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/06 00:12:35 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	helperfun(t_stack **stack_a, int size)
{
	if (size <= 2)
		ft_swap_three(stack_a);
	if (size == 4 || size == 3)
		ft_swap_five(stack_a, size);
	if (size >= 5)
		ft_sortmax(stack_a, size);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	*str;
	int		size;

	if (argc < 2)
		return (0);
	str = joinstr(argv, argc);
	if (!str)
		return (0);
	stack_a = ft_parsing(str);
	stack_a = ft_is_duplicated(stack_a);
	if (!stack_a)
	{
		free(str);
		return (0);
	}
	ft_sort_index(stack_a);
	size = ft_sizenode(stack_a);
	helperfun(&stack_a, size);
	if (stack_a)
		freelist(stack_a);
	free(str);
}
