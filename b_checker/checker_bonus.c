/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:56:02 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:05:24 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	checkinst(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa(stack_a);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(stack_a);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_pb(stack_a, stack_b);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb(stack_b);
	else
		return (0);
	return (1);
}

int	is_sorted(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		return (1);
	temp = head;
	while (temp->next != head)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	readline(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!(checkinst(line, stack_a, stack_b)))
		{
			free(line);
			line = get_next_line(0);
			while (line != NULL)
			{
				free(line);
				line = get_next_line(0);
			}
			freelist(*stack_a);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	stack_a = NULL;
	stack_b = NULL;
	(void)argc;
	str = joinstr(argv, argc);
	if (!str)
		return (0);
	stack_a = ft_parsing(str);
	stack_a = is_duplicated(stack_a);
	if (!stack_a)
	{
		free(str);
		return (0);
	}
	free(str);
	readline(&stack_a, &stack_b);
	if ((is_sorted(stack_a)) == 1 && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "kO\n", 3);
	freelist(stack_a);
}
