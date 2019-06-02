/*
** tools3.c for minishell in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Wed Mar 16 18:56:41 2016 
** Last update Sat Mar 19 19:18:06 2016 
*/

#include "minishell.h"

int	set_env_correct(char *str)
{
  int	i;

  i = 1;
  if ((str[0] < 65 || str[0] > 90) && (str[0] < 97 || str[0] > 122))
    {
      my_putstr("First character must be a letter.\n");
      return (0);
    }
  while (str[i])
    {
      if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122)\
	  && (str[i] > 57 || str[i] < 48))
	{
	  my_putstr("Must contain only alphanumeric characters.\n");
	  return (0);
	}
      i++;
    }
  return (1);
}

int	env_matches(char *str, char *env)
{
  int	i;

  i = 0;
  while ((str[i] != '=' || env[i] != '=') && str[i] != '\0' && env[i] != '\0')
    {
      if (str[i] != env[i])
	return (0);
      i++;
    }
  return (1);
}

void	remove_line(t_data *data, int ind)
{
  int	i;

  i = 0;
  while (data->env[ind + i + 1])
    {
      data->env[ind + i] = data->env[ind + i + 1];
      i++;
    }
  data->env[ind + i] = 0;
}

char	*before_equal(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '=' && str[i] != '\0')
    i++;
  str[i + 1] = '\0';
  return (str);
}

char	*before_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  str[i] = '\0';
  return (str);
}
