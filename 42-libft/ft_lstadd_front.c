/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:27:07 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/08 14:27:07 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
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
// 	printf("The content of the first element is: %d\n", *(int *)lst->content);
// 	b = malloc(sizeof(int));
// 	*b = 456;
// 	ft_lstadd_front(&lst, ft_lstnew(b));
// 	printf("The content of the first element is: %d\n", *(int *)lst->content);
// 	c = malloc(sizeof(int));
// 	*c = 789;
// 	ft_lstadd_front(&lst, ft_lstnew(c));
// 	printf("The content of the first element is: %d\n", *(int *)lst->content);
// 	return (0);
// }
