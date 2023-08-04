/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:56:02 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/04 05:20:41 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_int(int n, int fd)
{
	int		count;
	int		written;
	char	c;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		written = write(fd, "-", 1);
		if (written == -1)
			return (-1);
		count = put_int(n, fd);
		return (count + 1);
	}
	if (n > 9)
	{
		count = put_int(n / 10, fd);
		if (count == -1)
			return (-1);
		c = '0' + n % 10;
		return (count + write(fd, &c, 1));
	}
	c = '0' + n;
	return (write(fd, &c, 1));
}
