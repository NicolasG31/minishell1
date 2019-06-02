/*
** sig_handlers.c for minishell in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Sun Mar 20 12:32:44 2016 
** Last update Sun Mar 20 17:28:07 2016 
*/

#include "minishell.h"

int	find_builtin2(char *str, char **tab, t_data *data)
{
  if (matches_with(tab[0], "exit()") || matches_with(tab[0], "exit"))
    {
      my_exit(str, tab, data);
      return (1);
    }
  else if (matches_with(tab[0], "cd"))
    {
      if (count_word(str) > 2)
	my_putstr("Too many arguments.\n");
      else
	my_cd(str, tab, data);
      return (1);
    }
  return (0);
}

void	ctrlc_hand()
{
  my_putstr("\n$> ");
}

void	ctrlz_hand()
{
  my_putstr("\n$> ");
}
