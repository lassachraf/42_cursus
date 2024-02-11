/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:11:22 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/11 21:35:31 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, char c)
{
	t_stack	*s;

	printf("*------------%c------------*\n", c);
	if (!a)
	{
		printf("NULL\n");
		return ;
	}
	s = a;
	while (a)
	{
		printf("-> %d\n", a->value);
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
	check_doubles(a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) == 5)
			sort_five(&a, &b);
		// else
		// 	push_swap(&a, &b);
	}
	// print_stack(a, 'A');
	// print_stack(b, 'B');
	free_stack(&a, &b);
	print_stack(a, 'A');
	system("leaks push_swap");
	return (0);
}
