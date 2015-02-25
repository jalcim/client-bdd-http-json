#include "libft.h"
#include "../libsock/ft_inet.h"

char *ft_read_chain(int fd, char c)
{
  t_read *chain;
  t_read *start;
  t_read *fr;
  t_read *save;
  char *ret;
  int cpt;

  chain = (t_read *)malloc(sizeof(t_read));
  start = chain;
  start->size = 1;
  goto la;
  while (chain->c != c && chain->c)
    {
    la:
      save = chain;
      chain->next = (t_read *)malloc(sizeof(t_read));
      chain = chain->next;
      if (read(fd, &chain->c, 1) <= 0)
	{
	  if (!save->c)
	    return (NULL);
	  else
	      break;
	}
      chain->next = NULL;
      start->size++;
    }
  chain->next = NULL;
  fr = chain = start;
  ret = (char *)malloc(chain->size);
  cpt = -1;
  while (chain->next)
    {
      chain = chain->next;
      free(fr);
      fr = chain;
      ret[++cpt] = chain->c;
    }
  ret[++cpt] = '\0';
  return (ret);
}
