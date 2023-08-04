/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:56:19 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/04 05:20:05 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_double(int fd, double num, u_int8_t percision)
{
	double	original;
	int		count;
	int		p_idx;

	original = num;
	p_idx = 0;
	count = put_int((int)num, fd);
	num = num - (int)num;
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
