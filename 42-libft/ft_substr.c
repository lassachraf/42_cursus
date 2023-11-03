/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:00:24 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/03 18:56:30 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		c;

	i = -1;
	c = ft_strlen(s);
	if (len > c)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !sub)
		return (NULL);
	while (++i < len)
		sub[i] = s[start++];
	sub[i] = '\0';
	return (sub);
}
