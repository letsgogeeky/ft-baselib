/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:58:49 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/30 00:18:41 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	str_arr_len(char **arr)
{
	size_t	len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

void	str_arr_free(char **arr)
{
	int	idx;

	idx = 0;
	while (arr && arr[idx] != 0)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}

void	ra_print_str_arr_fd(char **arr, int fd)
{
	int	idx;

	idx = 0;
	if (!arr)
		return ;
	while (arr[idx])
	{
		ft_putendl_fd(arr[idx], fd);
		idx++;
	}
	return ;
}
