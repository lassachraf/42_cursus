/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:27:21 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/08 14:27:21 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	(*del)(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	int		*a;

// 	a = malloc(sizeof(int));
// 	*a = 5122002;
// 	lst = ft_lstnew(a);
// 	printf("Node before deletion is: %d\n", *(int *)lst->content);
// 	ft_lstdelone(lst, del);
// 	printf("Node after deletion is: %d\n", *(int *)lst->content);
// 	return (0);
// }
