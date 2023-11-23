/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:29:14 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/23 20:47:16 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_up(unsigned long num)
{
	char	*hexa;
	int		count;

	hexa = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		count += ft_print_hexa_up(num / 16);
		count += ft_print_hexa_up(num % 16);
	}
	else
		count += ft_putchar(hexa[num]);
	return (count);
}
