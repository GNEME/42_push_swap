/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:09:33 by ggneme            #+#    #+#             */
/*   Updated: 2023/05/02 20:59:32 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **list, int is_a, int can_talk)
{
	t_list	*head;
	t_list	*tmp;
	int		nbr;

	nbr = 1;
	head = *list;
	if (head)
		while (head->next && ++nbr < 2)
			head = head->next;
	if (!head || nbr < 2)
		return ;
	head = *list;
	tmp = head->next;
	head->next = tmp->next;
	tmp->next = head;
	*list = tmp;
	if (can_talk && is_a)
		write(1, "sa\n", 3);
	else if (can_talk && !is_a)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int can_talk)
{
	sa(a, 1, 0);
	sa(b, 0, 0);
	if (can_talk)
		write(1, "ss\n", 3);
}

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->content = content;
		list->next = 0;
	}
	return (list);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*p;

	if (!lst)
		return ;
	p = *lst;
	if (p)
	{
		while ((*lst)->next)
		{
			(*lst) = (*lst)->next;
			free(p);
			p = *lst;
		}
		free(p);
	}
	*lst = 0;
}

int	already_exist(t_list *list, int value)
{
	t_list	*p;

	p = list;
	if (!p)
		return (0);
	while (p->next)
	{
		if (p->content == value)
			return (1);
		p = p->next;
	}
	if (p->content == value)
		return (1);
	return (0);
}
