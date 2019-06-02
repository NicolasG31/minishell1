/*
** my_str_to_wordtab.c for minishell1 in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Sat Mar 12 15:18:36 2016 
** Last update Sun Mar 20 17:58:26 2016 
*/

#include "minishell.h"

int	count_word2(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ':' && str[i + 1] != '\0')
	n++;
      i++;
    }
  return (n);
}

int	cnt_char2(char *str)
{
  int	c;

  c = 0;
  while ((str[c] != ':') && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c += 1;
  return (c);
}

char	**my_str_to_wordtab2(char *str)
{
  char	**tab;
  int	i;
  int	b;
  int	a;

  init_cnts(&i, &b, &a);
  if ((tab = malloc(sizeof(*tab) * ((count_word2(str) + 1)))) == NULL)
    return (NULL);
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ':' || str[i] == '\n')
	{
	  while (str[i] == ':')
	    i++;
	  a = a + 1;
	  b = 0;
	}
      if ((tab[a] = malloc(sizeof(**tab) * ((cnt_char2(str + i) + 1)))) == NULL)
	return (0);
      while ((str[i] != ':')  && (str[i] != '\n') && (str[i] != '\0'))
	tab[a][b++] = str[i++];
      tab[a][b] = '\0';
    }
  tab[a + 1] = 0;
  return (tab);
}
