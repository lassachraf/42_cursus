/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/15 22:44:17 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	get_number_top(t_stack **a, int index)
// {
// 	int	n;

// 	n = stack_len(*a) / 2;
// 	if (index > n)
// 	{
// 		while (index <= stack_len(*a))
// 		{
// 			rra(a);
// 			index++;
// 		}
// 	}
// 	else
// 	{
// 		while (--index)
// 			ra(a);
// 	}
// }

// void	pushing_min(t_stack **a, t_stack **b)
// {
// 	t_stack	*tmp;
// 	int		index;
// 	int		nb;
// 	int		i;

// 	tmp = *a;
// 	i = 1;
// 	nb = tmp->value;
// 	index = 0;
// 	while (tmp)
// 	{
// 		if (nb > tmp->value)
// 		{
// 			nb = tmp->value;
// 			index = i;
// 		}
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	get_number_top(a, index);
// 	pb(b, a);
// }

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
		printf("cc\n");
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (arr[i])
	{
		printf("arr[%d] == %d\n", i, arr[i]);
		i++;
	}
	return (arr);
}

int	get_chunk(t_stack *a)
{
	int nb;

	nb = stack_len(a);
	if (nb < 20)
		return(5);
	else if (nb < 100)
		return(10);
	else
		return(30);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	*arr;
	int	nb_chunk;
	int	mid;
	(void)b;
	
	arr = sort_int_tab(copy_arr(*a), stack_len(*a));
	nb_chunk = get_chunk(*a);
	mid = stack_len(*a) / 2 - 1;
	
	// while ((*a)->next->next->next)
	// 	pushing_min(a, b);
	// sort_three(a);
	// while ((*b)->next)
	// 	pa(a, b);
	// pa(a, b);
	// pa(a, b);
	// print_stack(*a, 'A');
	// print_stack(*b, 'B');
	// get the cheapest number instructions and push it, than sort it !
	// should be in a loop to do the same with all elements in stack b !
}
