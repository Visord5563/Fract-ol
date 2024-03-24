NAME = main

SRC = main.c mandelbrod.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

# NAME = main

# SRC = main.c

# OBJ = $(SRC:.c=.o)

# all: $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# clean:
# 	rm -rf $(OBJ)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all
