/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 08:50:10 by jalcim            #+#    #+#             */
/*   Updated: 2014/06/08 12:23:41 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"
#include "../libft/includes/libft.h"

void ft_socktcp(int *sock, int port, t_sockaddr_in *serveur)
{
    if ((*sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        error("socket -> ");
    serveur->sin_family = PF_INET;
    serveur->sin_port = htons(port);
	errno = 0;
    if ((bind(*sock, (t_sockaddr *)serveur, sizeof(t_sockaddr))) == -1)
	{ 
		if (EACCES == errno)
			ft_putendl("L'adresse est protégée et l'utilisateur n'est pas le superutilisateur");
		error("bind -> ");
	}
}

void ft_waitsocktcp(int sock, t_pollfd *event, int size_fille, int time)
{
    event->fd = sock;
    event->events = POLLIN;
    if ((poll(event, sizeof(t_pollfd), time)) == -1)
        error("poll -> ");
    if (listen(event[0].fd, size_fille) == -1)
        error("listen -> ");
}

t_server *ft_serv_init()
{
	t_server *server;

	if (!(server = (t_server *)malloc(sizeof(t_server))))
		error("serv_init -> ");
	ft_bzero(server, sizeof(t_server));
	server->server = (t_sockaddr_in *)malloc(sizeof(t_sockaddr_in));
    ft_bzero(server->server, sizeof(t_sockaddr_in));
	server->list = NULL;
    server->connection = 0;
	return (server);
}

void ft_waitsock(int fd)
{
	t_pollfd event;
	char buf;

	while (size_fd(fd))
	{
		read(fd, &buf, 1);
		write(1, &buf, 1);
	}
    event.fd = fd;
    event.events = POLLIN;
    if ((poll(&event, sizeof(t_pollfd), 1)) == -1)
        error("poll -> ");
}
