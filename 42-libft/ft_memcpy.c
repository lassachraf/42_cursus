/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:47:39 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/03 16:09:22 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = 0;
	while (i++ < n && s2)
		*s1++ = *s2++;
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
