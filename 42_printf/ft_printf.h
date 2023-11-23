/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:12 by alassiqu          #+#    #+#             */
/*   Updated: 2023/11/23 20:41:51 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);

int	ft_printf(const char *s, ...);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexa_up(unsigned long num);
int	ft_print_hexa_low(unsigned long num);
int	ft_print_address(void *p);

#endif