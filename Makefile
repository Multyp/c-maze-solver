##
## EPITECH PROJECT, 2023
## DANTE
## File description:
## Solver Makefile
##

CC = gcc

CPPFLAGS = -Iincludes

CFLAGS = -Wall -Wextra -pedantic -g3

SRC = src/main.c \
	src/graph_create.c \
	src/graph_setup.c \
	src/graph_error.c \
	src/graph_utils.c \
	src/queue_funcs.c \
	src/brute_force.c

OBJ = $(SRC:.c=.o)

NAME = solver

LIB_NAME = ./lib/my/libmy.a

all: $(OBJ)
	cd ./lib/my && make
	$(CC) $(OBJ) $(LIB_NAME) $(CPPFLAGS) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	cd ./lib/my && make clean

fclean: clean
	rm -f $(NAME)
	cd ./lib/my && make fclean

re: fclean all
	cd ./lib/my && make re

.PHONY : all clean fclean re
