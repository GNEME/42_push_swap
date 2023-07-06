NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = mandatory/push_swap.c	mandatory/list_operators.c	mandatory/push_swap_utils.c	mandatory/push_swap_utils1.c \
		mandatory/push_swap_utils2.c mandatory/push_swap_utils3.c mandatory/push_swap_parsing.c

SRC_BONUS = bonus/checker.c bonus/list_operators.c bonus/get_next_line.c bonus/get_next_line_utils.c \
			bonus/push_swap_utils.c bonus/push_swap_parsing.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o checker

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re
