NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 	main/main.c parsing/check_input.c parsing/help.c\
		initial/initial.c  initial/list.c moves/rotate.c\
		moves/reverse_rotate.c moves/swap.c moves/push.c\
		main/find.c mini/three.c mini/four.c mini/five.c\
		main/push_swap.c\

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