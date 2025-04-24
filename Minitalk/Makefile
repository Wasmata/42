CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# Directories
SRCDIR		= srcs
INCDIR		= includes
OBJDIR		= obj
LIBFTDIR	= $(INCDIR)/libft
PRINTF_DIR	= $(INCDIR)/ft_printf

# Files
CLIENT		= client
SERVER		= server

CLIENT_SRC	= $(SRCDIR)/client.c
SERVER_SRC	= $(SRCDIR)/server.c
LIBFT_SRC	= $(wildcard $(LIBFTDIR)/*.c)
PRINTF_SRC	= $(wildcard $(PRINTF_DIR)/*.c)

CLIENT_OBJ	= $(OBJDIR)/client.o
SERVER_OBJ	= $(OBJDIR)/server.o
LIBFT_OBJ	= $(patsubst $(LIBFTDIR)/%.c, $(OBJDIR)/%.libft.o, $(LIBFT_SRC))
PRINTF_OBJ	= $(patsubst $(PRINTF_DIR)/%.c, $(OBJDIR)/%.printf.o, $(PRINTF_SRC))

ALL_OBJ		= $(CLIENT_OBJ) $(SERVER_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ)

# Rules
all: $(CLIENT) $(SERVER)

# Compilation
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/%.libft.o: $(LIBFTDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/%.printf.o: $(PRINTF_DIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Linking
$(CLIENT): $(CLIENT_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(SERVER_OBJ) $(LIBFT_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Cleaning
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re