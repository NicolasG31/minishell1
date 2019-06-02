/*
** tools2.c for minishell1 in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Wed Mar 16 09:21:51 2016 
** Last update Sun Mar 20 17:05:19 2016 
*/

#include "minishell.h"

char	**copy_env2(char **env, char **src)
{
  int	i;
  int	y;

  y = 0;
  while (src[y])
    {
      i = 0;
      while (src[y][i])
	{
	  env[y][i] = src[y][i];
	  i++;
	}
      y++;
    }
  return (env);
}

char	**copy_env(char **src)
{
  int	i;
  int	len;
  int	lines;
  char	**env;

  lines = 0;
  len = my_strlen(src[0]);
  while (src[lines])
    {
      if (my_strlen(src[lines]) > len)
	len = my_strlen(src[lines]);
      lines++;
    }
  i = 0;
  if ((env = malloc(sizeof(char *) * (lines + 1))) == NULL)
    return (NULL);
  while (i != lines)
    {
      if ((env[i] = malloc(sizeof(char) * (len))) == NULL)
	return (NULL);
      i++;
    }
  return (copy_env2(env, src));
}

char	*remove_forw_spaces(char *str)
{
  int	i;

  i = 0;
  if (str[i] != ' ')
    return (str);
  else
    {
      while (str[i] == ' ')
	i++;
    }
  return (&str[i]);
}

int	matches_with(char *str, char *fnc)
{
  int	i;

  i = 0;
  while (fnc[i] != '(' && str[i] != '(' && str[i] != '\0' && fnc[i] != '\0'\
	 && fnc[i] != ' ' && str[i] != ' ')
    {
      if (str[i] != fnc[i])
	return (0);
      i++;
      if (str[i] != fnc[i])
	return (0);
    }
  if (str[my_strlen(fnc) - 1] == fnc[my_strlen(fnc) - 1])
    return (1);
}

char	*my_revstr(char *str)
{
  int	a;
  int	b;
  char	y;

  a = 0;
  b = my_strlen(str) - 1;
  while (a < b)
    {
      y = str[b];
      str[b] = str[a];
      str[a] = y;
      a = a + 1;
      b = b - 1;
    }
  return (str);
}
