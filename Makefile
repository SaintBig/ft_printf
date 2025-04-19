# Variables
NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fPIC
AR			= ar rcs
RM			= rm -f

# Source files
SRCS		= ft_printf.c ft_print_ptr.c ft_print_num.c

# Object files
OBJS		= $(SRCS:.c=.o)

# Header file
HEADER		= ft_printf.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re