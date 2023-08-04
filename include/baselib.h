/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baselib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 05:01:36 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/04 05:04:17 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASELIB_H
# define BASELIB_H
# include "../libft/libft.h"

char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);

#endif