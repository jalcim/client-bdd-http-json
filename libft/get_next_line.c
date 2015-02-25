/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 16:18:58 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/25 01:27:23 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

static int   get_read (int fd, char **bin, char **buf, int *ret);

int		get_next_line (int fd, char **line)
{
	char	*buf;
	static char		*bin = NULL;
	int		ret;
	int		size;

	size = 0;
	if (!bin)
	{
		if (!(bin = (char *)malloc (BUFF_SIZE)))
			return (-1);
		ft_bzero (bin, BUFF_SIZE);
		ret = 1;
	}
	if (!(buf = (char *)malloc (BUFF_SIZE + 1)))
		return (-1);

	buf[BUFF_SIZE] = '\0';
	ft_bzero((*line), sizeof ((*line)));

	size = get_read (fd, (char **)&bin, &buf, &ret);

	if (size >= sizeof((*line)))
		(*line) = (char *)realloc ((*line), size + 1);

	ft_strncat ((*line), bin, size);
	ft_strcat ((*line), "\0");
	ft_strcpy (bin, bin + size + 1);
	return (ret);
}

static int	get_read (int fd, char **bin, char **buf, int *ret)
{
	int size;
	size = 0;
	int boll = 1;

	while ((*bin)[size] != '\n' && boll)
	{
		if (ft_strlen((*bin)) >= ((BUFF_SIZE - (BUFF_SIZE / 2)) - 1))
			if (!((*bin) = (char *)ft_realloc ((*bin), ((ft_strlen((*bin)) / 2) * 3))))
				return (0);
		ft_bzero ((*buf), BUFF_SIZE);
		if (!(*ret += read (fd, (*buf), BUFF_SIZE)))
			boll = 0;
		ft_strcat ((char *)(*bin), (*buf));
		size = ft_strlcar((*bin), '\n');
	}

	return (size);
}
