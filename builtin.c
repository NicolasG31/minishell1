/*
** builtin.c for minishell1 in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Wed Mar 16 10:31:24 2016 
** Last update Sun Mar 20 23:36:17 2016 
*/

#include "minishell.h"

void	print_env(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      my_putstr(env[i]);
      my_putchar('\n');
      i++;
    }
}

void	my_set_env(char *str, char **tab, t_data *data)
{
  char	**new_env;

  if (count_word(str) == 1)
    print_env(data->env);
  else if (count_word(str) == 2 || count_word(str) == 3)
    {
      if (set_env_correct(tab[1]) != 1)
	  return;
      if (does_exist(tab[1], data->env) == -1)
	data->env = copy_set_env(str, tab, data->env);
      else
	data->env = replace_env(str, data->env, does_exist(tab[1], data->env));
    }
  else
    my_putstr("Too many arguments.\n");
}

int	my_cd(char *str, char **tab, t_data *data)
{
  char	*path_home;
  char	dir[200];

  if (count_word(str) == 2 && my_strcmp(tab[1], "-"))
    {
      chdir(data->o_pwd);
      return (1);
    }
  data->o_pwd = getcwd(dir, 200);
  if (count_word(str) == 2 && chdir(tab[1]) == -1)
    {
      my_putstr("Directory not found.\n");
      return (0);
    }
  else if (count_word(str) == 1)
    {
      if ((path_home = find_home(data->env)) == NULL)
	{
	  my_putstr("No HOME set.\n");
	  return (0);
	}
      chdir(path_home);
    }
  return (1);
}

void	my_exit(char *str, char **tab, t_data *data)
{
  char	*value;
  int	ret;

  if (count_word(str) == 1 && my_strcmp(str, "exit") == 1)
    {
      my_putstr("exit\n");
      exit(0);
    }
  if (exit_is_correct(str, my_str_to_wordtab(str)) == 0)
    {
      my_putstr("Wrong syntax.\n");
      return;
    }
  if (exit_is_correct(str, tab) == 1 || exit_is_correct(str, tab) == 2)
    value = str_between_par(str);
  else if (exit_is_correct(str, tab) == 3)
    value = tab[1];
  ret = my_getnbr(value);
  free(value);
  exit(ret);
}

void	my_unset_env(char *str, t_data *data)
{
  char	**tab;
  int	i;
  int	y;

  i = 1;
  tab = my_str_to_wordtab(str);
  if (my_strcmp(str, "unsetenv") && my_strlen(str) == 8)
    my_putstr("Too few argument.\n");
  else
    {
      while (i != count_word(str))
	{
	  y = 0;
	  while (data->env[y])
	    {
	      if (env_matches(tab[i], data->env[y]))
		remove_line(data, y);
	      y++;
	    }
	  i++;
	}
    }
}
