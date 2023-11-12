/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:27:15 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/08 14:27:15 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

// void	del(void *content)
// {
// 	free(content);
// }

// void	print_content(void *content)
// {
// 	printf("Content: %d\n", *(int *)content);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	int		*a;
// 	int		*b;
// 	int		*c;

// 	a = malloc(sizeof(int));
// 	*a = 5;
// 	b = malloc(sizeof(int));
// 	*b = 12;
// 	c = malloc(sizeof(int));
// 	*c = 2002;
// 	lst = ft_lstnew(a);
// 	ft_lstadd_back(&lst, ft_lstnew(b));
// 	ft_lstadd_back(&lst, ft_lstnew(c));
// 	ft_lstclear(&lst, del);
// 	printf("Content : '");
// 	ft_lstiter(lst, print_content);
// 	printf("'\nThe list has been deleted.\n");
// 	return (0);
// }
