NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c check_input.c initial.c help.c list.c moves.c

OBJ = $(SRC:.c=.o)

LIBRARIES = ./libft/libft.a
SUBDIRS = libft

.SILENT:

all: libs $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBRARIES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libs:
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir);)

clean:
	rm -rf $(OBJ)
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) clean;)

fclean: clean
	rm -f $(NAME)
	$(foreach dir, $(SUBDIRS), $(MAKE) -C $(dir) fclean;)

re: fclean all

.PHONY: all clean fclean re libs bonus