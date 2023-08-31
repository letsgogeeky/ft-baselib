/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:32:55 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/31 18:21:13 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ra_int_in_bound(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

long long	ra_parse_long(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_iswhitespace(*str))
		str++;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		result = result * 10;
		result += *str - 48;
		str++;
	}
	result *= sign;
	return (result);
}

int	ra_is_int(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (0);
	if (str[idx] == '-' && str[idx + 1])
		idx++;
	while (str[idx])
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (0);
		idx++;
	}
	return (1);
}
