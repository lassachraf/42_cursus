/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:22:55 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/24 18:56:48 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_address(void *p)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_print_hexa_low((unsigned long)p);
	return (count);
}
