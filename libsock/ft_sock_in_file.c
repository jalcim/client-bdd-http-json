/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sock_in_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 04:45:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/06/19 20:22:55 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "ft_inet.h"
#include <stdio.h>

typedef struct s_char t_char;
struct s_char
{
  char c;

  t_char *next;
};

void inter_sd_dir(t_dirent **Rfille, DIR **rep, int socket, int nb, char *nb_file);
void ft_send_dir(int socket, char *name_dir)
{
  static int flag = 0;
  int nb;
  char *nb_file;
  DIR *rep;
  t_dirent *Rfille = NULL;

  nb = ft_compt_dir(name_dir);
  nb_file = ft_itoa(nb);

  if (!(rep = opendir(name_dir)))
    error("opendir -> ");
  chdir(name_dir);
  if (flag)
      inter_sd_dir(&Rfille, &rep, socket, nb, nb_file);
  else
    {
      flag = 1;
      write(socket, nb_file, ft_strlen(nb_file));
      write(socket, "\0", 1);
      ft_send_file(socket, name_dir, nb, &rep);
    }
  closedir(rep); 
  chdir("..");
}

void inter_sd_dir(t_dirent **Rfille, DIR **rep, int socket, int nb, char *nb_file)
{
  while (((*Rfille) = readdir((*rep))) && (*Rfille)->d_name[0] == '.')
    if ((*Rfille) == NULL)
      error("readdir -> ");
  write(socket, "1", 1);
  write(socket, nb_file, ft_strlen(nb_file));
  write(socket, "\0", 1);
  ft_send_file(socket, (*Rfille)->d_name, --nb, rep);
}

void ft_send_file(int socket, char *filename, int nb, DIR **rep)
{
  static int first = 1;
  t_dirent *Rfille = NULL;
  int fd;
  char ok;
  
  if (nb >= 0)
    {
      ft_putstr_fd(filename, socket);
      write(socket, "\0", 1);
    }
  if (ft_is_dir(filename) && !first)
    {
      nb--;
      ft_send_dir(socket, filename);
    }
  else if ((fd = open(filename, O_RDONLY, S_IRUSR)) && ((!first && nb >= 0) || (first && !nb)))
    {
      if (!fd)
	error("open ->");
      write(socket, "0", 1);
      ft_sendfile(fd, socket);
      read(socket, &ok, 1);
    }
  else
    {
      if (first)
	first = 0;
      else if (nb)
	error("sbad request -> ");
      else if (!nb)
	return ;
    }
  if (nb > 0)
    {
      while ((Rfille = readdir((*rep))) && Rfille->d_name[0] == '.')
	if (Rfille == NULL)
	  error("readdir -> ");
      if (Rfille->d_name == (char *)0x15)
	return ;
      if ((nb - 1))
	nb--;
      return (ft_send_file(socket, Rfille->d_name, nb, rep));
    }
  return ;
}

int ft_recv_file(int socket, int nb)
{
  static char first = -1;
  int fd;
  char *filename;
  
  sleep(1);
  filename = ft_recv_filename(socket);
  if (first != -1 || !nb)
    read(socket, &first, 1);
  else
    {
      first = 0;
      mkdir(filename, 0777);
      chdir(filename);
      return (ft_recv_file(socket, nb));
    }
  first -= '0';
  if (first && nb)
    {
      mkdir(filename, 0777);
      chdir(filename);
      ft_recv_file(socket, nb_dir_sock(socket));
      chdir("..");
    }
  else if ((!first || !nb) && (fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)))
    {
      free(filename);
      if (!fd)
	error("open -> ");
      ft_recvfile(socket, fd);
      write(socket, "0", 1);
    }
  first = 0;
  if (nb && --nb)
    first = ft_recv_file(socket, nb);
  return (1);
}

char *ft_fd_in_str(int node_tree)
{
  t_char *c;
  t_char *tmp;

  int size;
  char *str_tree;
  int cpt;

  size = 0;
  tmp = c = (t_char *)malloc(sizeof(t_char));
  while (++size && read(node_tree, &c->c, 1) && c->c)
      c = (c->next = (t_char *)malloc(sizeof(t_char *)));
  c->next = NULL;
  c = tmp;
  str_tree = (char *)malloc(size * sizeof(char));
  cpt = -1;
  while (size-- && c->next)
    {
      str_tree[++cpt] = c->c;
      tmp = c;
      c = c->next;
      free(tmp);
    }
  return (str_tree);
}

char *ft_recv_filename(int sock)
{
  char *filename;
  int compt;

  filename = (char *)malloc(256);
  compt = -1;
  while (read(sock, &filename[++compt], 1) && filename[compt] != '\0' && compt < 255)
    ;
  if (filename[compt] != '\0')
    exit(0);
  return (filename);
}

int ft_is_dir(char *name)
{
  DIR *tmp;

  if ((tmp = opendir(name)))
    {
      closedir(tmp);
      return (1);
    }
  return (0);
}

int ft_compt_dir(char *namedir)
{
  DIR *rep;
  t_dirent *Rfille;
  int compt;

  compt = 0;
  if (((rep) = opendir(namedir)))
    {
      while ((Rfille = readdir(rep)))
	if (Rfille->d_name[0] != '.')
	  compt++;
    }
  else
    error("opendir -> ");
  closedir(rep);
  return (compt);
}

int nb_dir_sock(int sock)
{
  char nb_dir[255];
  int compt;

  compt = -1;
  while (compt <= 255 && read(sock, &nb_dir[++compt], 1) && nb_dir[compt] != '\0')
    ;
  if (nb_dir[compt] != '\0')
    return (0);
  return (atoi(nb_dir));
}
