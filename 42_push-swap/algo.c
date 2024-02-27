/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:03:19 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/27 17:33:34 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexing(t_stack *a, int *arr)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (i < stack_len(tmp))
	{
		while (tmp)
		{
			if (tmp->value == arr[i])
			{
				tmp->final_index = i;
				break ;
			}
			tmp = tmp->next;
		}
		tmp = a;
		i++;
	}
	free(arr);
	return (i);
}

// int	still_numbers(t_stack **a, int mid)
// {
// 	t_stack	*tmp;

// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (tmp->final_index < mid)
//             return (1);
//         tmp = tmp->next;
// 	}
// 	return (0);
// }

// int	get_chunk(t_stack **a, int mid, int nb)
// {
// 	if (nb >= 100 && nb <= 500)
// 	{
// 		if (mid != nb - 3)
// 		{
// 			if (mid + 25 >= nb - 3)
// 				return (nb - 3);
// 			return (mid + 25);
// 		}
// 		else
// 			return (0);
// 	}
// 	else if (nb < 100)
// 	{
// 		if (mid != nb - 3)
// 		{
// 			if (mid + 25 >= nb - 3)
// 				return (nb - 3);
// 			return (mid + 25);
// 		}
// 		else
// 			return (0);
// 	}
// 	return (-1);
// }

// void stac_a_to_b(t_data *data,t_list **stac_a, t_list **stac_b)
// {
//     int i;
//     int nb;
//     i = 0;
//     data->end--;
//     while(*stac_b)
//     {
//         if((*stac_b)->content == data->sort[data->end])
//         {
//            pa(stac_a,stac_b);
//            printf("pa\n");
//            data->end--;
//         }
//         else
//         {
//             if(i == 0)
//             {
//                nb = (*stac_a)->content;
//                pa(stac_a,stac_b);
//                printf("pa\n");
//                ra(stac_a);
//                printf("ra\n");
//                i = 1;
//             }
//             else if(check_repeat_nb(*stac_b,data->sort[data->end]) == 0 && i == 1)
//             { 
//                 if (ft_lstlast(*stac_a)->content == nb)
//                     i = 0;
//                 rra(stac_a);
//                 data->end--;
//                 printf("rra\n");
//             }
//             else if((*stac_b)->content > ft_lstlast(*stac_a)->content && i == 1)
//             {
//                pa(stac_a,stac_b);
//                printf("pa\n");
//                ra(stac_a);
//                printf("ra\n");
//             }
//             else
//             {
//                ra_or_rra(data,stac_b);
//             }
//         }
//     }
//     i = 0;
//     while (i <= 23)
//     {
//         rra(stac_a);
//         printf("rra\n");
//         i++;
//     }
// }

void	push_back(t_stack **a, t_stack **b, int *arr)
{
	(void)a;
	(void)b;
	(void)arr;
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*arr;
	int		nb;
	int		mid_index;
	int		i;

	i = 0;
	tmp = *a;
	arr = sort_int_tab(copy_arr(*a), stack_len(*a));
	nb = indexing(*a, arr);
	mid_index = nb / 2;
	while (1)
	{
		if ((*a)->final_index < mid_index)
			pb(b, a);
		else
			ra(a);
		if (stack_len(*a) == mid_index)
			mid_index = nb - 3;
		if (stack_len(*a) == 3)
			break ;
	}
	sort_three(a);
	// printf("arr => %d\n", arr[nb - 1]);
	// push_back(a, b, arr);
	// print_stack(*a, 'A');
	// print_stack(*b, 'B');
	// while (*b)
	// 	push_max(a, b, nb);
}
