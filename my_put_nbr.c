/*
** my_put_nbr.c for my_put_nbr in /home/Sinjide/rendu/day6
** 
** Made by Nicolas Guillon
** Login   <Sinjide@epitech.net>
** 
** Started on  Tue Oct  6 14:04:33 2015 Nicolas Guillon
** Last update Tue Mar  8 09:32:38 2016 
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -1 * nb;
      my_putchar('-');
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + 48);
  return (nb);
}
