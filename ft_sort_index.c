/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:01:47 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 23:35:03 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_node(t_stack *head)
{
	t_stack	*temp;
	size_t	x;

	if (!head)
		return (0);
	temp = head->next;
	x = 1;
	while (temp != head)
	{
		x++;
		temp = temp->next;
	}
	return (x);
}

void	ft_sort(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sorttab(int arr[], int x)
{
	int	i;

	i = 0;
	while (i < x - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			ft_sort(&arr[i], &arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int	*ft_add_data(t_stack *head)
{
	int		x;
	int		i;
	int		*arr;
	t_stack	*temp;

	x = count_node(head);
	arr = malloc(sizeof(int) * x);
	if (!arr)
		return (0);
	temp = head;
	i = 0;
	while (i < x)
	{
		arr[i] = temp->value;
		temp = temp->next;
		i++;
	}
	ft_sorttab(arr, x);
	return (arr);
}

t_stack	*ft_sort_index(t_stack *head)
{
	t_stack	*temp;
	int		*arr;
	int		i;
	int		count;
	int		j;

	count = count_node(head);
	i = 0;
	j = 0;
	if (!head)
		return (NULL);
	arr = ft_add_data(head);
	temp = head;
	while (j < count)
	{
		while (temp->value != arr[i])
			i++;
		temp->index = i;
		i = 0;
		temp = temp->next;
		j++;
	}
	free(arr);
	return (head);
}