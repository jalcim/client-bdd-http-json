#include <string.h>

void ft_bzero(void *src, size_t size)
{
  char *tab;
  size_t compt;

  compt = -1;
  tab = (char *)src;
  while (++compt < size)
    tab[compt] = 0;
}
