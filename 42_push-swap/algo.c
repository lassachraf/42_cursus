/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/14 15:20:40 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	while ((*a)->next->next->next)
		pb(b, a);
	print_stack(*a, 'A');
	print_stack(*b, 'B');
	sort_three(a);
	
}
