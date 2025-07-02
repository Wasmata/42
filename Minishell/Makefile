# Définir les couleurs
RESET = \033[0m
BOLD = \033[1m
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[97m

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INC_DIR = includes
UTILS_DIR = utils
SRC_DIR = src
LIBFT_DIR = utils/Libft

# Fichiers sources et objets
SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Nom du programme
NAME = minishell

# Inclusions
INCS = -I$(INC_DIR) -I$(LIBFT_DIR)

# Librairies
LIBS = -L$(LIBFT_DIR) -lft

# Messages de début et fin de compilation
define start_message
	@echo "$(CYAN)Compiling $(BOLD)$(NAME)$(RESET)..."
	@echo ""
endef

define end_message
	@echo ""
	@echo "$(GREEN)Compilation $(BOLD)$(NAME)$(RESET) $(GREEN)terminée avec succès !$(RESET)"
	@echo ""
endef

# Message de nettoyage
define clean_message
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
endef

# Message de nettoyage complet
define fclean_message
	@echo "$(RED)Cleaning all files...$(RESET)"
endef

# Affichage stylé du nom "minishell"
define display_name
	@echo "$(MAGENTA)$(BOLD)  M   M  III  N   N III SSSS  H   H  EEEEE  L      L     $(RESET)"
	@echo "$(MAGENTA)$(BOLD)  MM MM   I   NN  N  I  S     H   H  E      L      L     $(RESET)"
	@echo "$(MAGENTA)$(BOLD)  M M M   I   N N N  I  SSS   HHHHH  EEEE   L      L     $(RESET)"
	@echo "$(MAGENTA)$(BOLD)  M   M   I   N  NN  I     S  H   H  E      L      L     $(RESET)"
	@echo "$(MAGENTA)$(BOLD)  M   M  III  N   N III SSSS  H   H  EEEEE  LLLLL  LLLLL$(RESET)"
endef

# Cible par défaut : Compilation de libft et de minishell
all: $(LIBFT_DIR)/libft.a $(NAME)

# Compilation de la libft
$(LIBFT_DIR)/libft.a:
	@echo "$(MAGENTA)Compiling libft...$(RESET)"
	@make -s -C $(LIBFT_DIR)

# Compilation du binaire minishell
$(NAME): $(OBJS)
	$(call display_name)
	$(call start_message)
	$(call progress_bar)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) -lreadline
	$(call end_message)

# Règle pour créer les objets .o à partir des fichiers .c
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

# Nettoyage des objets intermédiaires
clean:
	$(call clean_message)
	@rm -f $(OBJS)
	@make -s -C $(LIBFT_DIR) clean

# Nettoyage complet (objets + binaire)
fclean: clean
	$(call fclean_message)
	@rm -f $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

# Recompilation complète
re: fclean all

# Cibles à ne pas confondre avec des fichiers
.PHONY: all clean fclean re
