#ifndef _OBJECT_
#define _OBJECT_

#include "dclient/connecttest.h"
#include "bdd/bdd.h"
#include "libsock/ft_inet.h"

#define m_object_init object=init()
#define m_object_request_server(cmd) (*object->request_server)(object->infolog, cmd, ft_ccatid(object->infolog->id, object->infolog->token))
#define m_object_request_bdd_send(filename) (*object->request_bdd)(filename, object->infolog->data->reply, 0)
#define m_object_request_bdd_extract(filename) (*object->request_bdd)(filename, NULL, 1)
#define m_object_request_bdd_id(filename) (*object->request_bdd)(filename, NULL, 3)
#define m_object_request_bdd_del(filename) (*object->request_bdd)(filename, NULL, 2)
#define m_object_destruct (*object->destruct)(object)

typedef struct s_object t_object;

struct s_object
{
  int (*request_server)(t_connectinfo *infolog, int cmd, char *id);//int ft_request(t_connectinfo *infolog, int cmd, char *id)
  t_json *(*request_bdd)(char *filename, char *str, int cmd);//void request_bdd(char *id, char *data, int cmd)
  void (*destruct)(t_object *object);

  t_json *id;
  t_json *json;
  t_connectinfo *infolog;
};

void destruct(t_object *object);
t_object *init();
int object();

#endif

/* sans define

t_object *object;

object = init();
(*object->request_server)(object->infolog, 2);
(*object->request_bdd)("filename", object->infolog->data->reply, 0);
(*object->request_bdd)("filename", NULL, 1);
(*object->destruct)(object);
*/

/* avec define

t_object *object;

m_object_init;
m_object_request_server(2);
m_object_request_bdd_send("filename");
m_object_request_bdd_extract("filename");
m_object_destruct;
*/
