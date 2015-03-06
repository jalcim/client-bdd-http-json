#include "bdd.h"
#include <sys/types.h>
#include <unistd.h>
#include "../dfile/file_gest.h"

int svpid_synch(int pid);
int spfd(int *pipe, int in_out);
void file_gestionnaire();

int sort_err;

int init_bdd()
{
  int *fd1;
  int *fd2;
  int *pid;

  pid = (int *)malloc(2 * sizeof(int));
  fd1 = (int *)malloc(2 * sizeof(int));//pipe de requette
  fd2 = (int *)malloc(2 * sizeof(int));//pipe de reponse
  if (pipe(fd1)
      || pipe(fd2))
    error("creat pipe");
  dez_pipe(fd1, fd2);
  pid[0] = getpid();
  signal(SIGUSR1, ft_wait);
    ft_prepare();//verifie la presence du repertoire reg ou le cree et s'y deplace
    if (!(pid[1] = fork()))
    {
      ft_recup_pid(pid);//signal sur pid
      ft_read_req_pipe(fd1[0]);//pipe de requette
      ft_write_req_pipe(fd2[1]);//pipe de reponse
      close(fd1[1]);
      close(fd2[0]);
      chdir("..");
      sort_err = open("error_out", O_CREAT | O_RDWR, S_IRWXU);
      dup2(sort_err, 2);
        chdir("reg");
        ft_putendl_fd("start", 2);
        bdd();
      exit(0);
    }
  else
    {
      ft_recup_pid(pid);//signal sur pid
      ft_write_req_pipe(fd1[1]);//pipe de requette
      ft_read_req_pipe(fd2[0]);//pipe de reponse
      close(fd1[0]);
      close(fd2[1]);
      return (0);
    }
  return (-1);
}

t_json *request_bdd(char *id, char *data, int cmd)
{
  static char **prototype;
  int pipefd;
  int *pid;
  int pipid;
  char *strerr;
  t_json *json = NULL;
  //  t_json *sjson = NULL;

  if (!(pipefd = ft_write_req_pipe(0)))
    error("req_write_pipe");
  if (!prototype)
    {
      prototype = (char **)malloc(4 * sizeof(char *));
      prototype[0] = ft_strnew("send");
      prototype[1] = ft_strnew("extract");
      prototype[2] = ft_strnew("delete");
      prototype[3] = ft_strnew("tab_id");
    //prototype[3] = ft_strnew("send-gzip");
    }
  else
    if (cmd == -1)
      {
	free(prototype[0]);
	free(prototype[1]);
	free(prototype[2]);
	free(prototype[3]);
	free(prototype);
      }
  //////////////////////////////
  ft_putstr_fd(prototype[cmd], pipefd);
  write(pipefd, "\0", 1);
    ft_putendl_fd(prototype[cmd], 2);
  ft_putstr_fd(id, pipefd);
  write(pipefd, "\0", 1);
    ft_putendl_fd(id, 2);
    ft_putendl_fd("info sended", 2);
  if (cmd == 0)
    {
      ft_putstr_fd(data, pipefd);
      write(pipefd, "\0", 1);
    }
  pid = ft_recup_pid(NULL);
  if (kill(pid[1], SIGUSR1))
    error("signal error ->");
    ft_putstr_fd("sig send at process ", 2);
    ft_putnbr_fd(pid[0], 2);
    ft_putendl("\n");
  ////////////////////////////////
  usleep(500000);
  ////////
  ft_putendl_fd("reply", 2);
  strerr = ft_read_chain(ft_read_req_pipe(0), '\0');
  if (!(ft_strcmp(strerr, "error")))
    error(strerr);
  //
  strerr = ft_read_chain(ft_read_req_pipe(0), '\0');
  if (!(ft_strcmp(strerr, "bad request")))
    error(strerr);
  ////////
  if (cmd == 1 || cmd == 3)
    {
      signal(SIGUSR1, ft_wait);
      pipid = getpid();
      if (fork())
          json = parse(ft_read_req_pipe(0));
      else
      {
          usleep(500000);
          kill(pipid, SIGUSR1);
          ft_putnbr_fd(pipid, 2);
          ft_putendl_fd(" signal de parse", 2);
          exit(0);
      }
    }
  return (json);
}

int *ft_recup_pid(int *pid)
{
  static int *pids;

  if (pid)
    pids = pid;
  return (pids);
}

t_json *ft_recup_data(t_json *data)
{
  static t_json *datas = NULL;
  if (data)
    datas = data;
  return (datas);
}

void bdd()
{
  //  t_json *namelist;
    ft_putendl_fd("start bdd pour error_out", 2);
  signal(SIGUSR1, new_request);//si signal on a recu une requete
  //  namelist = all_id_folder();//recupere les noms de fichier
  while (1)
  {
      ft_putendl_fd("wait request error_out", 2);
      dup2(2, 1);
      printf("getpid = %d\n", getpid());
      pause();//on attend une requete pour deriver sur new_request
      ft_putendl_fd("end request error_out", 2);
  }
}

void ft_prepare()
{
    t_dirent *Rfille;
    DIR *rep;
 
    chdir("Users/lysoft/client-bdd-http-json/");

    rep = opendir(".");
    while ((Rfille = readdir(rep)))
        if (Rfille->d_name[0] != '.')
            ft_putendl_fd(Rfille->d_name, 2);
    closedir(rep);

    ft_putendl_fd("creat", 2);
    mkdir("reg", 0700);
    chdir("reg/");

    rep = opendir(".");
    while ((Rfille = readdir(rep)))
        if (Rfille->d_name[0] != '.')
            ft_putendl_fd(Rfille->d_name, 2);
    closedir(rep);
}

void new_request()
{
    ft_putendl_fd("fork new request error_out", 2); 
  if (fork())
    return ;
  ft_putendl_fd("new request", 2);
  ft_reply_request(ft_analyse_request(ft_fd_in_str(ft_read_req_pipe(0))));
  ft_putendl_fd("end new request", 2);
  exit(0);
}

/*
int main()
{
  int pifd[2];
  int fd;
  int size;
  char *str;

  pipe(pifd);
  chdir("../dfile/reg/");
  fd = open("json", O_RDONLY);
  ft_read_req_pipe(pifd[0]);
  size = size_fd(fd);
  str = ft_readfd(fd, size);
  ft_putstr_fd("filename", pifd[1]);
  write(pifd[1], "\0", 1);
  ft_putstr_fd(str, pifd[1]);
  write(pifd[1], "\0", 1);
  ft_analyse_request("send");
}
*/

t_data *ft_analyse_request(char *request)
{
  t_data *reply;
  int pipefd;
  int fd;
  t_json *json;
  char *tmp;
  char *tmp2;
  int size;
  int size2;

  pipefd = ft_read_req_pipe(0);//pipe de requette
  reply = (t_data *)malloc(sizeof(t_data));//structure de reponse
  if (!(reply->filename = ft_read_chain(pipefd, '\0')))//lecture dans pipe de requette
    error("no data for reply");
  if (!request)
    error("no request");
  if (!(ft_strcmp(request, "send")))//reception d'un fichier
    {
      json = json_analyse(pipefd);//parse
      //      write_json(json);//creation fichier//remplissage fichier
      reply->proto = ft_strnew("recept");//message de retour
      reply->reply = ft_strnew(reply->filename);//message de retour
    }
  else if (!(ft_strcmp(request, "tab_id")))//envoi d'un fichier
    {
        ft_putendl_fd("tab_id", 2);
      write_file_tab_id();//cherche tous les id et les noms et les ecrits dans le fichier tab_id
        ft_putendl_fd("????", 2);
      if ((fd = open("tab_id", O_RDONLY, S_IRUSR)) == -1)
	return (NULL);
      reply->proto = ft_strnew("tab_id");//retour de protocol
      reply->reply = ft_strnew("id");
      if (!(size = size_fd(fd)))//retour du fichier//bloque ici
	error("file 0 octet");
      tmp = ft_readfd(fd, size);
      reply->data = ft_strnew(tmp);
      munmap(tmp, size_fd(fd));
      close(fd);
    }
  else if (!(ft_strcmp(request, "extract")))//envoi d'un fichier
    {
      if ((fd = open(reply->filename, O_RDONLY)) == -1)//le fichier existe il ?
	return (NULL);//non retour d'erreur
      reply->proto = ft_strnew("extract");//oui retour de protocol
      dup2(1, 2);
      reply->reply = ft_strnew(reply->filename);
      reply->data = ft_strnew(tmp = ft_readfd(fd, size_fd(fd)));//retour du fichier
      munmap(tmp, size_fd(fd));
      close(fd);
    }
  else if (!(ft_strcmp(request, "delete")))//destruction de fichier
    {
      unlink(reply->filename);//dez
      reply->proto = ft_strnew("delete");//retour protocol
      reply->reply = ft_strnew(reply->filename);//retour nom de fichier
      fd = open("tab_id", O_RDWR, S_IRWXU);
      size = size_fd(fd);
      tmp = (char *)malloc(size + 1);
      read(fd, tmp, size);
      close(fd);
      unlink("tab_id");
      fd = open("tab_id", O_CREAT | O_RDWR, S_IRWXU);
      tmp[size] = 0;
      tmp2 = ft_strstr(tmp ,reply->filename);
      size2 = ft_strlcar(tmp2, '\n');
      size2 += ft_strlcar(&tmp2[size2 + 2], '\n') + 3;
      ft_strcpy(&tmp[tmp2 - tmp], &tmp2[size2]);
      ft_putendl_fd(tmp, 2);
      ft_putstr_fd(tmp, fd);
      close(fd);
    }
  else                                   //erreur
    {
      reply->proto = ft_strnew("error");
      reply->reply = ft_strnew("bad request");
    }
  return (reply);
}

void ft_reply_request(t_data *data)
{
  int pipefd;

  pipefd = ft_write_req_pipe(0);
  if (data == NULL)
    {
      ft_putstr_fd("extract", pipefd);
      write(pipefd, "\0", 1);
      ft_putstr_fd("error", pipefd);
      write(pipefd, "\0", 1);
      ft_putstr_fd("no data", pipefd);
      write(pipefd, "\0", 1);
      return ;
    }
  ////////
  ft_putstr_fd(data->proto, pipefd);
  write(pipefd, "\0", 1);
  free(data->proto);
  //
  ft_putstr_fd(data->reply, pipefd);
  write(pipefd, "\0", 1);
  free(data->reply);
  ////////
  if (!ft_strcmp(data->proto, "extract")
      || !ft_strcmp(data->proto, "tab_id"))
    {
      ft_putstr_fd(data->data, pipefd);
      write(pipefd, "\0", 1);
      free(data->data);
    }
}

int ft_read_req_pipe(int fd)
{
  static int sfd = 0;

  if (fd)
    sfd = fd;
  return (sfd);
}

int ft_write_req_pipe(int fd)
{
  static int sfd = 0;

  if (fd)
    sfd = fd;
  return (sfd);
}

void dez_pipe(int *fd1, int *fd2)
{
  static int **fd;

  if (!fd)
    fd = (int **)malloc(2 * sizeof(int *));
  if (fd1)
    {
      fd[0] = fd1;
      fd[1] = fd2;
    }
  else
    {
      close(fd[0][0]);
      close(fd[0][1]);
      close(fd[1][0]);
      close(fd[1][1]);
      free(fd[0]);
      free(fd[1]);
      free(fd);
      fd = NULL;
    }
}
