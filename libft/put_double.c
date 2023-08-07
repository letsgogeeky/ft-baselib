/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:56:19 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/07 23:56:43 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_double(int fd, double num, u_int8_t percision)
{
	int		count;
	int		p_idx;

	p_idx = 0;
	if (num < 0 && (int)num == 0)
		write(fd, "-", 1);
	count = put_int((int)num, fd);
	num = num - (int)num;
	if (num < 0)
		num *= -1;
	if (percision > 0)
	{
		count += write(fd, ".", 1);
		while (p_idx < percision)
		{
			num *= 10;
			count += put_int((int)num, fd);
			num = num - (int)num;
			p_idx++;
		}
	}
	return (count);
}

double	get_double(char	*str)
{
	int		idx;
	double	result;
	char	**parts;
	double	divisor;
	int		is_negative;

	idx = 0;
	result = 0;
	is_negative = 0;
	parts = ft_split(str, '.');
	result = ft_atoi(parts[0]);
	if (str && str[0] == '-' && result == 0)
		is_negative = 1;
	divisor = 10.0;
	while (parts[1] && parts[1][idx])
	{
		result += (double)(parts[1][idx] - '0') / divisor;
		divisor *= 10.0;
		idx++;
	}
	if (is_negative == 1)
		result = result * -1;
	return (result);
}
