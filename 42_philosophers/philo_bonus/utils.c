/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:00:53 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/11 16:50:06 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_count_digits(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		sign;
	char	*str;
	long	i;

	i = (long)n;
	sign = 0;
	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	digits = ft_count_digits(i) + sign;
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (sign)
		str[0] = '-';
	while (--digits >= sign)
	{
		str[digits] = i % 10 + '0';
		i /= 10;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		total;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (s1);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc(total * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s2);
	return (str);
}

bool	should_stop(t_state	state)
{
	if (state == DEAD)
		return (true);
	if (state == FINISH)
		return (true);
	if (state == FULL)
		return (true);
	return (false);
}
