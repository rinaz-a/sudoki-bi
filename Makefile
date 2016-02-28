##
## Makefile for Makefile in /home/rinaz_a/rendu/PSU_2015_my_select
## 
## Made by selim rinaz
## Login   <rinaz_a@epitech.net>
## 
## Started on  Fri Dec  4 16:34:29 2015 selim rinaz
## Last update Sun Feb 28 01:04:34 2016 
##

CC	= gcc -g

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
#CFLAGS	+=-ansi -pedantic
CFLAGS	+= -I.

NAME	= sudoki-bi

SRCS	= get_next_line.c	\
	  checks.c		\
	  my_essentials.c	\
	  sudoki-bi.c

OBJS	= $(SRCS:.c=.o)


all: 	$(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
