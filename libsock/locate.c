/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 02:21:12 by jalcim            #+#    #+#             */
/*   Updated: 2014/06/10 02:34:23 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"

char    **ft_strsplit(const char *str, char c);
char    *ft_reip(char *s);
char	*locate(char *user)
{
	const char	*url = "https://dashboard.42.fr/crawler/pull/";
	const char	*cmd = "curl -30kq -silent ";
	char		buff[4096];
	pid_t		child;
	char		**arg;
	char		*tmp;
	int		fd[2];
	char	**ret;
	char	*ip;
	char	*k;
	int	b = -1;

	pipe(fd);
	if (!(tmp = malloc(sizeof(*tmp) * (strlen(cmd) + strlen(url) + strlen(user) + 2))))
		return (NULL);
	tmp = strcpy(tmp, cmd);
	tmp = strcat(tmp, url);
	tmp = strcat(tmp, user);
	tmp = strcat(tmp , "/");
	if (!(arg = ft_strsplit(tmp, ' ')))
		return (NULL);
	free(tmp);
	child = fork();
	if (child)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		read(0, buff, 4096);
		k = strdup(buff);
		ret = ft_strsplit(k, '"');
		ip = strdup(ret[5]);
		while (ret[++b])
			free(ret[b]);
		free(ret);
		ip[strlen(ip) - 6] = 0;
		if (ip[0] == 'e' && ip[1] == 'r')
			return (NULL);
		return (ft_reip(ip));
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execv("/usr/bin/curl", arg);
	}
	return (NULL);
}
