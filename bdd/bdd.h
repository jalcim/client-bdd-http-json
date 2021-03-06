#ifndef _BDD_
#define _BDD_
#include "../libft/libft.h"
#include "../libsock/ft_inet.h"
#include "../dfile/object_sig_json.h"
#include <sys/mman.h>

typedef struct s_data t_data;

struct s_data
{
  char *data;
  char *ref;
  char *filename;
  char *proto;
  char *reply;
};

int init_bdd();
void ft_sauvegarde(t_data *data);
void ft_prepare();
int ft_write_req_pipe(int fd);
int ft_read_req_pipe(int fd);
t_data *ft_analyse_request(char *request);
void ft_reply_request(t_data *data);
void bdd();
t_json *request_bdd(char *id, char *data, int cmd);
void error(char *strerr);
void new_request();
int ft_del_data(char *ref);
int *ft_recup_pid(int *pid);
t_json *ft_recup_data(t_json *data);
t_data *ft_search(t_data *data);
void dez_pipe(int *fd1, int *fd2);
#endif
