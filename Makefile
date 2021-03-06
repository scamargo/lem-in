CC = gcc
NAME = lem-in
SRCS = main.c parse_room_list.c parse_tubes.c lem_helper.c found_another_path.c \
	   room.c start_simulation.c
LIB = libft/libft.a
FLAGS = -Wextra -Werror -Wall
INC = libft/includes

all:
	cd libft && make && cd ..
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -L. $(LIB) -I $(INC)
	
test:
	$(CC) -o $(NAME) $(SRCS) -L. $(LIB) -I $(INC)

fclean:
	rm -f $(NAME)

clean:
	rm -f $(NAME)

re:
	fclean all

