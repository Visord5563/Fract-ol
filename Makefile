NAME = fractol
NAMEB = fractol_bonus

SRC = mandatory/main.c mandatory/put_win.c mandatory/fractol.c mandatory/ft_atof.c
SRCB = bonus/main_bonus.c bonus/put_win_bonus.c bonus/fractol_bonus.c bonus/ft_atof_bonus.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all : $(NAME)

%.o: %.c bonus/header_bonus.h
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

%.o: %.c mandatory/header.h
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

bonus: $(OBJB)
	$(CC) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(NAMEB)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	rm -rf $(OBJ) $(OBJB)

fclean : clean
	rm -rf $(NAME) $(NAMEB)

re : fclean all