/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:00:04 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/11 11:43:04 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char **s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if (atol(s[i]) > 2147483647 || atol(s[i]) < -2147483648)
			flag = 1;
		i++;
	}
	if (flag == 1)
		ft_error_args(s);
}

void	check_args(int ac, char **av)
{
	char	**s;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < ac)
	{
		j = 0;
		s = ft_split(av[i], ' ');
		check_int(s);
		while (s[j])
		{
			k = 0;
			if (s[j][k] == '-')
				k = 1;
			while (s[j][k])
			{
				if (!ft_isdigit(s[j][k++]))
					ft_error();
			}
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
}

void	check_doubles(t_stack *a)
{
	t_stack *tmp;
	int		n;

	tmp = a;
	n = 0;
	while (a)
	{
		n = a->value;
		a = a->next;
		while (a)
		{
			if (n == a->value)
				ft_error();
			a = a->next;
		}
		tmp = tmp->next;
		a = tmp;
	}
}
