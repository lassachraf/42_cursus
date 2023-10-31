/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:40:21 by alassiqu          #+#    #+#             */
/*   Updated: 2023/10/31 17:31:38 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	p[n] = '\0';
	while (n--)
		p[n] = (unsigned char)c;
	return (s);
}

#include <stdio.h>

int	main(void)
{
	char	array[8];

	ft_memset(array, '3', 8);
	printf("%s\n", array);
	memset(array, '4', 8);
	printf("%s\n", array);
}
