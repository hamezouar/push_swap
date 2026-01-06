/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:21:28 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 11:18:27 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//******************* */ is empty started ************************//

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] != ' ')
		return (1);
	return (0);
}
//******************* */ is empty ended ************************//

char	*is_fail(char *temp)
{
	write(2, "Error\n", 6);
	free(temp);
	return (NULL);
}
//******************* */ is fail ended ************************//

t_stack	*ft_parsing(char *str)
{
	char	**ptr;
	int		i;
	long	data;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 0;
	ptr = ft_split(str, ' ');
	if (!ptr)
		return (NULL);
	if (ft_valid_number(ptr))
	{
		while (ptr[i])
		{
			data = ft_atoi(ptr[i]);
			stack_a = ft_addback(stack_a, data);
			i++;
		}
	}
	freeall(ptr);
	return (stack_a);
}

char	*joinstr(char **argv, int argc)
{
	char	*str;
	char	*temp;
	int		j;

	(void)argc;
	str = ft_strdup("");
	j = 1;
	while (argv[j])
	{
		temp = str;
		if (!is_empty(argv[j]))
			return (is_fail(temp));
		str = ft_strjoin(str, argv[j]);
		free(temp);
		if (!str)
			return (NULL);
		j++;
	}
	return (str);
}
