/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:11:22 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/27 13:54:09 by alassiqu         ###   ########.fr       */
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
		printf("index %d, index (sorted) %d, its value %d\n", a->index,
			a->final_index, a->value);
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
	ft_check_args(argc, argv);
	stack_init(&a, argv + 1, argc);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) <= 5)
			sort_five(&a, &b);
		else
			push_swap(&a, &b);
	}
	// print_stack(a, 'A');
	// if (!stack_sorted(a))
	// 	printf("KO\n");
	// else
	// 	printf("OK\n");
	free_stack(&a, &b);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (argc < 2)
// 		ft_error();
// 	ft_check_args(argc, argv);
// 	stack_init(&a, argv + 1, argc);
// 	print_stack(a, 'A');
// 	ra(&a);
// 	print_stack(a, 'A');
// 	pb(&b, &a);
// 	// pb(&b, &a);
// 	// pb(&b, &a);
// 	// pb(&b, &a);
// 	// pb(&b, &a);
// 	print_stack(a, 'A');
// 	print_stack(b, 'B');
// }