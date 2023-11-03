/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:27:49 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/03 15:38:56 by alassiqu         ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**strs;
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	k;

	strs = (char **)malloc(sizeof(char *) * count + 1);
	if (!strs)
		return (NULL);
	str = (char *)s;
	count = ft_count_words(s, c);
	i = 0;
	k = 0;
	while (k < count)
	{
		j = 0;
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
			strs[k][j++] = str[i];
		strs[k][j] = '\0';
		k++;
	}
	strs[count] = NULL;
	return (strs);
}

// void	ft_copy_word(char const *src, char *dest, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i] && src[i] != charset)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// }

// char	**ft_split(char const *s, char c)
// {
// }