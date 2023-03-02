##
## EPITECH PROJECT, 2023
## DANTE
## File description:
## Makefile for Dante lib
##

SRC = array.c \
	my_putchar.c \
	my_putstr.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
