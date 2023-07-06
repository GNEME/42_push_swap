/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:33:40 by ggneme            #+#    #+#             */
/*   Updated: 2023/05/02 19:46:52 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	normi(char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign = -1 * *sign;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
		*i = *i + 1;
}

int	my_atoi(char *str, int *error, int *start)
{
	long int	value;
	int			i;
	int			sign;

	value = 0;
	i = *start;
	sign = 1;
	*error = 0;
	while (str[i] && str[i] == ' ')
		i++;
	normi(str, &i, &sign);
	if (!('0' <= str[i] && str[i] <= '9'))
		*error = 1;
	while (str[i] && ('0' <= str[i] && str[i] <= '9'))
		value = value * 10 + (str[i++] - '0');
	if (str[i] && str[i] != ' ')
		*error = 1;
	while (str[i] && str[i] == ' ')
		i++;
	*start = i;
	value = sign * value;
	if (value <= -2147483649 || value >= 2147483648 || i == 0)
		*error = 1;
	return (value);
}

static void	get_stack_a_normi1(t_list **a, t_list **tmp, int *error, int value)
{
	if (already_exist(*a, value))
		*error = 1;
	else
	{
		(*tmp)->next = ft_lstnew(value);
		if (!(*tmp)->next)
			*error = 1;
		*tmp = (*tmp)->next;
	}
}

static int	get_stack_a_normi(t_list **a, char **p, int *first_iter, int *value)
{
	int		start;
	int		error;
	t_list	*tmp;

	error = 0;
	start = 0;
	while ((*p)[start] && error == 0)
	{
		*value = my_atoi(*p, &error, &start);
		if (error)
			break ;
		if (*first_iter)
		{
			tmp = ft_lstnew(*value);
			if (!tmp)
				error = 1;
			*a = tmp;
			*first_iter = 0;
		}
		else
			get_stack_a_normi1(a, &tmp, &error, *value);
	}
	if (!start)
		return (1);
	return (error);
}

t_list	*get_stack_a(char **argv)
{
	t_list	*a;
	int		error;
	char	**p;
	int		first_iter;
	int		value;

	p = argv;
	p++;
	error = 0;
	a = 0;
	first_iter = 1;
	while (*p)
	{
		error = get_stack_a_normi(&a, p, &first_iter, &value);
		if (error)
			break ;
		p++;
	}
	if (error)
	{
		ft_lstclear(&a);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (a);
}
