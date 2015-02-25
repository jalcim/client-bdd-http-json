/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 02:21:53 by jalcim            #+#    #+#             */
/*   Updated: 2014/06/10 02:07:24 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_inet.h"

char	*ft_reip(char *origin)
{
    char *final;
    int cpt1;
    int cpt2;

    if (!origin)
      error("no ip adresse");
    final = (char *)malloc(20);
    final[0] = '1';
    final[1] = '0';
    final[2] = '.';
    final[3] = '1';
    cpt1 = 1;
    cpt2 = 4;
    while (origin[cpt1])
      {
        if (origin[cpt1]>= '0' && origin[cpt1] <= '9')
	  final[cpt2] = origin[cpt1];
        else
	  final[cpt2] = '.';
        cpt2++;
        cpt1++;
      }
    printf("connexion a :%s:\n", final);
    return (final);
}
