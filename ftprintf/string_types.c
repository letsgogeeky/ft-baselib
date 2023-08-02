/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:10:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/02 06:42:44 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	smash_strlen(const char *c)
{
	int	size;

	size = 0;
	while (c[size] != '\0')
	{
		size++;
	}
	return (size);
}

int	handle_char(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	handle_string(char *str)
{
	size_t	len;
	int		written;

	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	len = smash_strlen(str);
	written = write(1, str, sizeof(char) * len);
	if (written == -1)
		return (-1);
	return (len);
}
