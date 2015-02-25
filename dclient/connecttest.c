#include "connecttest.h"

/*
 POST /REST/LOGIN HTTP/1.1\r\n
 Host: srvdmz.lysoft.ch\r\n
 User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.5) Gecko/20091102 Firefox/3.5.5 (.NET CLR 3.5.30729)\r\n
 Accept: text/html,application/xhtml+xml,application/xml;q=0.9,* / *;q=0.8\r\n
 Accept-Language: en-us,en;q=0.5\r\n
 Accept-Encoding: gzip,deflate\r\n
 Connection: keep-alive\n
 Content-type: application/x-www-form-urlencoded\r\n
 Content-Length: 23\r\n\r\n
 User=jeremy&Pass=123456");
 */

/*
 void request_bdd(char *id, char *data, int cmd);
 int client()
 {
 t_connectinfo *infolog;
 
 infolog = init_client();
 
 //  ft_connection_serveur(infolog);
 ft_request(infolog, 2, ft_ccatid(infolog->id, infolog->token));
 request_bdd("filetest1", infolog->data->reply, 0);
 request_bdd("filetest1", NULL, 1);
 close(infolog->sock);
 close_client(infolog);
 ft_request(NULL, -1, NULL);
 return (0);
 }
 */

t_connectinfo *init_client()
{
  t_connectinfo *infolog;

  infolog = ft_initlog();
  ft_connection_serveur(infolog);
  ft_authentification(infolog);
  return (infolog);
}

void close_client(t_connectinfo *infolog)
{
  ft_connection_serveur(infolog);
  ft_request(infolog, 1, ft_ccatid(infolog->id, infolog->token));
  ft_putendl(infolog->data->reply);
  free(infolog->sin);
  free(infolog->id);
  free(infolog->password);
  free(infolog->ip);
  free(infolog->token);
  free(infolog->data->reply);
  free(infolog->data);
  close(infolog->sock);
  free(infolog);
}

t_connectinfo *ft_initlog()
{
  t_connectinfo *infolog;

  infolog = (t_connectinfo *)malloc(sizeof(t_connectinfo));
  infolog->ip = (char *)malloc(20);
  infolog->id = (char *)malloc(20);
  infolog->password = (char *)malloc(20);
  strcpy(infolog->id, "User=jeremy");
  strcpy(infolog->password, "Pass=123456");
  ft_strcpy(infolog->ip, "10.10.33.101");//a lire et a convertir depuis infoApi
  infolog->data = (t_data_transfert *)malloc(sizeof(t_data_transfert));
  infolog->token = NULL;
  return (infolog);
}

char *ft_ccatid(char *id, char *pass)
{
  char *connectid;

  connectid = (char *)malloc(strlen(id) + strlen(pass) + 1);
  strcpy(connectid, id);
  strcat(connectid, "&");
  strcat(connectid, pass);
  return (connectid);
}

void ft_authentification(t_connectinfo *infolog)
{
  if(!infolog->token)
    {
     errno = 0;
      if (ft_request(infolog, 0, ft_ccatid(infolog->id, infolog->password)))
	{
	  perror("error authentification -> ");
	  exit(-1);
	}
      infolog->token = infolog->data->reply;
      infolog->token = head_parse(infolog->token, "SessionID");
      ft_putendl("premiere authentification reception de clef");
      write(2, ":", 1);
      ft_putstr_fd(infolog->token, 2);
      write(2, ":\n", 2);
    }
}

int ft_request(t_connectinfo *infolog, int cmd, char *id)
{
  //requette d'authentification pour recevoir la clef  
  static t_request *request = NULL;
  char **proto;
  int cpt;
  int fd;

  if (!request)
    {
        char str[100];
        getcwd(str, 100);
        ft_putendl_fd(str, 2);
        chdir("..");
      if ((fd = open("request_file", O_RDONLY, S_IRUSR)) == -1)
          error("open request_file");
      proto = (char **)malloc(NB_REQUEST * sizeof(char *));
      cpt = -1;
      while (++cpt < NB_REQUEST)
	ft_putendl(proto[cpt] = ft_read_chain(fd, '\n'));
      request = alloc_base_request();
      init_base_request(request, proto);
    }
  if (cmd == -1)
    {//GROSSE MERDE°°°°°°°°°°
      free(request->method);
      cpt = -1;
      while (++cpt < NB_REQUEST)
	free(request->service[cpt]);//FAUTIF
      free(request->service);
      free(request->protocol);
      free(request->HOST);
      free(request->User_Agent);
      free(request->Accept);
      free(request->Accept_Langage);
      free(request->Connection);
      free(request->Content_type);
      free(request->Content_Length);
      free(request->end);
      free(request);
      request = NULL;
      return (0);
    }
  construct_request(id , request, cmd);
  ft_putendl_fd(request->request, infolog->sock);
  ft_receve_reply_request(infolog);
  free(id);
  return (0);
}

char *head_parse(char *reply, char *chr)
{
  int cpt;
  int ok;
  char *ptr;
  char *ret;

  if (!(ptr = ft_strstr(reply, chr)))
    {
      ft_putendl("ERROR -> NON AUTORISER");
      ft_putendl(reply);
      exit (-1);
    }
  ok = 3;
  cpt = -1;
  while(ptr[++cpt] && ok)
    {
      if (ptr[cpt] == '"')
	ok--;
    }
  ret = (char *)malloc(cpt);
  strncpy(ret, ptr, cpt-1);
  ret[cpt] = '\0';
  ptr = ft_strchr(ret, '"');
  ptr[0] = '=';
  ft_strcpy(&ptr[1], &ptr[3]);
  ret[cpt] = '\0';
  free(reply);
  return (ret);
}

int ft_receve_reply_request(t_connectinfo *infolog)
{
  int timer;

  //attente de reponse
  timer = 0;
  while (!(infolog->data->size = size_fd(infolog->sock)) && timer < 10)
    {
      usleep(500000);
      timer++;
    }
  if (!infolog->data->size)
      error("no reply");
  //lecture de la reponse a la requette
  infolog->data->reply = (char *)malloc(infolog->data->size + 1);
  read(infolog->sock, infolog->data->reply, infolog->data->size);
  ft_putendl("reply recepted");
  infolog->data->reply[infolog->data->size] = '\0';
  return (1);
}

int ft_cli_socktcp(t_connectinfo *infolog)
{
  if ((infolog->sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
      ft_putendl("socket -> ");
      exit(-1);
    }
  if (!(infolog->sin->sin_addr.s_addr = (in_addr_t)ft_inet_addr(infolog->ip)))
    {
      ft_putendl("inet error ->");
      exit(-1);
    }
  infolog->sin->sin_family = PF_INET;
  infolog->sin->sin_port = ft_htons(PORT);
  ft_putendl("socket ok");
  return (0);
}

int ft_connection_serveur(t_connectinfo *infolog)
{
  infolog->sin = (t_sockaddr_in *)malloc(sizeof(t_sockaddr_in));
  ft_bzero(infolog->sin, sizeof(t_sockaddr_in));
  ft_cli_socktcp(infolog);
  ft_putendl("init connection");
  ft_printf("sock = %d, ip = %s\n\n",  infolog->sock, infolog->ip);
  if ((connect(infolog->sock, (t_sockaddr*)infolog->sin, sizeof(t_sockaddr))) == -1)
    {
      close(infolog->sock);
      perror("error -> connect\n");
      exit(-1);
    }
  ft_putendl("connected");
  return (0);
}
