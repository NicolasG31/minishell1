/*
** main.c for my_exec in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Tue Mar  8 09:13:39 2016 
** Last update Sun Mar 20 23:47:55 2016 
*/

#include "minishell.h"

int	execute_cmd(t_data *data, char *str, int e)
{
  pid_t	chd;
  pid_t	pid;
  int	status;
  char **tab;

  tab = my_str_to_wordtab(str);
  chd = fork();
  if (chd == 0 && e == 1)
    {
      if (execve(before_space(str), tab, data->env) == -1)
	return (1);
    }
  else if (chd == 0 && e == 0)
    {
      if (execve(data->correct_path, tab, data->env) == -1)
	return (1);
    }
  else
    {
      pid = wait(&status);
      while (pid != chd);
    }
  (status == 11) ? (my_putstr("Segmentation fault\n")) : (0);
  (status == 8) ? (my_putstr("Floating point exception\n")) : (0);
  return (0);
}

int	is_prog1(char *str, t_data *data)
{
  int	i;
  char	**tab;

  tab = my_str_to_wordtab(str);
  i = 0;
  while (data->path[i])
    {
      if (access(my_strcat(my_strcat(data->path[i], "/"), tab[0]), X_OK) == 0)
	{
	  data->correct_path = data->path[i];
	  return (1);
	}
      i++;
    }
  return (0);
}

int	is_prog2(char *str, t_data *data)
{
  int	i;
  char	**tab;

  tab = my_str_to_wordtab(str);
  i = 0;
  while (data->path[i])
    {
      if (access(tab[0], X_OK) == 0)
	{
	  return (1);
	}
      i++;
    }
  return (0);
}

int	is_a_prog(char *str, t_data *data, int p)
{
  int	i;

  i = 0;
  if (p == 0)
    {
      if (is_prog1(str, data) == 0)
	{
	  my_putstr(str);
	  my_putstr(" is not a valid command.\n");
	  return (0);
	}
    }
  else if (p == 1)
    {
      if (is_prog2(str, data) == 0)
	{
	  my_putstr(str);
	  my_putstr(" is not a valid command.\n");
	  return (0);
	}
    }
  return (1);
}

int	my_exec(char *str, t_data *data)
{
  char	**tab;
  int	i;

  i = 0;
  tab = my_str_to_wordtab(str);
  if (my_strlen(str) > 2)
    if (str[0] == '.' && str[1] == '/')
      {
	my_local_exec(&str[1], data);
	return (0);
      }
  if (is_a_prog(str, data, first_char_slash(str)) != 1)
    return (0);
  execute_cmd(data, str, first_char_slash(str));
  return (1);
}
