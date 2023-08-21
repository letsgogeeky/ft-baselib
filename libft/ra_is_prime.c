/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 23:51:49 by ramymoussa        #+#    #+#             */
/*   Updated: 2023/08/16 23:58:01 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ra_is_prime(int number)
{
    int i;

    if (number <= 1)
        return (0);
    if (number <= 3)
        return (1);
    if (number % 2 == 0 || number % 3 == 0)
        return (0);
    i = 5;
    while (i * i <= number)
    {
        if (number % i == 0)
            return (0);
        i++;
    }
    return (1);
}
