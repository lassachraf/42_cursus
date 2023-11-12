/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:27:27 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/08 14:27:27 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// void	print_content(void *content)
// {
// 	printf("Content: %d\n", *(int *)content);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	int		a;
// 	int		b;
// 	int		c;

// 	a = 5;
// 	b = 12;
// 	c = 2002;
// 	lst = ft_lstnew(&a);
// 	ft_lstadd_back(&lst, ft_lstnew(&b));
// 	ft_lstadd_back(&lst, ft_lstnew(&c));
// 	ft_lstiter(lst, print_content);
// 	return (0);
// }
