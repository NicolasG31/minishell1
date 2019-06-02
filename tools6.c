/*
** tools6.c for minishell in /home/guillo_w/minishell1/PSU_2015_minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Sun Mar 20 23:41:03 2016 
** Last update Sun Mar 20 23:45:52 2016 
*/

#include "minishell.h"

int	my_local_exec(char *str, t_data *data)
{
  char	path[200];
  char	**tab;
  pid_t	pid;
  pid_t	chd;
  int	status;

  tab = my_str_to_wordtab(str);
  chd = fork();
  if (chd == 0)
    {
      if (execve(my_strcat(getcwd(path, 200), str), tab, data->env) == -1)
	{
	  my_putstr("File not found\n");
	  return (0);
	}
    }
  else
    {
      pid = wait(&status);
      while (pid != chd);
    }
  (status == 11) ? (my_putstr("Segmentation fault\n")):(0);
  (status == 8) ? (my_putstr("Floating point exception\n")) : (0);
  return (0);
}
