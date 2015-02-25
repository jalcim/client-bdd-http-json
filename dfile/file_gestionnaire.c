#include "object_sig_json.h"

/*
  ces fonctions prennent des fichiers deja parser et pret a l'utilisation
*/
t_json *rect(int fd);
void ft_sl()
{
  return;
}

t_json *recurs_file(t_dirent *Rfille, DIR *rep)
{
  int dir;
  int fd;
  t_json *json;
  int pidp;

  signal(SIGUSR1, ft_sl);
  if (Rfille == NULL)
    return (NULL);
  printf("for file :%s:\n", Rfille->d_name);
  if ((fd = open(Rfille->d_name, O_RDONLY, S_IRUSR)) != -1)
    {
      dir = 0;
      pidp = getpid();
      if (!fork())
	{
	  usleep(500000);
	  kill(pidp, SIGUSR1);
	  exit(-1);
	}
      json = rect(fd);
      write_elem_json(json, 2);
      close(fd);
    }
  else
    dir = 1;
  if (!(json->next_chain = recurs_file((Rfille = readdir(rep)), rep)))
    printf("NULL\n");
  return (json);
}
/*
int main()
{
  t_json *json;
  DIR *rep;
  t_dirent *Rfille;

  chdir("/Users/Lysoft/project/dfile/reg");
  rep = opendir(".");
  while ((Rfille = readdir(rep)) && Rfille->d_name[0] == '.');

  ft_putendl(Rfille->d_name);
  json = recurs_file(Rfille, rep);
  return (0);
}
*/
t_json *rect(int fd)
{
  t_json *json;
  t_json *first;
  t_json *s = NULL;
  t_json *save = NULL;
  int bol;
  char *str;

  first = json = (t_json *)malloc(sizeof(t_json));
  pause();
  while (((str = ft_read_chain(fd, '\n'))))
    {
      bol = 0;
      if (str[0] == '\0' )
	{//
	  free(str);
	  str = NULL;
	  json->var = NULL;
	  //	  if (save)//
	  //	    {//
	      json = save;
	      free(json->next_var);
	      json->next_var = NULL;
	      json->next_chain = (t_json *)malloc(sizeof(t_json));
	      json = json->next_chain;
	      first->next_chain = json;
	      //	    }//
	  bol = 1;
	}//
      else if (!(json->var = ft_read_chain(fd, '\n')))
	{
	  json->var = ft_strnew("-1");
	  error("no data ?!\n\n\n\n\n");//return (first);
	}
      if (!bol)
	{//
	  json->namevar = str;
	  json->next_var = (t_json *)malloc(sizeof(t_json));
	  save = json;
	  json = json->next_var;
	  json->next_chain = NULL;
	}//
      else
	  json->next_var = NULL;
    }
  free(json);
  s = first;
  first = first->next_var;
  free(s);
  return (first);
}

/*
void error(char *strerr)
{
  perror(strerr);
  exit (-1);
}
*/