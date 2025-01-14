NAME = parsing

CC = cc
CFLAGS = -Wall -Wextra -Werror 
OBJ_DIR = obj
LIB = libft.a
SRC_ST = struct


SRC = main.c \
	parsing.c \
	$(SRC_ST)/lst_env.c \
	$(SRC_ST)/m_shell.c \

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re


