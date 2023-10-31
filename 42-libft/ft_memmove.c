/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:49:08 by alassiqu          #+#    #+#             */
/*   Updated: 2023/10/31 17:11:25 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)src;
	s2 = (char *)dest;
	i = 0;
	s2[n] = '\0';
	if (s2 > s1)
		while (n-- > 0)
			s2[n] = s1[n];
	else
	{
		while (i++ < n)
			s2[i] = s1[i];
	}
	return (dest);
}

// #include <stdio.h>

// void	test_move(char *string, int d, int s, int n, char *expected)
// {
// 	char	*tmp;

// 	tmp = strdup(string);
// 	printf("- depl. %d caracteres de \"%s\" de position %d à %d. Attendu = \"%s\"\n", n, string, s, d, expected);
// 	ft_memmove(tmp + d, tmp + s, n);
// 	if (strcmp(tmp, expected) != 0)
// 		printf("ECHEC, resultat obtenu = %s\n", tmp);
// 	free(tmp);
// }

// int	main(void)
// {
// 	printf("# tests\n");
// 	test_move("abcd", 0, 0, 2, "abcd");
// 	test_move("abcd", 1, 0, 2, "aabd");
// 	test_move("abcd", 2, 0, 2, "abab");
// 	test_move("abcd", 0, 1, 2, "bccd");
// 	test_move("abcd", 1, 1, 2, "abcd");
// 	test_move("abcd", 2, 1, 2, "abbc");
// 	test_move("abcd", 0, 2, 2, "cdcd");
// 	test_move("abcd", 1, 2, 2, "acdd");
// 	test_move("abcd", 2, 2, 2, "abcd");
// 	printf("# Done\n");
// }

#include <stdio.h>

int main() {
    char buffer[] = "Hello, World!";
    char *source = buffer;
    char *destination = buffer + 6; // Overlap by moving "World!" within the same string

    printf("Original: %s\n", buffer);
    printf("Source:   %s\n", source);
    printf("Dest:     %s\n", destination);

    size_t n = 6; // Number of characters to move

    ft_memmove(destination, source, n);

    printf("After memmove:\n");
    printf("Source:   %s\n", source);
    printf("Dest:     %s\n", destination);

    return 0;
}