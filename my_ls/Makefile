##
## ETNA PROJECT, 05/10/2019 by zhou_p
## Makefile
## File description:
##		project_description
##

CFLAGS = -Wall -Wextra -Werror
SRCA = lib/libmy.a
SRC = 	\
		my_ls.c\
		src/read_av.c\
		src/my_options.c\
		src/my_path.c\
		src/file.c\
		src/content.c\
		src/my_strupcase.c\
		src/display.c\
		src/sort_content.c\
		src/swap.c\
		src/displayoptions.c\
		src/display_list.c\
		src/my_nbrlen.c\
		src/free.c\
		src/condition_opt.c\
		src/error.c\

NAME = my_ls
CC = gcc
RM = /bin/rm -rf
OBJ	= $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(SRCA) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
