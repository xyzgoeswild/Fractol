SRC		= src/main.c \
		  src/display_error.c \
		  src/parsing.c \
		  src/events.c \
		  src/initialize.c \
		  src/math_utils.c \
		  src/render.c \
		  src/utils.c

NAME = fractol

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -O3

MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
