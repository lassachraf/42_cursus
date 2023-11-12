/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:40:21 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/12 21:13:32 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		p[n] = (unsigned char)c;
	return (s);
}

// int main()
// {
// 	int s[] = {4,3,8};
// 	// 111 11010000
// 	ft_memset(&s[0],43,1);
// 	printf("%d\n",s[0]);
// }
