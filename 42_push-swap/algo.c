/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/26 15:08:47 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	indexing(t_stack *a, int *arr)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (i < stack_len(tmp))
	{
		while (tmp)
		{
			if (tmp->value == arr[i])
			{
                tmp->final_index = i;
				break;
			}
            tmp = tmp->next;
		}
		tmp = a;
		i++;
	}
	return (i);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*arr;
	int		mid_index;

	tmp = *a;
	arr = sort_int_tab(copy_arr(*a), stack_len(*a));
	mid_index = indexing(*a, arr);
	while (stack_len(*a) != (mid_index / 2))
	{
		if ((*a)->final_index < (mid_index / 2))
			pb(b, a);
		else
			ra(a);
		// should push until the stack length is 3,
		// i still have to search a good condition to do
		// that,
	}
	free(arr);
	print_stack(*a, 'A');
	print_stack(*b, 'B');
}
