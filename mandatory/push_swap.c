/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <ggneme@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:07:06 by ggneme            #+#    #+#             */
/*   Updated: 2023/05/28 12:00:52 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_last(t_list *list)
{
	t_list	*p;

	p = list;
	if (!list)
		return (list);
	while (p->next)
		p = p->next;
	return (p);
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

static void	get_pos(t_list **list)
{
	t_list	*p;
	t_list	*pp;
	int		nbr;

	p = *list;
	while (p)
	{
		nbr = 0;
		pp = *list;
		while (pp)
		{
			if (p->content > pp->content)
				nbr ++;
			pp = pp->next;
		}
		p->pos = nbr;
		p = p->next;
	}
}

static void	ft_init(t_list **head_a, int *len_a, int *half, char **argv)
{
	*head_a = get_stack_a(argv);
	*len_a = get_len(*head_a);
	if (*len_a % 2 == 1)
		*half = (*len_a + 1) / 2;
	else
		*half = *len_a / 2;
}

int	main(int ac, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		len_a;
	int		len_b;
	int		half;

	(void)ac;
	head_b = 0;
	len_b = 0;
	ft_init(&head_a, &len_a, &half, argv);
	if (!head_a || stack_issorted(head_a))
	{
		ft_lstclear(&head_a);
		return (0);
	}
	get_pos(&head_a);
	sort_chunks(&head_a, &head_b, &len_a, &len_b);
	arrange_a(&head_a, &head_b, &len_a, &len_b);
	while (len_b != 0)
		get_max_and_pa(&head_b, &head_a, &len_a, &len_b);
	ft_lstclear(&head_a);
	return (0);
}
