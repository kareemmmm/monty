CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

SRC = main.c execute.c stack_funcs1.c stack_funcs2.c stack_funcs3.c memory.c
OBJ = $(SRC:.c=.o)
NAME = monty

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
