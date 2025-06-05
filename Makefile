NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_printf.c ft_printf_utils.c

OBJS		= $(SRCS:.c=.o)

HEADER		= ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re