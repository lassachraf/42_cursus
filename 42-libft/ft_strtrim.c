/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 23:02:30 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/01 11:45:43 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_first_char(char *s)
{
	int	i;

	i = 0;
	while (*s && ft_iswhitespace(*s++))
		i++;
	return (i);
}

static int	ft_last_char(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (s[i] && ft_iswhitespace(s[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char *s)
{
	int		start;
	int		end;
	int		len;
	char	*res;
	char	*ret;

	start = ft_first_char(s);
	end = ft_last_char(s);
	len = end - start + 1;
	res = malloc(sizeof(char *) * len);
	ret = res;
	while (*s && ft_iswhitespace(*s))
		s++;
	while (len--)
		*res++ = *s++;
	*res = '\0';
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		f;
// 	int		l;
// 	char	*s = "      ./ alassiqu ./ 12'21'     ./ ";
// 	char	*r;

// 	f = ft_first_char(s);
// 	l = ft_last_char(s);
// 	printf("Indexes : '%i' / '%i'\n", f, l);
// 	r = ft_strtrim(s);
// 	printf("\"%s\"\n", r);
// }
