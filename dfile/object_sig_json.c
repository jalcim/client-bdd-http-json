#include "object_sig_json.h"

/*
void ft_wait()
{
  return ;
}

int main()
{
  int fd1[2];
  int fd2[2];
  t_json *json;

  pipe(fd1);
  pipe(fd2);
  fd2[0] = open("reg/json", O_RDONLY, S_IWUSR);//pour les tests
  chdir("reg/");
  json = json_analyse(fd2[0]);//fd2[0] est a recuperer par static

  return (0);
}

void gest(int fd)
{
  char *str;
  char **name;
  int cpt;
  int fd_out;

  sleep(1);
  str = ft_read_chain(fd, '\0');
  name = ft_strsplit(str, '\n');
  cpt = -3;
  while ((str = ft_read_chain(fd, '\0')) && str[0])
    {
      if (++cpt < 0)
	continue;
      if ((fd_out = open(name[cpt], O_CREAT | O_WRONLY, S_IRWXU)) == -1)//pour les tests
	error("open gest ->");
      ft_putendl_fd(name[cpt], 2);
      ft_putendl_fd(str, 2);
      ft_putendl_fd(str, fd_out);
    }
}
*/

t_json *json_analyse(int fd_rd_bdd)
{
  int cpt;
  char *file;
  t_json *json = NULL;
  int fd1[2];
  int fd2[2];
  int pid;
  int pid2;
  
  pipe(fd1);
  pipe(fd2);
  if (!(file = ft_read_chain(fd_rd_bdd, '\0'))
      || !file[0])
    error("no data for analyse");
  cpt = -1;
  while (file[++cpt] != '{');
  pid = getpid();
  if (!fork())
    {
      pid2 = getpid();
      if (fork())
	{
	  signal(SIGUSR1, ft_wait);
	  preparse(fd1[0], fd2[1], pid2);//process 2
	}
      else
	{
	  prepreparse(&file[cpt], fd1[1], pid);//process 3
	  pid = getpid();
	}
    }
  else
    {
      json = parse(fd2[0]);//process 1
      write_json(json);
    }
  free(file);
  close(fd1[0]);
  close(fd1[1]);
  close(fd2[0]);
  close(fd2[1]);
  return (json);
}

/*
void ft_mods(t_json *json, int fd)
{//3 MODULES DE MANIPULATION DES DONNES
  t_json *njson;

  //ecriture de tous les id patient
  if (!(njson = search_json(json, "Id_Patient\n", NULL)))//retourne tous les id_patient
    error("search == NULL");
  write_path_json(njson, fd);//ecrit tous les id_patient (pour l'application)
  //
  //ecriture de tous les dossiers separer par un '\0'
  write_json(json, fd);
}


 void selon_patient()
 {//ecriture de tous les id patients, ecriture de dossier patient concerner
 char *id_p;
 int pipefd[2];
 //coter appli
 pipe(pipefd);
 ft_putendl_fd("13103", pipefd[1]);
 close(pipefd[1]);
 //coter gestionnaire
 id_p = ft_read_chain(pipefd[0], '\n');
 if (!id_p)
 return ;
 if (!(json = search_json(json, "Id_Patient\n", id_p)))//retourne le dossier patient suivant son id_patient
 return ;
 write_elem_json(json, fd);//ecrit le dossier patient
 close(pipefd[0]);
 //
 }
*//*
void error(char *strerr)
{
  perror(strerr);
  exit(-1);
}
*/
