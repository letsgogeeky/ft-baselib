/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:08:06 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/29 23:16:26 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *c)
{
	int	size;

	size = 0;
	if (!c)
	{
		return (size);
	}
	while (c[size] != '\0')
	{
		size++;
	}
	return (size);
}

void	gnl_bzero(void *s, int len)
{
	int		idx;
	char	*tmp;

	idx = 0;
	tmp = (char *)s;
	while (idx < len)
	{
		tmp[idx] = '\0';
		idx++;
	}
}

char	*gnl_calloc(size_t count, size_t size)
{
	char	*str;

	if (count * size / count != size)
		return (NULL);
	str = (char *)malloc(count * size);
	if (!str)
	{
		return (free(str), str = NULL, NULL);
	}
	gnl_bzero(str, count * size);
	return (str);
}

char	*gnl_strchr(const char *s, int c)
{
	unsigned char	cr;

	cr = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == cr)
		{
			return ((char *)s);
		}
		s++;
	}
	if (cr == '\0' && *s == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2, int s2_len)
{
	unsigned int	len;
	char			*str;
	unsigned int	str_idx;
	int				s2_idx;

	len = gnl_strlen(s1) + s2_len;
	str_idx = 0;
	s2_idx = 0;
	str = (char *)gnl_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && s1[str_idx] != '\0')
	{
		str[str_idx] = s1[str_idx];
		str_idx++;
	}
	while (s2_idx < s2_len)
	{
		str[str_idx] = *s2;
		s2++;
		str_idx++;
		s2_idx++;
	}
	str[str_idx] = '\0';
	return (free(s1), s1 = NULL, str);
}
