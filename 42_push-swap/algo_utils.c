/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:07:31 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/27 10:07:30 by alassiqu         ###   ########.fr       */
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

void	push_max(t_stack **a, t_stack **b, int n)
{
	t_stack	*tmp;
	int		temp;
	int		nb;
	int		i;

	tmp = *b;
	i = 1;
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
	max_util(b, temp, n, nb);
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
