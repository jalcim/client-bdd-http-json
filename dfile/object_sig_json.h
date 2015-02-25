#ifndef _JSON_
#define _JSON_
#include "../libsock/ft_inet.h"
#include "../libft/libft.h"

typedef struct s_json t_json;
struct s_json
{
  char *namevar;
  char *var;

  t_json *path;
  t_json *next_var;
  t_json *next_chain;
  t_json *last;
};

char *ft_croch(char *file, char c);
t_json *parse(int fd);
void preparse(int fd, int fd2, int pid);
void prepreparse(char *file, int fd, int pid);

t_json *search_json(t_json *json, char *namevar, char *id);
t_json *json_analyse(int fd_rd_bdd);
void gest(int fd);
void ft_mods(t_json *json, int fd);

void write_json(t_json *json);
void write_elem_json(t_json *json, int fd);
void write_path_json(t_json *json, int fd);
void ft_wait();
#endif
