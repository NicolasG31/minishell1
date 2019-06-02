/*
** main.c for minishell1 in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Mon Mar 14 11:36:02 2016 
** Last update Sun Mar 20 22:43:05 2016 
*/

#include "minishell.h"

char	*find_path(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (env[i] == NULL)
	return (NULL);
      if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2]	\
	  == 'T' && env[i][3] == 'H' && env[i][4] == '=')
	return (&env[i][5]);
      i++;
    }
}

int	find_builtin(char *str, char **tab, t_data *data)
{
  if (matches_with(tab[0], "env"))
    {
      print_env(data->env);
      return (1);
    }
  else if (matches_with(tab[0], "setenv"))
    {
      my_set_env(str, tab, data);
      return (1);
    }
  else if (matches_with(tab[0], "unsetenv"))
    {
      my_unset_env(str, data);
      return (1);
    }
  else
    if (find_builtin2(str, tab, data) == 1)
      return (1);
    else
      return (0);
}

void	my_shell(char *str, t_data *data)
{
  char	*path;

  if (str[0] == '\0')
    return;
  if (find_builtin(str, my_str_to_wordtab(str), data) != 1)
    {
      if ((path = find_path(data->env)) == NULL)
	{
	  my_putstr("No PATH set.\n");
	  return;
	}
      data->path = my_str_to_wordtab2(path);
      my_exec(str, data);
    }
}

int	main(int ac, char **av, char **env)
{
  t_data	data;
  char		*str;

  data.env = copy_env(env);
  if (env == NULL)
    {
      my_putstr("Env null\n");
      exit(0);
    }
  while (42)
    {
      my_putstr("$> ");
      signal(SIGINT, ctrlc_hand);
      signal(SIGTSTP, ctrlz_hand);
      str = get_next_line(0);
      if (str == NULL)
	{
	  my_putstr("exit\n");
	  return (0);
	}
      str = remove_forw_spaces(my_revstr(str));
      my_shell(remove_forw_spaces(my_revstr(str)), &data);
    }
  return (1);
}
