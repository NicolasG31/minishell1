##
## Makefile for my_select in /home/guillo_w/select
## 
## Made by 
## Login   <guillo_w@epitech.net>
## 
## Started on  Fri Feb 19 17:30:07 2016 
## Last update Sun Mar 20 23:45:23 2016 
##

CC	= gcc

RM	= rm -f

NAME	= mysh

LIB	= -lncurses -Wall -pedantic

SRCS	= main.c \
	  exec.c \
	  my_str_to_wordtab.c \
	  my_str_to_wordtab2.c \
	  get_next_line.c \
	  builtin.c \
	  setenv.c \
	  tools.c \
	  tools2.c \
	  tools3.c \
	  tools4.c \
	  tools5.c \
	  tools6.c \
	  sig_handlers.c


OBJ	= $(SRCS:.c=.o)

all:    $(NAME)

$(NAME): $(OBJ)
	$(CC) -g $(OBJ) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
