/*
** tools5.c for minishell in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Sun Mar 20 12:12:09 2016 
** Last update Sun Mar 20 18:01:01 2016 
*/

#include "minishell.h"

void	put_old_pwd(char *str, char **tab, t_data *data)
{
  return;
}

char	*find_home(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (env[i] == NULL)
	return (NULL);
      if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2]\
	  == 'M' && env[i][3] == 'E' && env[i][4] == '=')
	return (&env[i][5]);
      i++;
    }
}

int	is_nbr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 48 || str[i] > 57)
	return (0);
      i++;
    }
  return (1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	first_char_slash(char *str)
{
  int	i;

  i = 0;
  if (str[i] != ' ')
    {
      if (str[i] == '/')
	return (1);
      else
	return (0);
    }
  else
    {
      while (str[i] == ' ')
	i++;
      if (str[i] == '/')
	return (1);
      return (0);
    }
}
