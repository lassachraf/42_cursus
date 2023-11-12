/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:08:45 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/12 16:03:48 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*ret_list;
	void	*content;

	ret_list = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			content = f(lst->content);
			new_list = ft_lstnew(content);
			if (!new_list)
			{
				del(content);
				ft_lstclear(&ret_list, del);
				return (ret_list);
			}
			ft_lstadd_back(&ret_list, new_list);
			lst = lst->next;
		}
	}
	return (ret_list);
}

// void	*add_one(void *num)
// {
// 	int	*new_num;

// 	new_num = malloc(sizeof(int));
// 	*new_num = *(int *)num + 2;
// 	return (new_num);
// }

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d ", *(int *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("\n");
// }

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*new_list;
// 	int		a;
// 	int		b;
// 	int		c;

// 	a = 5;
// 	b = 12;
// 	c = 2002;
// 	lst = ft_lstnew(&a);
// 	ft_lstadd_back(&lst, ft_lstnew(&b));
// 	ft_lstadd_back(&lst, ft_lstnew(&c));
// 	printf("Original list: ");
// 	print_list(lst);
// 	new_list = ft_lstmap(lst, &add_one, &free);
// 	if (!new_list)
// 	{
// 		printf("ft_lstmap returned NULL\n");
// 		return (1);
// 	}
// 	printf("New list     : ");
// 	print_list(new_list);
// 	return (0);
// }
