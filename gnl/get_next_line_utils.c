/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:05:45 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/29 18:16:09 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, s1_len + 1);
	ft_strlcpy((joined_str + s1_len), s2, s2_len + 1);
	free(s1);
	return (joined_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[start] && j < len)
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}

long	ft_strchr(const char *s, char c)
{
	long	cur;

	cur = 0;
	while (s[cur])
	{
		if (s[cur] == (unsigned char)c)
			return (cur);
		cur++;
	}
	if (s[cur] == (unsigned char)c)
		return (cur);
	return (-1);
}
