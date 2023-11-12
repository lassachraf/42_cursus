/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:26:55 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/08 14:26:55 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

// int	main(void)
// {
// 	t_list	*lst;
// 	int		*a;
// 	int		*b;
// 	int		*c;

// 	a = malloc(sizeof(int));
// 	*a = 123;
// 	lst = ft_lstnew(a);
// 	printf("Last element content is: %d\n", *(int *)ft_lstlast(lst)->content);
// 	b = malloc(sizeof(int));
// 	*b = 456;
// 	ft_lstadd_back(&lst, ft_lstnew(b));
// 	printf("Last element content is: %d\n", *(int *)ft_lstlast(lst)->content);
// 	c = malloc(sizeof(int));
// 	*c = 789;
// 	ft_lstadd_back(&lst, ft_lstnew(c));
// 	printf("Last element content is: %d\n", *(int *)ft_lstlast(lst)->content);
// 	return (0);
// }
