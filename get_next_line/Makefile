CC := gcc
NAME := get_next_line
CFLAGS := -Wall -Wextra -Werror
LIBFT := libft/libft.a
SOURCE :=	get_next_line.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

debug:
	$(CC) $(CFLAGS) -g $(SOURCE) $(LIBFT) -o $(NAME)

sanitize:
	$(CC) $(CFLAGS) -fsanitize=address $(SOURCE) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
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