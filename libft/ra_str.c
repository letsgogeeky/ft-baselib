/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:25:36 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/16 21:20:37 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ra_replace(char *str, char a, char b)
{
	int	idx;

	if (!str)
		return ;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == a)
			str[idx] = b;
		idx++;
	}
}

int	ra_is_whiteshapce(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
