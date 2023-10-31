/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:00:24 by alassiqu          #+#    #+#             */
/*   Updated: 2023/10/31 22:13:45 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = -1;
	sub = (char *)malloc(len + 1);
	if (!s || !sub)
		return (NULL);
	while (++i < len)
		sub[i] = s[start++];
	sub[i] = '\0';
	return (sub);
}
