/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:20:37 by alassiqu          #+#    #+#             */
/*   Updated: 2023/10/31 22:56:07 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*start;
	char	*str;
	int		total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char *) * total_len);
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

// #include <stdio.h>

// int main() {
//     const char *s1 = "Hello, ";
//     const char *s2 = "world!";

//     char *result = ft_strjoin(s1, s2);

//     if (result) {
//         printf("Concatenated string: %s\n", result);
//         free(result);
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }