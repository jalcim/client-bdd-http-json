
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servcom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 01:07:00 by jalcim            #+#    #+#             */
/*   Updated: 2014/06/19 19:24:32 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inet.h"
//#include "../bdd/transit_bdd.h"
#include "../libft/includes/libft.h"

/* partie shell
   pere retourne au shell
   fils du fils devien processus communiquation coter shell
   fils devien pere du server
   SIGUSR1 == chat
   SIGUSR2 == cmd
*/
t_server	*recup(t_server *server);

void shell_server()
{
	int pidp;
	int pid;
	int *fifo;
	
	init_transit(0);
	init_data(0);
	if (!(fifo = (int *)malloc(2*sizeof(int))))
		error("malloc error\n");
	pidp = getpid();
	if ((pid = fork()))
	{
		ft_pidsave(pid);
		return ;
	}
	pipe(fifo);
	recup_pipe(fifo);
	init_pipe_redir();
//	synch(getpid());
	printf("pid server = %d\n", getpid());
	if (!(pid = fork()))
	{
		ft_pidsave(pidp);
		wait_sig();
	}
	ft_pidsave(pid);
	signal(SIGINT, killslave);
	servershell(pid);
}

void wait_sig()
{
    signal(SIGUSR1, sig_serv);
    signal(SIGUSR2, sig_serv);

    while (1)
        pause();
}

void sig_serv(int sig)
{
    char *buffer;
    char *user;
    int *fifo;
//  int pid;

//    if ((pid = fork()))
//      return ;
    fifo = recup_pipe(NULL);
    close(fifo[1]);
    user = ft_fd_in_str(fifo[0]);
    buffer = ft_fd_in_str(fifo[0]);
    if (sig == SIGUSR1)
		chat_rcv(user, buffer);//init_transit(4); init_data(4); transit(login, buffer);
    else if (sig == SIGUSR2)//init_transit(2); init_data(2); dup2(socket, 1); transit(login, buffer); execve(buffer);
		cmd_dist_rcv(user, buffer);
//	kill(ft_pidsave(0), SIGUSR1);
    free(buffer);
    free(user);
//    exit(0);
}

/* partie server */
int synch(int pid_serv)
{
	static int spid_serv = 0;

	if (pid_serv)
		spid_serv = pid_serv;
	else
		return (spid_serv);
	return (0);
}

void redir_wait()
{
	return ;
}

void servcom(char mode, char *user, char *buffer, int pid, int sock)
{
    int *fifo;
    int *pipefd;
    char buf;
    
    //	signal(SIGUSR1, redir_wait);
    pipefd = NULL;
    fifo = recup_pipe(NULL);
    close(fifo[0]);
    if (mode == 'c')
      kill(pid, SIGUSR1);
    else if (mode == 'x')
      {
	if (!(pipefd = pipe_redir(NULL)))
	  error("pipe_redir uninitialised");
	close(pipefd[1]);
        kill(pid, SIGUSR2);
      }
    else
      error("argument not valide");
    
    ft_putstr_fd(user, fifo[1]);
    write(fifo[1], "\0", 1);
    ft_putstr_fd(buffer, fifo[1]);
    write(fifo[1], "\0", 1);
    
    printf("pid = %d\n", getpid());
    //	pause();
    while (read(pipefd[0], &buf, 1) > 0 && buf)
      write(sock, &buf, 1);
    write(sock, "\0", 1);
}

void killslave()
{
	t_server *server;
    int pid;

    pid = ft_pidsave(0);
    kill(pid, SIGINT);
	server = recup(NULL);
	close(server->sock);
    free(server->client);
    free(server);
    exit(0);
}

int ft_pidsave(int pid)
{
    static int spid = 0;

    if (pid)
        spid = pid;
    else
        return (spid);
    return (0);
}

int *recup_pipe(int *fifo)
{
    static int *fifo_save = NULL;

    if (fifo)
		fifo_save = fifo;
    else
        return (fifo_save);
    return (NULL);
}
