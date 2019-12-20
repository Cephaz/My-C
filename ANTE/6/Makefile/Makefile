##
## ETNA PROJECT, 05/10/2019 by zhou_p
## Makefile
## File description:
##		project_description
##

CFLAGS = -Wall -Wextra -Werror
SRC = ./lib/my/my_putchar.c  ./lib/my/my_putstr.c ./lib/my/my_strlen.c \
	./lib/my/my_getnbr.c ./lib/my/my_putnbr.c ./lib/my/my_isneg.c \
	./lib/my/my_swap.c ./lib/my/my_strcpy.c ./lib/my/my_strncpy.c \
	./lib/my/my_strcmp.c ./lib/my/my_strncmp.c ./lib/my/my_strcat.c \
	./lib/my/my_strncat.c ./lib/my/my_strstr.c ./lib/my/my_strdup.c
NAME = ./lib/libmy.a
HEADER = ../include/
OBJ = $(SRC:.c=.o)
CC = gcc
RM = /bin/rm -rf
FILE = ../lib/ ../include/
FILEE = ./lib/ ./include/

all : copy $(NAME)

copy:
	cp -r $(FILE) .

.c.o:
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean :
	$(RM) $(FILEE)

fclean : clean
	$(RM) $(NAME) $(OBJ)

re : fclean all
