/*
** minishell.h for minishell1 in /home/guillo_w/minishell1
** 
** Made by GUILLON Nicolas
** Login   <guillo_w@epitech.net>
** 
** Started on  Wed Mar  9 17:19:36 2016 
** Last update Sun Mar 20 23:46:39 2016 
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "get_next_line.h"

typedef struct	s_data
{
  char		**env;
  char		**path;
  char		*correct_path;
  char		*o_pwd;
}		t_data;

void	my_putchar(char c);
int	my_put_nbr(int nb);
void	my_putstr(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *str1, char *str2);
char	*find_path(char **env);
void	my_shell(char *str, t_data *data);
int	execute_cmd(t_data *data, char *str, int e);
int	is_prog1(char *str, t_data *data);
int	is_prog2(char *str, t_data *data);
int	is_a_prog(char *str, t_data *data, int p);
int	my_strlen(char *str);
int	first_char_slash(char *str);
int	my_exec(char *str, t_data *data);
int	count_word(char *str);
int	cnt_char(char *str);
char	**my_str_to_wordtab(char *str);
int	count_word2(char *str);
int	cnt_char2(char *str);
char	**my_str_to_wordtab2(char *str);
char	*remove_forw_spaces(char *str);
int	matches_with(char *str, char *fnc);
void	print_env(char **env);
void	my_set_env(char *str, char **tab, t_data *data);
char	**copy_env(char **src);
char	**copy_env2(char **env, char **src);
int	does_exist(char *str, char **src);
char	**copy_set_env(char *str, char **tab, char **src);
char	**copy_set_env2(char *str, char **tab, char **env, char **src);
int	env_matches(char *str, char *env);
void	remove_line(t_data *data, int ind);
void	my_unset_env(char *str, t_data *data);
char	*my_revstr(char *str);
int	my_cd(char *str, char **tab, t_data *data);
void	my_exit(char *str, char **tab, t_data *data);
char	**replace_env(char *str, char **src, int ind);
char	**replace_env2(char *str, char **env, char **src, int ind);
char	*before_equal(char *str);
int	set_env_correct(char *str);
char	*before_space(char *str);
int	free_env(char **env);
int	exit_is_correct(char *str, char **tab);
char	*str_between_par(char *str);
int	len_between_par(char *str);
int	is_nbr(char *str);
void	ctrlc_hand();
void	ctrlz_hand();
char	*find_home(char **env);
void	put_old_pwd(char *str, char **tab, t_data *data);
int	find_builtin2(char *str, char **tab, t_data *data);
void	init_cnts(int *a, int *b, int *c);
int	my_local_exec(char *str, t_data *data);

#endif /* !MINISHELL_H_ */
