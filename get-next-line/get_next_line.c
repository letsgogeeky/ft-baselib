/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:08:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/29 23:18:06 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000
#endif

static char	*adjust_buffer(char *str)
{
	int		buffer_idx;
	int		new_idx;
	char	*new_buffer;

	buffer_idx = 0;
	if (!str)
		return (free(str), NULL);
	while (str[buffer_idx] && str[buffer_idx] != '\n')
		buffer_idx++;
	if (!str[buffer_idx])
		return (free(str), NULL);
	new_buffer = gnl_calloc(gnl_strlen(str) - buffer_idx + 1, sizeof(char));
	if (new_buffer == NULL)
		return (free(str), free(new_buffer), NULL);
	buffer_idx++;
	new_idx = 0;
	while (str[buffer_idx])
		new_buffer[new_idx++] = str[buffer_idx++];
	new_buffer[new_idx + 1] = 0;
	return (free(str), new_buffer);
}

static char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		line = gnl_calloc(i + 1, sizeof(char));
	else
		line = gnl_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		if (line[i] == '\n')
		{
			i++;
			line[i] = 0;
			break ;
		}
		i++;
	}
	return (line);
}

static char	*gnl_read_from_fd(int fd, char *str)
{
	int		read_size;
	char	*tmp;

	tmp = gnl_calloc(BUFFER_SIZE, sizeof(char));
	if (!tmp)
		return (free(str), NULL);
	read_size = read(fd, tmp, BUFFER_SIZE);
	if (read_size == -1)
		return (free(tmp), free(str), NULL);
	while (read_size > 0)
	{
		str = gnl_strjoin(str, tmp, read_size);
		if (str && gnl_strchr(str, '\n'))
			break ;
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
			return (free(tmp), tmp = NULL, free(str), NULL);
	}
	free(tmp);
	tmp = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = gnl_read_from_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = adjust_buffer(buffer);
	return (line);
}
