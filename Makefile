CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRCS = push_swap.c \
		parser.c \
		stack.c \
		stack2.c \
		utils.c \
		utils2.c \
		normalize.c \
		instructions_pushrot.c \
		instructions_reverse.c \
		instructions_swap.c \
		algo_small.c \
		algo_small2.c \
		sorting.c \
		test.c \
		main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
