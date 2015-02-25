/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 05:07:40 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/28 13:39:20 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void ft_putstr_fd(const char *s, int fd)
{
	if (!(write(fd, s, ft_strlen(s)) > 0))
	{
		perror("error -> \n");
		exit(0);
	}
}
