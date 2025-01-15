NAME	=	minishell

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g $(INCLUDE)
INCLUDE	=	-I includes -I OctoLIB
CLONE	=	git clone
RM		=	rm -f

LIB		=	OctoLIB
LIBFT	=	$(LIB)/libft.a

SRC		=	src/builtins/cd.c \
			src/builtins/pwd.c \
			src/builtins/main.c \
			src/builtins/env.c \
			src/builtins/echo.c \
			src/builtins/exit.c \
			src/builtins/export.c \


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
