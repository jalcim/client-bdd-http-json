
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 20:22:37 by jalcim            #+#    #+#             */
/*   Updated: 2014/06/19 19:45:09 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "ft_inet.h"

#include <stdio.h>
#include <sys/mman.h>

char *ft_readfd(int fd, int nb_oct)
{
    char *str;

    str = (char *)projectm(fd, PROT_READ, nb_oct);

    return (str);
}

char *ft_writefd(int fd, int nb_oct)
{
    char *str;

    str = (char *)projectm(fd, PROT_WRITE, nb_oct);

    return (str);
}

int size_fd(int fd)
{
    struct stat status;

    fstat(fd, &status);

    return ((int)status.st_size);
}

void *projectm(int fd, int prot, int nb_oct)
{
    void *addr = NULL;

    addr = mmap(addr, nb_oct, prot, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
		error("mmap -> ");
    msync(addr, nb_oct, 0);
    return (addr);
}

void ft_sendfile(int fd, int sock)
{
    char *str;
    int nb_oct;

    if (!(nb_oct = size_fd(fd)))
	{
		ft_putendl_fd("error tranfers is empty", 2); 
		return ;
	}
    str = ft_readfd(fd, nb_oct);
    write(sock, str, nb_oct);
    munmap(str, nb_oct);
}

void ft_recvfile(int sock, int fd)  
 {
    char *str;
    int nb_oct;
    char *formate;

    if (!(nb_oct = size_fd(sock)))
	{
		ft_putendl_fd("error tranfers is empty", 2);
		return ;
	}
    formate = (char *)malloc(nb_oct);
    ft_memset(formate, '\0', nb_oct);
    write(fd, formate, nb_oct);
    free(formate);

    str = ft_writefd(fd, nb_oct);
    read(sock, str, nb_oct);

    munmap(str, nb_oct);
}

void ft_redirfd(int fd1, int fd2)
{
    char *str1;
    int nb_oct;
    char *str2;
    char *formate;

    if (!(nb_oct = size_fd(fd1)))
	{
		ft_putendl_fd("error tranfers is empty", 2);
		return ;
	}
    str1 = ft_readfd(fd1, nb_oct);

    formate = (char *)malloc(nb_oct);
    ft_memset(formate, '\0', nb_oct);
    write(fd2, formate, nb_oct);
    free(formate);

    str2 = ft_writefd(fd2, size_fd(fd2));
    ft_memcpy(str2, str1, nb_oct);

    munmap(str1, nb_oct);
    munmap(str2, nb_oct);
}
