/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:30:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/02 06:39:04 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	gnl_strlen(char *c)
{
	int	size;

	size = 0;
	if (!c || !c[size])
	{
		return (size);
	}
	while (c && c[size] && c[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	unsigned int	len;
	char			*str;
	unsigned int	str_idx;

	if (!s1 || !s2)
		return (NULL);
	len = gnl_strlen(s1) + gnl_strlen(s2);
	str_idx = 0;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (s1[str_idx] != '\0')
	{
		str[str_idx] = s1[str_idx];
		str_idx++;
	}
	while (*s2 != '\0')
	{
		str[str_idx] = *s2;
		s2++;
		str_idx++;
	}
	str[str_idx] = '\0';
	free(s1);
	return (str);
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

char	*gnl_calloc(unsigned int count, unsigned int size)
{
	char	*str;

	str = malloc(count * size);
	if (!str)
	{
		return (NULL);
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
