##
## ETNA PROJECT, 05/10/2019 by zhou_p
## Makefile
## File description:
##		project_description
##

CFLAGS = -Wall -Wextra -Werror
SRC = mainn.c
CC = gcc
RM = /bin/rm -rf
NAME = EXEC

all : $(NAME) lance

lance:
	./my_crd < commands.lst

$(NAME):
	$(CC) $(SRC) -L lib/ -lmy -o my_crd

clean :
	$(RM) my_crd

fclean : clean
	$(RM) my_crd

re : fclean all
