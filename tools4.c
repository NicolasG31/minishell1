/*
** tools4.c for minishell in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Sat Mar 19 20:59:03 2016 
** Last update Sun Mar 20 12:20:59 2016 
*/

#include "minishell.h"

int	is_number_between_par(char *str)
{
  int	i;

  i = 1;
  if (my_strlen(str) < 3)
    return (0);
  if (str[0] != '(')
    return (0);
  if (str[my_strlen(str) - 1] != ')')
    return (0);
  while (str[i] != ')')
    {
      if (str[i] < 48 || str[i] > 57)
	return (0);
      i++;
    }
  return (1);
}

int	len_between_par(char *str)
{
  int	i;
  int	cnt;

  i = 0;
  cnt = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '(' && str[i] != '\0')
    i++;
  while (str[i] != ')' && str[i] != '\0')
    {
      cnt++;
      i++;
    }
  return (cnt);
}

char	*str_between_par(char *str)
{
  char	*arg;
  int	i;
  int	y;

  if ((arg = malloc(sizeof(char *) * len_between_par(str))) == NULL)
    return (NULL);
  i = 0;
  y = 0;
  while (str[i] != '(')
    i++;
  i++;
  while (str[i] != ')')
    {
      arg[y] = str[i];
      y++;
      i++;
    }
  arg[y] = '\0';
  return (arg);
}

int	exit_is_correct(char *str, char **tab)
{
  int	i;

  if (count_word(str) == 1)
    {
      i = 5;
      while (str[i] != ')')
	{
	  if (str[i] < 48 || str[i] > 57)
	    return (0);
	  i++;
	}
      return (1);
    }
  else if (count_word(str) == 2)
    {
      if (is_number_between_par(tab[1]))
	return (2);
      else if (is_nbr(tab[1]))
	return (3);
      else
	return (0);
    }
  else
    return (0);
}

int	free_env(char **env)
{
  int	i;

  i = 0;
  if (env == NULL)
    return (0);
  while (env[i])
    {
      free(env[i]);
      i++;
    }
  if (env != NULL)
    free(env);
  return (1);
}
