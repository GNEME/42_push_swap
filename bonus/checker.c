/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:38:39 by ggneme            #+#    #+#             */
/*   Updated: 2023/05/05 23:39:19 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_cmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i ++;
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	return (0);
}

static int	stack_issorted(t_list	*list)
{
	t_list	*p;
	int		tmp;

	if (!list)
		return (0);
	tmp = list->content;
	p = list->next;
	while (p)
	{
		if (tmp > p->content)
			return (0);
		tmp = p->content;
		p = p->next;
	}
	return (1);
}

static void	ft_execute(char *str, t_list **head_a, t_list **head_b)
{
	if (ft_cmp(str, "pa\n"))
		pa(head_a, head_b, 1, 0);
	else if (ft_cmp(str, "pb\n"))
		pa(head_b, head_a, 0, 0);
	else if (ft_cmp(str, "ra\n"))
		ra(head_a, 1, 0);
	else if (ft_cmp(str, "rb\n"))
		ra(head_b, 0, 0);
	else if (ft_cmp(str, "rr\n"))
		rr(head_a, head_b, 0);
	else if (ft_cmp(str, "rra\n"))
		rra(head_a, 1, 0);
	else if (ft_cmp(str, "rrb\n"))
		rra(head_b, 0, 0);
	else if (ft_cmp(str, "rrr\n"))
		rrr(head_a, head_b, 0);
	else
	{
		free(str);
		write(2, "Error\n", 6);
		ft_lstclear(head_a);
		ft_lstclear(head_b);
		exit(1);
	}
}

static void	normi(char *str, t_list **head_a, t_list **head_b)
{
	if (ft_cmp(str, "sa\n"))
		sa(head_a, 1, 0);
	else if (ft_cmp(str, "sb\n"))
		sa(head_b, 0, 0);
	else if (ft_cmp(str, "ss\n"))
		ss(head_a, head_b, 0);
	else
		ft_execute(str, head_a, head_b);
}

int	main(int ac, char **argv)
{
	char	*line;
	t_list	*head_a;
	t_list	*head_b;

	(void)ac;
	head_b = 0;
	head_a = get_stack_a(argv);
	if (!head_a)
		return (0);
	line = get_next_line(0);
	while (line)
	{
		normi(line, &head_a, &head_b);
		free(line);
		line = get_next_line(0);
	}
	if (stack_issorted(head_a) && !head_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	return (0);
}
