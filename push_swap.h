/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <ggneme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:48:44 by ggneme            #+#    #+#             */
/*   Updated: 2023/05/28 12:08:08 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 42
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
int		my_atoi(char *str, int *error, int *start);
void	sa(t_list **list, int is_a, int can_talk);
void	ss(t_list **a, t_list **b, int can_talk);
void	pa(t_list **a, t_list **b, int is_a, int can_talk);
void	ra(t_list **list, int is_a, int can_talk);
void	rr(t_list **a, t_list **b, int can_talk);
void	rra(t_list **list, int is_a, int can_talk);
void	rrr(t_list **a, t_list **b, int can_talk);
int		already_exist(t_list *list, int value);
t_list	*get_stack_a(char **argv);
int		get_len(t_list *list);
void	get_max_and_pa(t_list **list, t_list **head_a, int *len_a, int *len_b);
void	arrange_a(t_list **a, t_list **b, int *len_a, int *len_b);
t_list	*get_last(t_list *list);
void	sort_chunks(t_list **a, t_list **b, int *len_a, int *len_b);
void	find_and_pb(t_list **a, int len_a, int end);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
#endif
