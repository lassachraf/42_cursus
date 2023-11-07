/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:27:49 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/07 18:58:10 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char	**ft_custom_copy(char **strs, char *str, size_t count, char c)
{
	size_t		i;
	size_t		len;
	const char	*start;

	i = 0;
	while (i < count)
	{
		len = 0;
		while (*str == c)
			str++;
		start = str;
		while (*str && *str != c)
		{
			str++;
			len++;
		}
		strs[i] = (char *)malloc(len + 1);
		if (!strs[i])
			return (NULL);
		ft_strlcpy(strs[i], start, len + 1);
		i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	size_t	count;

	if (!s)
		return (NULL);
	str = (char *)s;
	count = ft_count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (0);
	strs = ft_custom_copy(strs, str, count, c);
	strs[count] = 0;
	return (strs);
}
