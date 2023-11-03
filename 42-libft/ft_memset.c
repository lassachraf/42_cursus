/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:40:21 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/03 17:56:10 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		p[n] = (unsigned char)c;
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	array[8];
// 	for (int i = 0; i < 8; i++)
// 	{
// 		printf("%d\n", array[i]);
// 	}
// 	ft_memset(array, '2', 8);
// 	for (int i = 0; i < 8; i++)
// 	{
// 		printf("%d\n", array[i]);
// 	}
// 	// memset(array, '4', 8);
// 	// printf("%d\n", array);
// }
