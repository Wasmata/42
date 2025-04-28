NAME = fdf

# ===========================
#        COMPILATION
# ===========================

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
MLX_DIR = inc/minilibx-linux
MLX     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
INCLUDES = -Iinc -I$(MLX_DIR) -Iinc/get_next_line -Iinc/libft

# ===========================
#         SOURCES
# ===========================

SRC = srcs/main.c \
      $(filter-out srcs/main.c, $(wildcard srcs/*.c)) \
      $(wildcard inc/libft/*.c) \
      $(wildcard inc/get_next_line/*.c)

OBJ = $(SRC:.c=.o)

# ===========================
#          RULES
# ===========================

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRC) $(INCLUDES) $(MLX) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
