int ft_int_len(int nb)
{
  if (nb < 0)
    return (1 + ft_int_len(nb / 10));
  if (nb > 9)
    return (1 + ft_int_len(nb / 10));
  return (1);
}
