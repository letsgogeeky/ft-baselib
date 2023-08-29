/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:08:02 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/29 23:18:31 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

int		gnl_strlen(char *c);
char	*gnl_strjoin(char *s1, char *s2, int s2_len);
void	gnl_bzero(void *s, int len);
char	*gnl_calloc(size_t count, size_t size);
char	*gnl_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif
