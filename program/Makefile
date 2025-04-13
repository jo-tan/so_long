NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g3
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I /usr/local/include
LIB			=	-L ./libft -lft -L /usr/local/lib -lmlx -lX11 -lXext -lbsd
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
				src/ft_update.c\
				src/ft_end_game.c

all:		libft o_dir $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) $(INC) -o $@ $^ $(LIB)
			@echo " [ OK ] | so_long ready!"

libft:		
			@echo " [ .. ] | Compiling libft.."
			@make -sC libft
			@echo " [ OK ] | Libft ready!"

o_dir:
			@mkdir -p obj
			@echo " [ .. ] | Compiling so_long.."

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

.PHONY:		all clean fclean re libft
