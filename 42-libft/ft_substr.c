/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:00:24 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/05 18:13:12 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char		*sub;
// 	size_t		i;

// 	i = 0;
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (!s || len > (ft_strlen(s) - start))
// 		return (NULL);
// 	sub = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!sub)
// 		return (NULL);
// 	while (i < len)
// 		sub[i++] = s[start++];
// 	sub[i] = '\0';
// 	return (sub);
// }
