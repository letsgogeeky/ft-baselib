/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:56:19 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/04 17:27:06 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_double(int fd, double num, u_int8_t percision)
{
	int		count;
	int		p_idx;

	p_idx = 0;
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
