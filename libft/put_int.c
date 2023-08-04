/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:56:02 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/04 04:57:57 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes a signed integer to the specified file descriptor.
 *
 * This function takes a signed integer `n` and writes its textual representation
 * to the given file descriptor `fd`. The function handles both positive and
 * negative integers, including the special case of the most negative value
 * (-2147483648). The function returns the number of characters written to the
 * file descriptor on success, or -1 on failure.
 *
 * Note: This function is used for writing integers to a file descriptor and
 * does not add a newline or any other separators after the number.
 *
 * @param n The signed integer to be written.
 * @param fd The file descriptor where the integer will be written.
 * @return The number of characters written on success, or -1 on failure.
 */

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
