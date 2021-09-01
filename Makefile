CC := gcc
NAME := ft_minishell
CFLAGS := -Wall -Wextra -Werror
LIBFT := get_next_line/libft/libft.a
GNL := get_next_line/get_next_line.a
SOURCE := main.c parsing.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C get_next_line
	$(CC) $(CFLAGS) $(OBJECTS) $(GNL) $(LIBFT) -o $(NAME)

debug:
	$(CC) $(CFLAGS) -g $(SOURCE) $(GNL) $(LIBFT) -o $(NAME)

sanitize:
	$(CC) $(CFLAGS) -fsanitize=address $(SOURCE) $(LIBFT) -o $(NAME)

clean:
	make -C get_next_line clean
	rm -f $(OBJECTS)

sclean:
	rm -f $(OBJECTS)

fclean: dclean
	rm -f $(NAME)
	rm -f $(LIBFT)

dclean: clean
	rm -rf $(NAME).dSYM

re: fclean all

sre: sclean all