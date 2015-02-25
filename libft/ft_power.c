int ft_power(int nb, int power)
{
  if (power)
    return (nb * ft_power(nb, power - 1));
  return (1);
}
