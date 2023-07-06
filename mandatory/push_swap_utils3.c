/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <ggneme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:10:31 by ggneme            #+#    #+#             */
/*   Updated: 2023/06/07 12:11:17 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	find_and_pb_init(int *half, int *nbr, int *nbr_tmp, int len_a)
{
	*nbr_tmp = 1;
	*nbr = 0;
	if (len_a % 2 == 0)
		*half = len_a / 2;
	else
		*half = (len_a + 1) / 2;
}

static int	find_and_pb_normi(int *nbr, int *nbr_tmp, int *tmp, int len_a)
{
	int	half;

	if (len_a % 2 == 0)
		half = len_a / 2;
	else
		half = (len_a + 1) / 2;
	if (!*nbr)
		return (1);
	if (*nbr_tmp <= half)
	{
		if (*nbr_tmp < *tmp)
		{
			*nbr = *nbr_tmp;
			*tmp = *nbr_tmp;
		}
	}
	else if (*nbr_tmp <= len_a)
	{
		if (len_a - *nbr_tmp + 2 < *tmp)
		{
			*nbr = *nbr_tmp;
			*tmp = len_a - *nbr_tmp + 2;
		}
	}
	return (0);
}

static void	find_and_pb_normi1(t_list **a, int len_a, int nbr, int half)
{
	if (len_a == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, 1, 1);
	}
	else if (nbr <= half)
		while (--nbr)
			ra(a, 1, 1);
	else if (nbr <= len_a)
	{
		nbr = len_a - nbr + 2;
		while (--nbr)
			rra(a, 1, 1);
	}
}

void	find_and_pb(t_list **a, int len_a, int end)
{
	int		nbr;
	int		nbr_tmp;
	int		tmp;
	int		half;
	t_list	*p;

	p = *a;
	find_and_pb_init(&half, &nbr, &nbr_tmp, len_a);
	while (p)
	{
		if (p->pos < end)
		{
			if (find_and_pb_normi(&nbr, &nbr_tmp, &tmp, len_a))
			{
				nbr = nbr_tmp;
				if (nbr_tmp <= half)
					tmp = nbr_tmp;
				else if (nbr_tmp <= len_a)
					tmp = len_a - nbr_tmp + 2;
			}
		}
		nbr_tmp ++;
		p = p->next;
	}
	find_and_pb_normi1(a, len_a, nbr, half);
}
