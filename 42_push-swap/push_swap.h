/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:21:41 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/18 21:21:41 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;	

// Handle input : ./push_swap "1 -42 1337"
char	**ft_split(char *str, char separator);

// Handle errors-free :

// Stack creation :

// Stack utils :
// void			append_node(t_stack **stack, int nbr);
// t_stack	*find_last_node(t_stack *head);
// t_stack	*find_smallest(t_stack *stack);
// t_stack	*return_cheapest(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	finish_rotation(t_stack **s, t_stack *n, char c);

// Algorithms :
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);

// Actions/Operations functions :
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

#endif