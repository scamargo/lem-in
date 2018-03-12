CC = gcc
NAME = lem-in
SRCS = main.c
LIB = libft/libft.a
FLAGS = -Wextra -Werror -Wall
INC = libft/includes

all:
	cd libft && make && cd ..
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -L. $(LIB) -I $(INC)
	
test:
	$(CC) -o $(NAME) $(SRCS) -L. $(LIB) -I $(INC)
