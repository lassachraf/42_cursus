/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:02:30 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/04 21:42:19 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_first_char(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (*s && ft_is_char_in_set(*s++, set))
		i++;
	return (i);
}

static int	ft_last_char(char const *s, char const *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (s[i] && ft_is_char_in_set(s[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*ret;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = ft_last_char(s1, set) - ft_first_char(s1, set) + 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	ret = res;
	while (*s1 && ft_is_char_in_set(*s1, set))
		s1++;
	while (len--)
		*res++ = *s1++;
	*res = '\0';
	return (ret);
}
