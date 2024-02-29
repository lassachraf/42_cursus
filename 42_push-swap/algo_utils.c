/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:07:31 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/29 18:06:19 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	if (size <= 1)
		return (0);
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

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

int	get_min(t_stack **a)
{
	t_stack	*tmp;
	int		nb;

	tmp = *a;
	while (tmp)
	{
		if (nb > tmp->value)
			nb = tmp->value;
		tmp = tmp->next;
	}
	return (nb);
}

int	check_reverse(t_stack **a)
{
	t_stack	*tmp;
	int        i;
	int        size;
	int        nb;

	tmp = *a;
	i = 1;
	size = stack_len(*a);
	while (tmp && i != size)
	{
		if (tmp->value > tmp->next->value)
			i++;
		tmp = tmp->next;
		if (!tmp->next)
			break ;
	}
	if (i == size)
	{
		nb = get_min(a);
		while ((*a)->value != nb)
			ra(a, 1);
		return (1);
	}
	return (0);
}
