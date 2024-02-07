/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:41 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/07 16:05:36 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "42_libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

// Handle errors-free :
void	ft_error(void);
// void	ft_error_and_free(void);

// All checks :
void	check_args(int ac, char **av);
void	check_doubles(t_stack *a);
void	push_min(t_stack **a, t_stack **b);
void	push_max(t_stack **a, t_stack **b);
void	min_util(t_stack **a, int temp);
void	max_util(t_stack **a, int temp);
void	free_stack(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
void	push_min_100(t_stack **a, t_stack **b);
// Stack creation :

// Stack utils :
void	stack_init(t_stack **a, char **av, int ac);
void	append_node(t_stack **stack, int nbr);
t_stack	*find_last_node(t_stack *head);
t_stack	*find_smallest(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
// void	stack_init(t_stack **a, );

// Algorithms :
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
// void	push_swap(t_stack **a, t_stack **b);

// Actions/Operations functions :
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif