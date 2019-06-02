/*
** main.c for getnextline in /home/Sinjide/getnextline
** 
** Made by Nicolas Guillon
** Login   <Sinjide@epitech.net>
** 
** Started on  Tue Jan  5 16:27:58 2016 Nicolas Guillon
** Last update Sun Mar 20 18:00:05 2016 
*/

#include "get_next_line.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i = i + 1;
  while (src[j] != '\0')
    {
      dest[i + j] = src[j];
      j = j + 1;
    }
  dest[i + j] = '\0';
  return (dest);
}

char	*malloc_and_ret(char *str)
{
  char	*save;
  int	i;

  i = 0;
  if ((save = malloc(sizeof(char) * my_strlen(str) + READ_SIZE + 1)) == NULL)
    return (NULL);
  while (i <= READ_SIZE)
    {
      save[i] = '\0';
      i++;
    }
  my_strcat(save, str);
  free(str);
  return (save);
}

int	found_backslash(char *buff, char *str)
{
  int	i;

  i = 0;
  buff[i] = '\0';
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  str[i] = '\0';
	  my_strcat(buff, &str[i + 1]);
	  return (1);
	}
      i++;
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE];
  char		*str;
  int		i;

  i = READ_SIZE;
  if ((str = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  str[0] = '\0';
  my_strcat(str, buff);
   while (i >= 0)
    {
      buff[i] = '\0';
      i--;
    }
  while ((found_backslash(buff, str)) == 0)
    {
      if (read(fd, buff, READ_SIZE) <= 0)
	return (NULL);
      if ((str = malloc_and_ret(str)) == NULL)
	return (NULL);
      my_strcat(str, buff);
    }
  return (str);
}
