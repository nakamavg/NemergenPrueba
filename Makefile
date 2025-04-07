CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -I ./includes
SRC_DIR = srcs
NAME = Nemergent

SRC = $(SRC_DIR)/config.c $(SRC_DIR)/linked_list.c $(SRC_DIR)/threads.c $(SRC_DIR)/numbers.c $(SRC_DIR)/arguments.c $(SRC_DIR)/signals.c main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(NAME) test_config test_lists test_threads

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re