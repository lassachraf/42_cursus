/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:10:39 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/03 18:03:45 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (c == 0)
		return ((char *)(s + i + 1));
	while (i > 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	const char *p = "achraf";
// 	char *p1 = ft_strrchr(p, 'a');
// 	printf("%s\n", p);
// }