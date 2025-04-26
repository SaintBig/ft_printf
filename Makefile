# Variables
NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror

# Source files
SRCS		= ft_printf.c ft_print_ptr.c ft_print_num.c

# Object files
OBJS		= $(SRCS:.c=.o)

# Header file
HEADER		= ft_printf.h

# Rules
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