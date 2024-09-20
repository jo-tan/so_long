NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g3
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I ./mlx -I /usr/X11/include/
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lX11 -lmlx -lXext -lm -g -L /usr/X11/lib 
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/ft_draw_map.c \
				src/ft_hook.c \
				src/ft_init_game.c \
				src/ft_init_game1.c \
				src/ft_init_map.c \
				src/ft_map_isvalid.c \
				src/ft_valid_path.c \
				src/ft_mlx.c \
				src/ft_move.c \
				src/ft_parsing_map.c \
				src/ft_texture.c \
				src/so_long.c \
				src/ft_update.c

all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -sC mlx
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -sC libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re

