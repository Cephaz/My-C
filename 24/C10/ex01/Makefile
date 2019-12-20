SRC = ft_cat.c

NAME = ft_cat

RM = /bin/rm -f

all: $(NAME)

$(NAME): 
	gcc -Wall -Wextra -Werror -c ft_cat.c
	gcc -o $(NAME) ft_cat.o

clean:
	$(RM) ft_cat.o

fclean: clean
	$(RM) $(NAME)
