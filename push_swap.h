/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:04:46 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 11:07:45 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
int					ft_strlen(char const *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
int					ft_valid_number(char **str);
long				ft_atoi(char *str);
void				freeall(char **str);
t_stack				*ft_sort_index(t_stack *head);
t_stack				*ft_addback(t_stack *head, int data);
t_stack				*ft_is_duplicated(t_stack *head);
void				freelist(t_stack *head);
void				ft_pa(t_stack **src, t_stack **dst);
void				ft_pb(t_stack **src, t_stack **dst);
void				ft_ra(t_stack **head);
void				ft_rra(t_stack **head);
void				ft_sa(t_stack **head);
void				ft_swap_five(t_stack **head, int argc);
void				ft_swap_three(t_stack **head);
void				ft_rb(t_stack **head);
void				ft_rrb(t_stack **head);
void				ft_sortmax(t_stack **stack_a, int size);
int					ft_sizenode(t_stack *head);
int					indexpos(t_stack *head, int number);
t_stack				*ft_parsing(char *str);
char				*joinstr(char **argv, int argc);
t_stack				*ft_is_duplicated(t_stack *head);

#endif