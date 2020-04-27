##
## ETNA PROJECT, 16/03/2020 by zhou_p
## Makefile
## File description:
##		project_description
##


SRC = 	\
		main.c\
		src/my_putchar.c\
		src/my_putnbr.c\
		src/my_putnbrbase.c\
		src/my_putnbrunsigned.c\
		src/my_putstr.c\
		src/my_strcmp.c\
		src/my_strlen.c\
		src/my_printf.c\
		src/my_base.c\
		src/my_putfloat.c\
		src/my_putde.c\
		src/my_bases.c\
		src/my_arrondi.c\
		src/my_check.c

HEADER = ./include/
CC = gcc
RM = /bin/rm -rf
OBJ	= $(SRC:.c=.o)
CFLAGS = -fPIC -W $(CFLAGI) -g -I.
CFLAG = -shared
CFLAGI = -Wall -Wextra -Werror
STATIC = libmy_printf_`uname -m`-`uname -s`.a
DYNAMIC = libmy_printf_`uname -m`-`uname -s`.so
NSTATIC = my_printf_static
NDYNAMIC = my_printf_dynamic

make: all $(NSTATIC) $(NDYNAMIC)

all: $(NDYNAMIC) $(NSTATIC)

.c.o:
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NSTATIC):	$(OBJ)
	ar r $(STATIC) $(OBJ)

$(NDYNAMIC):	$(OBJ)
	$(CC) $(CFLAGS) $(CFLAG) -o $(DYNAMIC) $(SRC)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(STATIC) $(DYNAMIC)

re : fclean all

.PHONY:  all clean fclean re make
