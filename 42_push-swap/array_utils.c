/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:07:31 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/17 17:13:38 by alassiqu         ###   ########.fr       */
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

int	get_nb_arr_index(int *tab, int nb)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == nb)
			break;
		i++;
	}
	return (i);
}

int	get_nb_index(t_stack *a, int nb)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (a)
	{
		if (a->value == nb)
			break;
		i++;
		a = a->next;
	}
	a = tmp;
	return (i);
}
