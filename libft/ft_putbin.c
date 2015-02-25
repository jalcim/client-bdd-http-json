/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 21:59:09 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/25 22:03:16 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putbin(unsigned int origin)
{
    unsigned int bit = 1;
    unsigned int compt = 0;
    char *print;

    bit = origin;
    while (bit != 0)
    {
        bit >>= 1;
        compt++;
    }
    bit = 1;
    bit <<= (compt - 1);
    while (bit <= origin && bit)
    {
        write(1, (print = (bit & origin ? "1" : "0")), 1);
        bit >>= 1;
    }
    write(1, "\n", 1);
}

unsigned int ft_bindec(char *bin)
{
    unsigned int nb;
    unsigned int bit = 1;
    unsigned int compt = 0;
    int size;

    size = strlen(bin);
    while (bin[--size])
    {
        if (bin[size] == '1')
            nb |= bit;
        bit <<= 1;
        compt++;
    }
    return (nb);
}
