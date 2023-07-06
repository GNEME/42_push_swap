/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <ggneme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:00:07 by ggneme            #+#    #+#             */
/*   Updated: 2023/05/28 11:39:18 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_len(t_list *list)
{
	int		len;
	t_list	*p;

	len = 0;
	p = list;
	if (!list)
		return (len);
	len ++;
	while (p->next)
	{
		p = p->next;
		len ++;
	}
	return (len);
}

static void	get_max_and_pa_normi(t_list **list,
		t_list **head_a, int *nbrnbr, int len_b)
{
	int	half;
	int	nbr;

	nbr = *nbrnbr;
	if (len_b % 2 == 1)
		half = (len_b + 1) / 2;
	else
		half = len_b / 2;
	if (nbr <= half)
		while (--nbr)
			ra(list, 0, 1);
	else if (nbr <= len_b)
	{
		nbr = len_b - nbr + 2;
		while (--nbr)
			rra(list, 0, 1);
	}
	pa(head_a, list, 1, 1);
}

void	get_max_and_pa(t_list **list, t_list **head_a, int *len_a, int *len_b)
{
	int		max_value;
	int		nbr;
	int		i;
	t_list	*p;

	p = *list;
	if (!p)
		return ;
	max_value = p->content;
	nbr = 1;
	i = 1;
	p = p->next;
	while (p)
	{
		if (max_value < p->content)
		{
			max_value = p->content;
			nbr = i + 1;
		}
		i ++;
		p = p->next;
	}
	get_max_and_pa_normi(list, head_a, &nbr, *len_b);
	*len_a = *len_a + 1;
	*len_b = *len_b - 1;
}

static void	arrange_a_normi(t_list **a)
{
	t_list	*tmp_last;

	tmp_last = get_last(*a);
	if ((*a)->content > tmp_last->content)
	{
		if ((*a)->next->content > (*a)->content)
			rra(a, 1, 1);
		else if ((*a)->next->content < tmp_last->content)
			ra(a, 1, 1);
		else
		{
			ra(a, 1, 1);
			sa(a, 1, 1);
		}
	}
	else
	{
		if ((*a)->next->content > tmp_last->content)
		{
			sa(a, 1, 1);
			ra(a, 1, 1);
		}
		else if ((*a)->next->content < (*a)->content)
			sa(a, 1, 1);
	}
}

void	arrange_a(t_list **a, t_list **b, int *len_a, int *len_b)
{
	if (*len_a == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, 1, 1);
	}
	else
		arrange_a_normi(a);
	if (!*b)
		return ;
	if ((*a)->pos + 1 < (*b)->pos)
	{
		while (*len_a)
		{
			pa(b, a, 0, 1);
			*len_a = *len_a - 1;
			*len_b = *len_b + 1;
		}
	}
	else if ((*a)->pos + 1 == (*b)->pos)
	{
		pa(a, b, 1, 1);
		sa(a, 1, 1);
		*len_a = *len_a + 1;
		*len_b = *len_b - 1;
	}
}
