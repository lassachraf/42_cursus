/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:13:39 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/12 11:58:00 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	t_list	*lst;
// 	int		size;
// 	int		a;
// 	int		b;
// 	int		c;

// 	a = 5;
// 	b = 12;
// 	c = 2002;
// 	lst = ft_lstnew(&a);
// 	ft_lstadd_back(&lst, ft_lstnew(&b));
// 	ft_lstadd_back(&lst, ft_lstnew(&c));
// 	size = ft_lstsize(lst);
// 	printf("The size of the list is: %d\n", size);
// 	while (size--)
// 	{
// 		printf("%d\n", *(int *)lst->content);
// 		lst = lst->next;
// 	}
// 	return (0);
// }
