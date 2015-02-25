#ifndef __ft_inet__
#define __ft_inet__
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <poll.h>
#include <dirent.h>
#include <signal.h>

typedef struct dirent t_dirent;
typedef struct sockaddr_in t_sockaddr_in;
typedef struct in_addr t_in_addr;
typedef struct pollfd t_pollfd;
typedef struct sockaddr t_sockaddr;
typedef struct s_aton t_aton;
typedef struct s_server t_server;
typedef struct s_client t_client;

struct s_server
{
  int pid;
  int connection;
  t_sockaddr_in *server;
  int sock;
  t_client *list;
  t_client *client;
};

struct s_client
{
  int port;
  t_sockaddr_in *info;
  t_pollfd *event;
  t_client *next;
};

struct	s_aton
{
  u_long		parts[4];
  in_addr_t	val;
  char		*c;
  char		*endptr;
  int			gotend;
  int			n;
};

unsigned long int ft_inet_addr(const char *ip);
int ft_inet_aton(const char *cp, struct in_addr *addr);
unsigned short ft_htons(unsigned short value);
unsigned int ft_htonl(unsigned int value);

char    *locate(char *user);
char    *ft_reip(char *s);

int ft_recv_file(int socket, int nb);
void ft_send_file(int socket, char *filename, int nb, DIR **rep);
void ft_send_dir(int socket, char *name_dir);
void ft_sendfile(int fd, int sock);
void ft_recvfile(int sock, int fd);
int redirfd(int fd1, int fd2);
char *ft_readfd(int fd, int nb_oct);
char *ft_writefd(int fd, int nb_oct);
char *ft_fd_in_str(int fd);
void *projectm(int fd, int prot, int nb_oct);
int fd_size(int fd);
int ft_is_dir(char *name);
void ft_waitsock(int fd);//[del]

void ft_socktcp(int *sock, int port, t_sockaddr_in *serveur);
void ft_waitsocktcp(int sock, t_pollfd *event, int size_fille, int time);
void wait_connect(t_server *server);
void new_connect(t_server *server);
void ft_accept(t_server *server);

t_server *ft_serv_init();
void acceuil(t_server *server, int pid);
char cmd_sock(int sock);
int nb_dir_sock(int sock);
int ft_compt_dir(char *namedir);
int nb_dir_sock(int sock);
char *ft_recv_filename(int sock);
void ft_serv_end();

void servershell(int pid);
void shell_server();
void wait_sig();
void sig_serv(int sig);
void servcom(char mode, char *user, char *buffer, int pid, int sock);
int *recup_pipe(int *fifo);
int ft_pidsave(int pid);
void killslave();
void error(char *strerr);

void chat_rcv(char *login, char *buffer);
void cmd_dist_rcv(char *login, char *buffer);
void init_pipe_redir();
int *pipe_redir(int *fd);
int size_fd(int fd);

int synch(int pid_serv);
void redir_wait();
void error(char *strerr);
#endif
