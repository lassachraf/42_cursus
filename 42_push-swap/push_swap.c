/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:11:22 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/01 20:22:11 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// if (!stack_sorted(a))
	// {
	// 	if (stack_len(a) == 2)
	// 		sa(&a);
	// 	else if (stack_len(a) == 3)
	// 		sort_three(&a);
	// 	else
	// 		push_swap(&a, &b);
	// }
	// free_stack(&a);
	return (0);
}
