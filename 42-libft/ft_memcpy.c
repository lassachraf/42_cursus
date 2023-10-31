/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:47:39 by alassiqu          #+#    #+#             */
/*   Updated: 2023/10/31 20:52:13 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (!src && !dest)
		return (NULL);
	s1 = (char *)dest;
	s2 = (char *)src;
	i = -1;
	while (++i < num)
		s1[i] = s2[i];
	s1[num] = '\0';
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	orgnl[50] = "Hey from CLUSTER E1";
// 	char	copy[50];
// 	char	*res;

// 	res = ft_memcpy(copy, orgnl, 10);
// 	printf("%s\n", res);
// 	printf("%s\n\n", copy);
// 	res = memcpy(copy, orgnl, 10);
// 	printf("%s\n", res);
// 	printf("%s\n", copy);
// }
