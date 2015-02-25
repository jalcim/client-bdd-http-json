#ifndef _CLIENT_
#define _CLIENT_
#include "../libsock/ft_inet.h"
#include "../libft/libft.h"

#define PORT 80
#define NB_REQUEST 3

typedef struct s_request t_request;
typedef struct s_connectinfo t_connectinfo;
typedef struct s_data_transfert t_data_transfert;

struct s_request
{
  char *method;
  char **service;
  char *protocol;
  char *HOST;
  char *User_Agent;
  char *Accept;
  char *Accept_Langage;
  char *Accept_Encoding;
  char *Connection;
  char *Content_type;
  char *Content_Length;
  char *end;
  char *Body;

  char *request;
};

struct s_connectinfo
{
  int sock;
  int port;
  t_sockaddr_in *sin;
  char *id;
  char *password;
  char *ip;
  char *token;
  t_data_transfert *data;
};

struct s_data_transfert
{
  char *reply;
  int size;
};

void close_client(t_connectinfo *infolog);
int init_bdd();
int client();

t_connectinfo *ft_initlog();
t_connectinfo *init_client();
int ft_connection_serveur(t_connectinfo *infolog);
int ft_cli_socktcp(t_connectinfo *infolog);
int ft_request(t_connectinfo *infolog, int cmd, char *id);
void ft_authentification(t_connectinfo *infolog);
int ft_receve_reply_request(t_connectinfo *infolog);
void error(char *strerr);
char *head_parse(char *reply, char *chr);

char *construct_request(char *id, t_request *request, int cmd);
void init_base_request(t_request *request, char **proto);
t_request *alloc_base_request();

char *ft_ccatid(char *id, char *pass);
#endif
