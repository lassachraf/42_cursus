/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:33:36 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/15 10:13:29 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack **a, char **av, int ac)
{
	char	**s;
	int		i;
	int		j;

	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		s = ft_split(av[i], ' ');
		while (s[j])
		{
			append_node(a, ft_atoi(s[j]));
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
	check_doubles(*a);
}

void	sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		sa(a);
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value
		&& (*a)->next->value < (*a)->next->next->value)
		ra(a);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		rra(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push_min(a, b);
	push_max(a, b);
	sort_three(a);
	pa(a, b);
	ra(a);
	pa(a, b);
}

void	free_stack(t_stack **a, t_stack **b)
{
	t_stack	*c;

	while (*a)
	{
		c = (*a)->next;
		free(*a);
		*a = c;
	}
	while (*b)
	{
		c = (*b)->next;
		free(*b);
		*b = c;
	}
}
