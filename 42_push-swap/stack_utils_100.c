/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:58:01 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/11 21:40:45 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_100(t_stack **a, t_stack **b)
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