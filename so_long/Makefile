NAME = mlx.a
SRC = $(wildcard *.c)
CC = gcc
CFLAGS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -Lmlx -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c = .o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) -Wall -Wextra -Werror *.c $(CFLAGS) -o so_long

clean:
	rm -rf so_long

fclean: clean

re: clean fclean all

