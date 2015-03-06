#include "bdd.h"
/*
void file_gestionnaire()
{
  
  signal(SIGUSR1, );
  while (1)
    {
      pause();
    }
}
*/
int fd_save(int *pipefd, int in_out)
{
  static int *spipe;

  if (pipefd)
    spipe = pipefd;
  else
    {
      if (in_out)
	return (spipe[1]);
      else
	return (spipe[0]);
    }
  return (0);
}
