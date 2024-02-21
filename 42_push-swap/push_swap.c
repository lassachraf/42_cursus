/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:11:22 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/21 17:11:34 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, char c)
{
	t_stack	*s;
	int		i;

	i = 0;
	write(1, "*------------", 14);
	write(1, &c, 1);
	write(1, "------------*\n", 15);
	if (!a)
	{
		write(1, "NULL\n", 6);
		return ;
	}
	s = a;
	while (a)
	{
		printf("%d -> %d\n", a->index,a->value);
		a = a->next;
	}
	a = s;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		ft_error();
	check_args(argc, argv);
	stack_init(&a, argv + 1, argc);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) <= 5)
		{
			printf("in five section !\n");
			sort_five(&a, &b);
		}
		else
			push_swap(&a, &b);
	}
	print_stack(a, 'A');
	// free_stack(&a, &b);
	return (0);
}
