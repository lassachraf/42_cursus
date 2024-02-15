/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:11:22 by alassiqu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/15 21:04:18 by alassiqu         ###   ########.fr       */
=======
/*   Updated: 2024/02/15 15:38:53 by alassiqu         ###   ########.fr       */
>>>>>>> 7637d5ff7593d0cb0233e516f386b4d74fd5021b
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, char c)
{
	t_stack	*s;
	int		i;

	i = 0;
	printf("*------------%c------------*\n", c);
	if (!a)
	{
		printf("NULL\n");
		return ;
	}
	s = a;
	while (a)
	{
		printf("%d -> %d\n", i++, a->value);
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
		else if (stack_len(a) == 5)
			sort_five(&a, &b);
		else
			push_swap(&a, &b);
	}
	// print_stack(a, 'A');
<<<<<<< HEAD
	// print_stack(b, 'B');
=======
>>>>>>> 7637d5ff7593d0cb0233e516f386b4d74fd5021b
	free_stack(&a, &b);
	return (0);
}
