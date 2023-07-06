/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:53:37 by ggneme            #+#    #+#             */
/*   Updated: 2023/05/01 19:07:31 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **a, t_list **b, int is_a, int can_talk)
{
	t_list	*tmp;

	tmp = *b;
	if (!tmp)
		return ;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (can_talk)
	{
		if (is_a)
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
	}
}

void	ra(t_list **list, int is_a, int can_talk)
{
	t_list	*tmp;
	t_list	*p;
	int		nbr;

	p = *list;
	nbr = 1;
	if (p)
		while (p->next && ++nbr < 2)
			p = p->next;
	if (!p || nbr < 2)
		return ;
	tmp = *list;
	*list = tmp->next;
	tmp->next = 0;
	p = *list;
	while (p->next)
		p = p->next;
	p->next = tmp;
	if (can_talk && is_a)
		write(1, "ra\n", 3);
	else if (can_talk && !is_a)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int can_talk)
{
	ra(a, 1, 0);
	ra(b, 0, 0);
	if (can_talk)
		write(1, "rr\n", 3);
}

void	rra(t_list **list, int is_a, int can_talk)
{
	t_list	*tmp;
	t_list	*p;
	int		nbr;

	p = *list;
	nbr = 1;
	if (p)
		while (p->next && ++nbr < 2)
			p = p->next;
	if (!p || nbr < 2)
		return ;
	while (p->next->next)
		p = p->next;
	tmp = p->next;
	p->next = 0;
	tmp->next = *list;
	*list = tmp;
	if (can_talk && is_a)
		write(1, "rra\n", 4);
	else if (can_talk && !is_a)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int can_talk)
{
	rra(a, 1, 0);
	rra(b, 0, 0);
	if (can_talk)
		write(1, "rrr\n", 4);
}
