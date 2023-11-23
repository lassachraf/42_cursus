/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:24:45 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/23 21:36:45 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_perc_in_s(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}

int	ft_format(va_list ap, const char *s)
{
	int	count;

	count = 0;
	if (*s == 'd' || *s == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (*s == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*s == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*s == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (*s == 'p')
		count += ft_print_address(va_arg(ap, void *));
	else if (*s == 'x')
		count += ft_print_hexa_low(va_arg(ap, unsigned int));
	else if (*s == 'X')
		count += ft_print_hexa_up(va_arg(ap, unsigned int));
	else if (*s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	if (ft_perc_in_s(s, '%') == 1)
	{
		while (*s)
		{
			if (*s == '%')
			{
				s++;
				if (!*s)
					break ;
				count += ft_format(ap, s);
			}
			else
				count += ft_putchar(*s);
			s++;
		}
	}
	else
		count += ft_putstr((char *)s);
	va_end(ap);
	return (count);
}
// int main()
// {
// 	printf("%d\n", ft_printf("          abcdef      %"));
// 	printf("%d\n", printf("          abcdef      %"));
// }
