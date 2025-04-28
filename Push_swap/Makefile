NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCDIRS = src utils
INCLUDES = -Iincludes

SRC = main.c $(wildcard $(addsuffix /*.c, $(SRCDIRS)))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
