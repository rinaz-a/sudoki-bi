##
## Makefile for Makefile in /home/rinaz_a/rendu/PSU_2015_my_select
## 
## Made by selim rinaz
## Login   <rinaz_a@epitech.net>
## 
## Started on  Fri Dec  4 16:34:29 2015 selim rinaz
## Last update Fri Feb 26 18:17:15 2016 rouill_d
##

CC	= gcc -g

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
#CFLAGS	+=-ansi -pedantic
CFLAGS	+= -I.

NAME	= sudoki-bi

SRCS	= sudoki-bi.c		\
	  get_next_line.c

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
