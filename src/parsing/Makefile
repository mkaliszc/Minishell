NAME = parsing

CC = cc
CFLAGS = -Wall -Wextra -Werror 
OBJ_DIR = obj
LIB = libft.a
SRC_ST = struct
SRC_CMD = $(SRC_ST)/lst_cmd
SRC_ENV = $(SRC_ST)/lst_env
SRC_MS = $(SRC_ST)/m_shell
SRC_OF = $(SRC_ST)/order_file
SRC_RD = redir
SRC_UT = utils
SRC_LN = line
SRC_TC = table_char
SRC_Q = quote_parse
SRC_V = var_env

SRC = main.c \
	parsing.c \
	$(SRC_ENV)/c_lst_env.c \
	$(SRC_MS)/c_m_shell.c \
	$(SRC_UT)/utils1.c \
	$(SRC_LN)/parse_line.c \
	$(SRC_ENV)/r_lst_env.c \
	$(SRC_ENV)/u_lst_env.c \
	$(SRC_LN)/parse_err.c \
	$(SRC_LN)/parse_utils.c \
	$(SRC_LN)/to_modify.c \
	$(SRC_TC)/split_cmd.c \
	$(SRC_TC)/table_cmd.c \
	$(SRC_CMD)/c_lst_cmd.c \
	$(SRC_OF)/c_order_file.c \
	$(SRC_RD)/in_hdc.c \
	$(SRC_RD)/out_app.c \
	$(SRC_Q)/remove_quote.c \
	$(SRC_V)/get_env.c \
	$(SRC_V)/rep_q_n_v.c \

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


