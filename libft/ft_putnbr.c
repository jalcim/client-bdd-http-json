void ft_putchar(char c);

void ft_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      ft_putchar('-');
    }
  if (nb > 9)
    ft_putnbr(nb / 10);
  ft_putchar(nb % 10 + 48);
}
