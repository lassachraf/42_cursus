/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/21 17:09:45 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_arr(t_stack *a)
{
	t_stack	*tmp;
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * stack_len(a));
	tmp = a;
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	return (arr);
}

int	get_chunk(t_stack *a)
{
	int	nb;

	nb = stack_len(a);
	if (nb < 20)
		return (5);
	else if (nb < 100)
		return (10);
	else
		return (30);
}

void	get_it_top(t_stack **a, t_stack **b, int nb)
{
	t_stack	*tmp;
	int		index;

	tmp = *a;
	index = get_nb_index(tmp, nb);
	if (index >= (stack_len(tmp) / 2))
	{
		while ((*a)->value != nb)
		{
			rra(a);
			index++;
		}
	}
	else
	{
		while (index)
		{
			ra(a);
			index--;
		}
	}
	pb(b, a);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*arr;
	int		mid;

	tmp = *a;
	arr = sort_int_tab(copy_arr(*a), stack_len(*a));
	mid = stack_len(*a) / 2;
	(void)b;
	// if (mid > (stack_len(*a) / 2))
	// {
	// 	while (mid--)
	// 		ra(a);
	// }
	// else
	// {
	// 	while (mid <= stack_len(*a))
	// 	{
	// 		ra(a);
	// 		mid++;
	// 	}
	// }
	// free(tmp);
	// sort_three(a);
	// while ((*b)->next)
	// 	pa(a, b);
	// pa(a, b);
	// pa(a, b);
	// print_stack(*a, 'A');
	// print_stack(*b, 'B');
}
