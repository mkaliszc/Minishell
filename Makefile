NAME	=	minishell

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE	=	-I includes -I libft
CLONE	=	git clone
RM		=	rm -f

LIB		=	libft
LIBFT	=	$(LIB)/libft.a

SRC		=	src/builtins/cd.c 						\
			src/builtins/pwd.c 						\
			src/exec/main.c						\
			src/exec/exec_utils.c						\
			src/exec/handle_child.c						\
			src/exec/handle_file.c						\
			src/exec/exec_main.c						\
			src/exec/redir.c						\
			src/exec/error.c						\
			src/exec/path.c						\
			src/builtins/env.c						\
			src/builtins/echo.c						\
			src/builtins/exit.c						\
			src/builtins/export.c					\
			src/builtins/unset.c					\
			src/exec/free.c							\
			src/parsing/line/parse_err.c			\
			src/parsing/line/parse_line.c			\
			src/parsing/line/parse_utils.c			\
			src/parsing/line/to_modify.c			\
			src/parsing/quote_parse/remove_quote.c			\
			src/parsing/redir/in_hdc.c				\
			src/parsing/redir/out_app.c				\
			src/parsing/struct/lst_cmd/c_lst_cmd.c				\
			src/parsing/struct/lst_env/c_lst_env.c				\
			src/parsing/struct/lst_env/r_lst_env.c				\
			src/parsing/struct/lst_env/u_lst_env.c				\
			src/parsing/struct/m_shell/c_m_shell.c				\
			src/parsing/struct/m_shell/r_m_shell.c				\
			src/parsing/struct/order_file/c_order_file.c				\
			src/parsing/table_char/split_cmd.c				\
			src/parsing/table_char/table_cmd.c				\
			src/parsing/utils/utils1.c				\
			src/parsing/var_env/get_env.c				\
			src/parsing/var_env/rep_q_n_v.c				\
			src/parsing/var_env/exit_code.c				\
			src/parsing/parsing.c				\



OBJ 		= $(SRC:.c=.o)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline

$(LIBFT):
		$(MAKE) -C $(LIB)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all clean fclean re
