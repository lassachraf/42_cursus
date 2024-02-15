/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/15 15:56:04 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mid_value(t_stack *b)
{
	t_stack	*tmp;
	int		mid;
	int		i;
	int		nb;

	i = 0;
	tmp = b;
	mid = stack_len(b) / 2;
	while (i < mid)
		b = b->next;
	nb = b->value;
	b = tmp;
	return ()
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		mid;
	int		i;

	while ((*a)->next->next->next)
		pb(b, a);
	sort_three(a);
	mid = stack_len(b) / 2;
	tmp = *b;
	i = 0;
	while (i < mid)
	{
		if ((*b)->value < mid)
		i++;
	}
	// get the cheapest number that need the min instructions and push it, than sort it !
	// should be in a loop to do the same with all elements in stack b !
}
