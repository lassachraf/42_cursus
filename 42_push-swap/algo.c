/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:37:13 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/28 00:14:41 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_range(t_stack **a)
{
	int	range;

	range = stack_len(*a);
	if (6 <= range && range <= 16)
		return (3);
	else if (range <= 100)
		return (13);
	else if (range <= 500)
		return (30);
	else
		return (45);
}

void	sort(t_stack **a, t_stack **b, int num)
{
	int	*arr;
	int	nb;
	int	range;
	int	i;

	arr = sort_int_tab(copy_arr(*a), stack_len(*a));
	range = get_range(a);
	i = 0;
	while (*a)
	{
		nb = (*a)->value;
		if (range + i >= num)
			range = num - 1 - i;
		else if (nb > arr[i] && nb <= arr[range + i])
		{
			pb(b, a);
			if (stack_len(*b) >= 2 && (*b)->value < (*b)->next->value)
				sb(b);
			i++;
		}
		else if (nb <= arr[i])
		{
			pb(b, a);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
	free(arr);
	while (*b)
		push_max(a, b, num);
}

void	push_max(t_stack **a, t_stack **b, int n)
{
	t_stack	*tmp;
	int		temp;
	int		nb;
	int		i;

	(void)n;
	tmp = *b;
	i = 0;
	nb = tmp->value;
	temp = 0;
	while (tmp)
	{
		if (nb < tmp->value)
		{
			nb = tmp->value;
			temp = i;
		}
		i++;
		tmp = tmp->next;
	}
	max_util(b, temp, stack_len(*b), nb);
	pa(a, b);
}

void	max_util(t_stack **b, int temp, int n, int nb)
{
	if (temp != 0)
	{
		if (temp <= (n / 2))
		{
			while ((*b)->value != nb)
				rb(b);
		}
		else
		{
			while ((*b)->value != nb)
				rrb(b);
		}
	}
}
