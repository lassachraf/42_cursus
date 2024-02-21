/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:06:25 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/21 17:17:43 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		temp;
	int		nb;
	int		i;

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
		tmp = tmp->next;
	}
	min_util(a, temp);
	pb(b, a);
}

void	min_util(t_stack **a, int temp)
{
	printf("tmp +> %d\n", temp);
	if (temp != 0)
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
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	nb;

	nb = stack_len(*a);
	if (nb == 5)
		push_min(a, b);
	push_min(a, b);
	print_stack(*a, 'A');
	sort_three(a);
	if (nb == 5)
		pa(a, b);
	pa(a, b);
}
