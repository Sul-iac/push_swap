NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f
SRC = main.c check_errors.c init_a_to_b.c init_b_to_a.c push.c rev_rotate.c rotate.c \
sort_stacks.c sort_three.c stack_init.c stack_utils.c swap.c

OBJ = $(SRC:.c=.o)

.c.o: 
	$(CC) $(FLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(FRAMEWORK) -o $(NAME)

all:
	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
