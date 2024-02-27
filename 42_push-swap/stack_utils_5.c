/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:06:25 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/27 13:22:49 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **a, t_stack **b, int n)
{
	t_stack	*tmp;
	int		temp;
	int		nb;
	int		i;

	tmp = *a;
	i = 1;
	nb = tmp->value;
	temp = 0;
	while (tmp)
	{
		if (nb > tmp->value)
		{
			nb = tmp->value;
			temp = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (n)
		min_util_four(a, --temp);
	else
		min_util_five(a, temp);
	pb(b, a);
}

void	min_util_four(t_stack **a, int temp)
{
	if (temp != 0)
	{
		if (temp == 1)
		{
			ra(a);
		}
		else if (temp == 2)
		{
			ra(a);
			ra(a);
		}
		else if (temp == 3)
			rra(a);
	}
}

void	min_util_five(t_stack **a, int temp)
{
	if (temp != 0)
	{
		if (temp == 2)
			ra(a);
		else if (temp == 3)
		{
			rra(a);
			rra(a);
		}
		else if (temp == 4)
			rra(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	nb;

	nb = stack_len(*a);
	if (nb == 4)
	{
		push_min(a, b, 1);
		sort_three(a);
		pa(a, b);
	}
	if (nb == 5)
	{
		push_min(a, b, 0);
		// print_stack(*a, 'A');
		// print_stack(*b, 'B');
		push_min(a, b, 0);
		// print_stack(*a, 'A');
		// print_stack(*b, 'B');
		sort_three(a);
		// print_stack(*a, 'A');
		pa(a, b);
		pa(a, b);
	}
}
