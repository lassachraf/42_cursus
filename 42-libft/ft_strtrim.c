/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:02:30 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/02 13:07:24 by alassiqu         ###   ########.fr       */
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
	int		start;
	int		end;
	int		len;
	char	*res;
	char	*ret;

	start = ft_first_char(s1, set);
	end = ft_last_char(s1, set);
	len = end - start + 1;
	res = malloc(sizeof(char *) * len);
	ret = res;
	while (*s1 && ft_is_char_in_set(*s1, set))
		s1++;
	while (len--)
		*res++ = *s1++;
	*res = '\0';
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		f;
// 	int		l;
// 	char	*s = "nul";
// 	char	*r;

// 	f = ft_first_char(s, "nul");
// 	l = ft_last_char(s, "nul");
// 	printf("Indexes : '%i' / '%i'\n", f, l);
// 	r = ft_strtrim(s, "nul");
// 	printf("\"%s\"\n", r);
// }
