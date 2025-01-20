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
			src/builtins/main.c						\
			src/builtins/env.c						\
			src/builtins/echo.c						\
			src/builtins/exit.c						\
			src/builtins/export.c					\
			src/builtins/unset.c					\
			src/parsing/struct/lst_env/c_lst_env.c	\
			src/parsing/struct/lst_env/r_lst_env.c	\
			src/parsing/struct/lst_env/u_lst_env.c	\
			src/parsing/utils/utils1.c				\
			src/exec/free.c							\
			src/exec/main.c							\
			src/exec/path.c							\
			src/exec/exec_utils.c							\
			# src/parsing/struct/m_shell/c_m_shell.c	\

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
