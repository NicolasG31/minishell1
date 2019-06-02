/*
** tools.c for raytracer in /home/guillo_w/raytracer
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Fri Mar 11 10:07:36 2016 
** Last update Sun Mar 20 17:15:40 2016 
*/

#include "minishell.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

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

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}

int	my_getnbr(char *str)
{
  int	res;
  int	cpt;
  int	tmp;
  int	neg;

  neg = 1;
  tmp = 0;
  res = 0;
  cpt = 0;
  if (str == NULL)
    return (0);
  if (str[0] == 0)
    return (-1);
  while (str[cpt])
    {
      tmp = res;
      if (str[cpt] == '-')
	neg = neg * -1;
      else if (str[cpt] >= '0' && str[cpt] <= '9')
	res = res * 10 + str[cpt] - 48;
      cpt = cpt + 1;
    }
  return ((neg < 0) ? -res : res);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' || str2[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}
