#include "object_sig_json.h"
#include "../bdd/bdd.h"

t_json *search_json(t_json *json, char *namevar,char *id)
{
  t_json *ptr;
  t_json *save = NULL;//

  ft_putendl_fd("search_json", 2);
  if (!json)
    error("no json");
  ptr = json;
  ft_putendl_fd("????", 2);
  while (1)
    {
      if (!json->next_var)
	{
	  ft_putendl_fd("plus de variable", 2);
	  if (!json->next_chain)
	    {
	      ft_putendl_fd("plus de chaine", 2);
	      break;
	    }
	}
      while (json->next_var)
	{
	  if (!json->namevar)
	    break;
	  if (!strcmp(json->namevar, namevar))
	    {
	      if (!id)
		{//
		  if (!save)
		    save = json;
		  ptr->path = json;
		  ptr = ptr->path;
		  ptr->path = NULL;
		  break;
		}//
	      else if (!strcmp(json->var, id))
		  return (ptr);
	    }
	  if (!json->next_var)
	    break;
	  json = json->next_var;
	}
      while (json->next_var)
	json = json->next_var;
      if (!(json->next_chain))
	break;
      if (!id)
	json = json->next_chain;
      else
	ptr = json = json->next_chain;
    }
  if (id && !save)
    ft_putendl_fd("echec", 2);
  ft_putendl_fd("end search_json", 2);
  return (save);//
}
/*
void write_json_1(t_json *json)
{
  t_json *njson;
  int fd;
  int cpt;

  if (!json)
    error("no json");
  cpt = -1;
  while(++cpt < 2)//on passe les 2 champs
    {
      while (json->next_var)//on vas a la fin de la liste
	json = json->next_var;
      json = json->next_chain;//on change de liste
    }
  while (1)
    {
      njson = json;//nom pointe sur json
      while(njson->next_var//on cherche l'id
	    && ft_strcmp(njson->namevar, "Id_Patient\n"))
	njson = njson->next_var;
      if (!njson->next_var)//si on la pas trouver on sort de la boucle (2 fichier de fin)
	break;
      ft_putstr_fd("create file : ", 2);
      ft_putendl_fd(njson->var, 2);
      unlink(njson->var);//on detruit un eventuel fichier existant au paravant
      fd = open(njson->var, O_CREAT | O_RDWR);//on cree le fichier
      write_elem_json(json, fd);
      close(fd);
      while (json->next_var)
	json = json->next_var;
      if (!(json->next_chain))
	break;
      json = json->next_chain;
      write(fd, "\0", 1);
    }
  ft_putendl_fd("end wr_js", 2);
}
*/
void write_elem_json(t_json *json, int fd)
{
  ft_putendl_fd("write_elem_json", 2);
  while (1)
    {
     if (!json->namevar)
	break;
     if (!json->namevar[0])
	error("no namevar");
      if (!json->var || !json->var[0])
	error("no var");
      ft_putstr_fd(json->namevar, fd);//pourquoi str et non endl ?
      ft_putstr_fd(json->var, fd);//parce qu'il y a deja un \n
      if (!json->next_var)
	break;
      json = json->next_var;
    }
  write(fd, "\0", 1);
}

void write_path_json(t_json *json, int fd)
{
  t_json *ptr;

  while (1)
    {
      ft_putstr_fd(json->var, fd);
      if (!json->path)
	break;
      ptr = json;
      json = json->path;
      ptr->path = NULL;
    }
  write(fd, "\0", 1);
}


void write_json(t_json *json)//json//liste sur les datas
{
  t_json *njson;//liste sur les ids
  t_json *sjson;//sauvegarde

  int fd;
  char *filename;
  int cpt;

  signal(SIGUSR1, ft_wait);
  ft_putendl_fd("wr_js_2 en attente de signal", 2);
  //  pause();
  ft_putendl_fd("signal recu sur wr_js_2", 2);
  
  sjson = json;//sauvegarde du json
  //strcmp
  njson = search_json(json, "Id_Patient\n", NULL);//recherche des ids
  cpt = -1;
  while(++cpt < 2)//on passe les 2 premiers champs
    {
      while (json->next_var)// on vas a la fin de la liste
	json = json->next_var;
      json = json->next_chain;//pour aller a la liste suivante
    }
  while (1)
  {
    filename = ft_strnew(njson->var);//on recupere le nom 
    filename[ft_strlen(njson->var) - 1] = '\0';//on l'adapte (\n, \0);

    ft_putstr_fd("create file :", 2);
    ft_putstr_fd(filename, 2);
    ft_putendl_fd(":", 2);

    unlink(njson->var);//on detruit un eventuel fichier existant au paravant    
    fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU);//creation du fichier
    write_elem_json(json, fd);//ecriture du fichier
    close(fd);

    if (!(njson->path))//si plus de suite dans le chemin des noms
      {
	ft_putendl_fd("path : ", 2);
	break;//on sort de la boucle
      }
    while (json->next_var)//on vas a la fin du champ
      json = json->next_var;
    if (!json->next_chain)//si plus d'autre champ
      {
	ft_putendl_fd("chain : ", 2);
	break;//on sort de la boucle
      }
    json = json->next_chain;//on passe sur l'autre champ
    njson = njson->path;//on passe a l'autre nom
    free(filename);
  }
}
