#include "object.h"

t_object *init()
{
  t_object *object;

  init_bdd();
  object = (t_object *)malloc(sizeof(t_object));
  object->infolog = init_client();
  object->request_server = ft_request;
  object->request_bdd = request_bdd;
  object->destruct = destruct;
  return (object);
}

void destruct(t_object *object)
{
  int *pid;

  //  ft_request(NULL, -1, NULL);
  //  dez_pipe(NULL, NULL);
  //  free(object);

  close_client(object->infolog);
  close(ft_write_req_pipe(-1));
  close(ft_read_req_pipe(-1));
  pid = ft_recup_pid(NULL);
  kill(pid[0], SIGINT);
  free(pid);
}

int main()
{
  t_object *object;
  char str[100];

  chdir("/Users/Lysoft/Desktop/chantier/");

  //lancement des processur initialisation de l'objet et de ses methodes/structures
  m_object_init;//constructeur object

  /*
  //mise a jour des tab_id
  object->id = m_object_request_bdd_id(" ");//demande a la bdd des ids client
  if (object->id)
    {
      write_elem_json(object->id, 2);

      //extraction sans mise a jour
      ft_putendl_fd("extract OBJECT", 2);
      scanf("%s", str);
      object->json = m_object_request_bdd_extract(str);//demande d'un fichier a la bdd
      write_elem_json(object->json, 2);

      //destruction sans mise a jour
      ft_putendl_fd("del OBJECT", 2);
      scanf("%s", str);
      m_object_request_bdd_del(str);//destruction d'un fichier dans la bdd
    }
  */
  //mise a jour de la bdd (connection serveur/requette http/post)
  ft_putendl_fd("MISE A JOUR DE LA BDD", 2);
  m_object_request_server(2);//requette au serveur (2)==(reception json)
  m_object_request_bdd_send(" ");//envoi a la bdd de json

  //mise a jour des tab_id
  ft_putendl_fd("id OBJECT", 2);
  object->id = m_object_request_bdd_id(" ");//demande a la bdd des ids client
  write_elem_json(object->id, 2);//ecriture sur la sortie d'erreur

  //synchronisation
  m_object_request_server(2);//requette au serveur (2)==(reception json) 
  m_object_request_bdd_send(" ");//envoi a la bdd de json

  //mise a jour des tab_id
  object->id = m_object_request_bdd_id(" ");//demande a la bdd des ids client
  write_elem_json(object->id, 2);

  ft_putendl_fd("extract OBJECT", 2);
  scanf("%s", str);
  object->json = m_object_request_bdd_extract(str);//demande d'un fichier a la bdd
  write_elem_json(object->json, 2);

  ft_putendl_fd("del OBJECT", 2);
  scanf("%s", str);
  m_object_request_bdd_del(str);//destruction d'un fichier dans la bdd

  ft_putendl_fd("end", 2);
  m_object_destruct;
  return (0);
}
