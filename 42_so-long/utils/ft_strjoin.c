/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:20:37 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/20 17:57:05 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin_2(char const *s1, char const *s2)
{
	char	*start;
	char	*str;
	int		total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * total_len);
	if (!str)
		return (NULL);
	start = str;
	while (*s1)
		*start++ = *s1++;
	while (*s2)
		*start++ = *s2++;
	*start = '\0';
	return (str);
}
