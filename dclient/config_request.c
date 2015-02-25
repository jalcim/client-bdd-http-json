#include "connecttest.h"

t_request *alloc_base_request()
{
  t_request *request;

  request = (t_request *)malloc(sizeof(t_request));
  request->method = (char *)malloc(ft_strlen("POST /REST") + 1);
  request->service = (char **)malloc(NB_REQUEST * sizeof(char *));

  request->protocol = (char *)malloc(ft_strlen("HTTP/1.1\r\n") + 1);
  request->HOST = (char *)malloc(ft_strlen("HOST: srvdmz01.lysoft.ch\r\n") + 1);
  request->User_Agent = (char *)malloc(ft_strlen("User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.5) Gecko/20091102 Firefox/3.5.5 (.NET CLR 3.5.30729)\r\n") + 1);
  request->Accept = (char *)malloc(ft_strlen("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n") + 1);
  request->Accept_Langage = (char *)malloc(ft_strlen("Accept-Language: en-us,en;q=0.5\r\n") + 1);
  //  request->Accept_Encoding = (char *)malloc(ft_strlen("Accept-Encoding: utf-8\r\n") + 1);
  request->Connection = (char *)malloc(ft_strlen("Connection: keep-alive\n") + 1);
  request->Content_type = (char *)malloc(ft_strlen("Content-type: application/x-www-form-urlencoded\r\n") + 1);
  request->Content_Length = (char *)malloc(ft_strlen("Content-Length: ") + 1);
  request->end = (char *)malloc(ft_strlen("\r\n\r\n") + 1);
  return (request);
}

void init_base_request(t_request *request, char **proto)
{
  int cpt;

  strcpy(request->method, "POST /REST");
  request->service = proto;
  cpt = -1;
  while (++cpt < NB_REQUEST)
    request->service[cpt] = ft_strnew(proto[cpt]);
  strcpy(request->protocol, "HTTP/1.1\r\n");
  strcpy(request->HOST, "HOST: srvdmz01.lysoft.ch\r\n");
  strcpy(request->User_Agent, "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.5) Gecko/20091102 Firefox/3.5.5 (.NET CLR 3.5.30729)\r\n");
  strcpy(request->Accept, "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n");
  strcpy(request->Accept_Langage, "Accept-Language: en-us,en;q=0.5\r\n");
  //  strcpy(request->Accept_Encoding, "Accept-Encoding: utf-8\r\n");
  strcpy(request->Connection, "Connection: keep-alive\n");
  strcpy(request->Content_type, "Content-type: application/x-www-form-urlencoded\r\n");
  strcpy(request->Content_Length, "Content-Length: ");
  strcpy(request->end, "\r\n\r\n");
}

char *construct_request(char *id, t_request *request, int cmd)
{
  int size;
  char *csize;

  size = ft_strlen(request->method)+ ft_strlen(request->service[cmd])+ ft_strlen(request->protocol)+ ft_strlen(request->HOST)
    + ft_strlen(request->User_Agent)+ ft_strlen(request->Accept)+ ft_strlen(request->Accept_Langage)
    /*+ ft_strlen(request->Accept_Encoding)*/+ ft_strlen(request->Connection)+ ft_strlen(request->Content_type)
    + ft_strlen(request->Content_Length) + ft_strlen(request->end) + ft_strlen(id);
  request->request = (char *)malloc(size + 1);
  ft_strcpy(request->request, request->method); ft_strcat(request->request, request->service[cmd]);
  ft_strcat(request->request, request->protocol); ft_strcat(request->request, request->HOST);
  ft_strcat(request->request, request->User_Agent); ft_strcat(request->request, request->Accept);
  ft_strcat(request->request, request->Accept_Langage); //ft_strcat(request->request, request->Accept_Encoding);
  ft_strcat(request->request, request->Connection); ft_strcat(request->request, request->Content_type);
  ft_strcat(request->request, request->Content_Length);
  csize = ft_itoa(ft_strlen(id));
  ft_strcat(request->request, csize); ft_strcat(request->request, request->end); ft_strcat(request->request, id);
  return (request->request);
}
