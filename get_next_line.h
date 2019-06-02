/*
** get_next_line.h for getnextline in /home/Sinjide/getnextline
** 
** Made by Nicolas Guillon
** Login   <Sinjide@epitech.net>
** 
** Started on  Tue Jan  5 16:30:04 2016 Nicolas Guillon
** Last update Wed Mar 16 11:02:35 2016 
*/

#include "minishell.h"

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

char	*get_next_line(const int fd);
int	my_strlen(char *str);
char	*my_strcat(char *dest, char *src);
int	found_backslash(char *buff, char *str);
char	*malloc_and_ret(char *str);

#endif /* !GET_NEXT_LINE_H_ */
