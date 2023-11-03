/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:45:55 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/03 17:01:11 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	i = -1;
	while (++i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(s + i));
	}
	return (NULL);
}
