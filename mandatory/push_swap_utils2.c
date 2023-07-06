/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <ggneme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:53:04 by ggneme            #+#    #+#             */
/*   Updated: 2023/06/07 12:17:25 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	chunks_init(int *chunk_size, int *middle, int *end, int len_a)
{
	*chunk_size = 1;
	while (*chunk_size < len_a / 3)
		*chunk_size = 3 * *chunk_size + 1;
	if (*chunk_size > 1 && len_a > 200)
		*chunk_size /= 6;
	else if (*chunk_size > 1)
		*chunk_size /= 2;
	else
		*chunk_size = 2;
	*end = *chunk_size;
	if (*chunk_size % 2 == 0)
		*middle = *chunk_size / 2;
	else
		*middle = (*chunk_size + 1) / 2;
	return (0);
}

static int	sort_chunks_normi(t_list **a, t_list **b, int end, int middle)
{
	int	len_b;

	if ((*a)->pos < end)
	{
		pa(b, a, 0, 1);
		len_b = get_len(*b);
		if ((*b)->pos < middle)
			if (len_b > 1)
				if ((*b)->content < (*b)->next->content)
					ra(b, 0, 1);
		return (1);
	}
	return (0);
}

void	sort_chunks(t_list **a, t_list **b, int *len_a, int *len_b)
{
	int	chunk_size;
	int	start;
	int	end;
	int	middle;
	int	i;

	start = 0;
	i = chunks_init(&chunk_size, &middle, &end, *len_a);
	while (*len_a > 3)
	{
		while (*a && i < end && *len_a > 3)
		{
			if (sort_chunks_normi(a, b, end, middle))
			{
				*len_a -= 1;
				*len_b += 1;
				i ++;
			}
			else
				find_and_pb(a, *len_a, end);
		}
		start += chunk_size;
		middle += chunk_size;
		end += chunk_size;
	}
}
