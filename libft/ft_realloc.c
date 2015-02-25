/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 17:18:13 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/26 09:14:17 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void *ft_realloc (void *replace, int size)
{
    char *ptr;

    ptr = NULL;
    if (!(ptr = (char *)malloc(size)))
        return (NULL);
	ft_bzero (ptr, size);
    ft_memcpy(ptr, (char *)replace, sizeof(*replace));
	free(replace);
	return ((void *)ptr);
}
