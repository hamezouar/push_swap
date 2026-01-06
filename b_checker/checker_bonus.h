/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:16:19 by hamezoua          #+#    #+#             */
/*   Updated: 2026/01/05 15:27:21 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

char				*get_next_line(int fd);
char				*joinstr(char **argv, int argc);
t_stack				*ft_parsing(char *str);
t_stack				*is_duplicated(t_stack *head);
void				freelist(t_stack *head);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
t_stack				*ft_addback(t_stack *head, int data);
long				ft_atoi(char *str);
int					ft_valid_number(char **str);
char				**ft_split(char const *s, char c);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strlen(char const *str);
void				ft_pa(t_stack **src, t_stack **dst);
void				ft_pb(t_stack **src, t_stack **dst);
void				ft_ra(t_stack **head);
void				ft_rb(t_stack **head);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);
void				ft_rra(t_stack **head);
void				ft_rrb(t_stack **head);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);
void				ft_sa(t_stack **head);
void				ft_sb(t_stack **head);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);
char				*ft_strjoin_line(char const *s1, char const *s2);
#endif