/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:11:35 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/28 21:24:47 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42_libft/libft.h"
#include "../push_swap.h"
#include "get_next_line.h"

int	ft_check_operation(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(a, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(b, a, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		return (free(line), ft_error(), 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	ft_check_args(argc, argv);
	stack_init(&a, argv + 1, argc);
	line = get_next_line(0);
	while (line)
	{
		ft_check_operation(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (!stack_sorted(a))
		printf("KO\n");
	else
		printf("OK\n");
	free_stack(&a, &b);
	system("leaks checker");
	return (0);
}
