NAME = libft.a

SOURCES = 							\
	str/ft_strlen.c 				\
	str/ft_strmapi.c 				\
	str/ft_striteri.c 				\
	str/ft_strnstr.c 				\
	str/ft_strjoin.c 				\
	str/ft_strtrim.c 				\
	str/ft_strlcpy.c 				\
	str/ft_strchr.c					\
	str/ft_strlcat.c 				\
	str/ft_strdup.c					\
	str/ft_substr.c 				\
	str/ft_toupper.c 				\
	str/ft_tolower.c 				\
	str/ft_strncmp.c 				\
	str/ft_strrchr.c 				\
	is/ft_isdigit.c 				\
	is/ft_isprint.c 				\
	is/ft_isalpha.c 				\
	is/ft_isascii.c 				\
	is/ft_isalnum.c 				\
	is/ft_isspace.c					\
	mem/ft_memset.c 				\
	mem/ft_bzero.c 					\
	mem/ft_memcpy.c					\
	mem/ft_memmove.c				\
	mem/ft_memchr.c 				\
	mem/ft_memcmp.c 				\
	mem/ft_calloc.c 				\
	put/ft_putchar_fd.c				\
	put/ft_putstr_fd.c 				\
	put/ft_putendl_fd.c				\
	put/ft_putnbr_fd.c 				\
	convert/ft_split.c 				\
	convert/ft_itoa.c 				\
	convert/ft_atoi.c 				\
	convert/ft_atol.c 				\
	gnl/get_next_line.c 			\
	printf/ft_printf/ft_printf_hex.c 			\
	printf/ft_printf/ft_printf_ptr.c 			\
	printf/ft_printf/ft_printf_utils.c 		\
	printf/ft_printf/ft_printf.c 				\
	printf/ft_printf_fd/ft_printf_fd_hex.c 			\
	printf/ft_printf_fd/ft_printf_fd_ptr.c 			\
	printf/ft_printf_fd/ft_printf_fd_utils.c 		\
	printf/ft_printf_fd/ft_printf_fd.c 				\
	check/check_extension.c 		\
	lists/ft_lstnew_bonus.c			\
	lists/ft_lstadd_front_bonus.c	\
	lists/ft_lstsize_bonus.c		\
	lists/ft_lstlast_bonus.c		\
	lists/ft_lstadd_back_bonus.c	\
	lists/ft_lstdelone_bonus.c		\
	lists/ft_lstiter_bonus.c		\
	lists/ft_lstclear_bonus.c		\
	ptr/ft_swap.c					\
	free/free_char_tab.c			\
	free/free_int_tab.c				\


OBJECTS = $(SOURCES:.c=.o)

CC = gcc
INCLUDE = -I .
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar crs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
