/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 04:56:19 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/04 05:03:06 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes a double-precision floating-point number to specified file descriptor.
 *
 * This function takes a double-precision floating-point number `num` and writes
 * its textual representation to the given file descriptor `fd`. The `percision`
 * parameter specifies the number of decimal places to be displayed for the
 * fractional part of the number. The function returns the number of characters
 * written to the file descriptor on success.
 *
 * The function internally converts the double value into its integer and
 * fractional parts and uses the `put_int` function to write the integer part to
 * the file descriptor. If the `percision` value is greater than zero, it writes
 * the fractional part by multiplying the remaining decimal values with 10 and
 * repeatedly calling `put_int` to write each digit to the file descriptor.
 *
 * @param fd The file descriptor where the double will be written.
 * @param num The double-precision floating-point number to be written.
 * @param percision The number of decimal places for the fractional part.
 * @return The number of characters written to the file descriptor on success.
 */

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
