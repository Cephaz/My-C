##
## ETNA PROJECT, 05/10/2019 by zhou_p
## Makefile
## File description:
##		project_description
##

CFLAGS = -Wall -Wextra -Werror
SRC = ./my/my_putchar.c  ./my/my_putstr.c ./my/my_strlen.c \
	./my/my_getnbr.c ./my/my_putnbr.c ./my/my_isneg.c \
	./my/my_swap.c ./my/my_strcpy.c ./my/my_strncpy.c \
	./my/my_strcmp.c ./my/my_strncmp.c ./my/my_strcat.c \
	./my/my_strncat.c ./my/my_strstr.c ./my/my_strdup.c \
	./my/my_readline.c
NAME = ./libmy.a
HEADER = ../include/
OBJ = $(SRC:.c=.o)
CC = gcc
RM = /bin/rm -rf

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
