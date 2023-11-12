/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:22:40 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/12 12:00:56 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*last;
// 	int		a;
// 	int		b;
// 	int		c;

// 	a = 5;
// 	b = 12;
// 	c = 2002;
// 	lst = ft_lstnew(&a);
// 	ft_lstadd_back(&lst, ft_lstnew(&b));
// 	ft_lstadd_back(&lst, ft_lstnew(&c));
// 	last = ft_lstlast(lst);
// 	printf("The content of the last element is: %d\n", *(int *)last->content);
// 	return (0);
// }
