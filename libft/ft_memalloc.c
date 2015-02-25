/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:19:34 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 20:57:13 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void ft_bzero (void *src, size_t size);

void * ft_memalloc(size_t size)
{
  char *tab;
  tab = (char *)malloc (size);
  if (tab == NULL)
    return (NULL);

  ft_bzero(tab, size);

  return (tab);
}
