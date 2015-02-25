#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char **ft_strsplit(char *string, char c)
{
  int cpt[2];
  char **dbstring;

  cpt[0] = -1;
  cpt[1] = 1;
  while (string[++cpt[0]])
    (string[cpt[0]] == c ? cpt[1]++ : 0);
  dbstring = (char **)malloc((cpt[1] + 1) * sizeof(char*));
  cpt[1] = cpt[0] = -1;
  while (string[++cpt[0]])
    {
      dbstring[++cpt[1]] = &string[cpt[0]];
      while(string[++cpt[0]] && string[cpt[0]] != c);
      if (string[cpt[0]] && string[cpt[0]] == c)
	string[cpt[0]] = (char) 0;
      else if(!string[cpt[0]])
	break;
    }
  dbstring[++cpt[1]] = NULL;
  return (dbstring);
}
