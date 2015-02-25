void ft_putnbr_fd(int nb, int fd);
void ft_putchar_fd(char c, int fd);

void ft_putnbr_fd(int nb, int fd)
{
  if (nb < 0)
    {
      nb = -nb;
      ft_putchar_fd('-', fd);
    }
  if (nb > 9)
    ft_putnbr_fd(nb / 10, fd);
  ft_putchar_fd(nb % 10 + 48, fd);
}
