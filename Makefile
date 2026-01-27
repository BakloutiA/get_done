# Variables
NAME		= gnl.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
# Default BUFFER_SIZE if not specified
BS_FLAG		= -D BUFFER_SIZE=42

# Source files
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compiling with the BUFFER_SIZE flag
%.o: %.c
	$(CC) $(CFLAGS) $(BS_FLAG) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Special rule to compile and run a test
# Usage: make test
test: re
	$(CC) $(CFLAGS) $(BS_FLAG) main.c $(NAME) -o test_gnl
	./test_gnl

.PHONY: all clean fclean re test
