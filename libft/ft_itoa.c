#include <stdlib.h>

int ft_power(int nb, int power);
int ft_int_len(int nb);

char *ft_itoa(int n)
{
  int i;
  int op;
  int min;
  char *str;

  i = 0;
  op = 10;
  min = 0;
  str = (char *)malloc(sizeof(*str) * 12);
  if (n < 0)
    {
      n += (n == -2147483648 && ++min) ? 1 : 0;
      n = -n;
      str[i++] = '-';
    }
  op = ft_power(op, ft_int_len(n) - 1);
  while (op)
    {
      n += (!(op / 10) && min) ? 1 : 0;
      str[i++] = n / op % 10 + 48;
      n %= op;
      op /= 10;
    }
  str[i] = '\0';
  return (str);
}
