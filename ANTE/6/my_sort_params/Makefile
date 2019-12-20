##
## ETNA PROJECT, 05/10/2019 by zhou_p
##	Makefile
##	File description:
##		project_description
##

CFLAGS = -Wall -Wextra -Werror
SRC = my_sort_params.c my_copy.c
NAME = my_sort_params
CC = gcc
RM = /bin/rm -f

all : $(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
		$(RM) $(NAME)

fclean : clean

re : fclean all
