/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:06:25 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/09 14:32:26 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int temp;
	int	nb;
	int	i;

	tmp = *a;
	i = 1;
	nb = tmp->value;
	tmp = tmp->next;
	temp = 0;
	while (tmp)
	{
		if (nb > tmp->value)
		{
			nb = tmp->value;
			temp = i;
		}
		i++;
		tmp = (tmp)->next;
	}
	min_util(a, temp);
	pb(b, a);
}

void	push_max(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int temp;
	int	nb;
	int	i;

	tmp = *a;
	i = 1;
	nb = tmp->value;
	tmp = tmp->next;
	temp = 0;
	while (tmp)
	{
		if (nb < tmp->value)
		{
			nb = tmp->value;
			temp = i;
		}
		i++;
		tmp = (tmp)->next;
	}
	max_util(a, temp);
	pb(b, a);
}

void	min_util(t_stack **a, int temp)
{
	if (temp <= 2)
	{
		if (temp == 2)
			ra(a);
		ra(a);
	}
	else if (temp > 2)
	{
		if (temp == 4)
			rra(a);
		else
		{
			rra(a);
			rra(a);
		}
	}
}

void	max_util(t_stack **a, int temp)
{
	if (temp <= 1)
	{
		if (temp == 1)
			sa(a);
	}
	else if (temp > 1)
	{
		if (temp == 3)
			rra(a);
		else
		{
			rra(a);
			rra(a);	
		}
	}
}
