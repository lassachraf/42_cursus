/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:45:55 by alassiqu          #+#    #+#             */
/*   Updated: 2023/10/30 18:15:22 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (++i < n)
		if ((unsigned char)s == (unsigned char)c)
			return ((void *)(s + i));
	return (NULL);
}
