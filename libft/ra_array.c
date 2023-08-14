/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:58:49 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/14 02:25:56 by ramoussa         ###   ########.fr       */
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
	}
	free(arr);
}
