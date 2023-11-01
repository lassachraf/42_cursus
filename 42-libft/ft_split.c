/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:27:49 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/01 14:37:57 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i++] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_copy_word(char const *s, char *ret, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		ret[j++] = s[i++];
	ret[j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		count;
	int		i;
	int		j;

	count = ft_count_words(s, c);
	ret = (char **)malloc((sizeof(char *) * count));
	if (!ret)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < count)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i++] != c)
			j++;
		ret[i] = (char *)malloc(sizeof(char) * j + 1);
		if (!ret[i])
			return (NULL);
		ft_copy_word(s, ret[i], c);
	}
	return (ret);
}
#include <stdio.h>
int	main(void)
{
	char const	*s = "abcabcdecbfhcjklmnc po";
	// char		**p = ft_split(s, 'c');
	char		**d = ft_split(s, 'b');
	while (*d++)
		printf("\'%s\'\n", *d);
}
