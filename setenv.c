/*
** setenv.c for minishell1 in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Thu Mar 17 16:01:26 2016 
** Last update Sun Mar 20 17:10:48 2016 
*/

#include "minishell.h"

char	**replace_env2(char *str, char **env, char **src, int ind)
{
  int	i;
  int	y;
  char	**tab;

  tab = my_str_to_wordtab(str);
  y = 0;
  while (src[y])
    {
      i = 0;
      while (src[y][i])
	{
	  env[y][i] = src[y][i];
	  i++;
	}
      if (y == ind)
	{
	  if (count_word(str) == 2)
	    env[y] = my_strcat(before_equal(env[y]), "\0");
	  else if (count_word(str) == 3)
	    env[y] = my_strcat(before_equal(env[y]), tab[2]);
	}
      free(src[y]);
      y++;
    }
  return (env);
}

char	**replace_env(char *str, char **src, int ind)
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
      env[i] = malloc(sizeof(char) * (len));
      if (i == ind)
	if ((env[i] = malloc(sizeof(char) * (len) + my_strlen(str))) == NULL)
	  return (NULL);
      i++;
    }
  return (replace_env2(str, env, src, ind));
}

int	does_exist(char *str, char **src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      if (env_matches(str, src[i]))
	return (i);
      i++;
    }
  return (-1);
}

char	**copy_set_env2(char *str, char **tab, char **env, char **src)
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
      free(src[y]);
      y++;
    }
  if (count_word(str) == 2)
    env[y] = my_strcat(env[y], my_strcat(tab[1], "="));
  else if (count_word(str) == 3)
    env[y] = my_strcat(env[y], my_strcat(my_strcat(tab[1], "="), tab[2]));
  return (env);
}

char	**copy_set_env(char *str, char **tab, char **src)
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
  if ((env = malloc(sizeof(char *) * (lines + 2))) == NULL)
    return (NULL);
  while (i != lines + 1)
    {
      if ((env[i] = malloc(sizeof(char) * (len))) == NULL)
	return (NULL);
      i++;
    }
  return (copy_set_env2(str, tab, env, src));
}

