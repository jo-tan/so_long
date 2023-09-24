/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:38:16 by jo-tan            #+#    #+#             */
/*   Updated: 2023/09/24 12:45:15 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"

/*data streams*/
# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define IMG_WIDTH 40
# define IMG_HEIGHT 40

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	int			**map;
	int			columns;
	int			rows;
	t_position	p_player;
	t_position	*p_collectable;
	t_position	p_exit;
	int			n_collectable;
	int			n_exit;
	int			n_player;
	int			c_collectable;
	int			c_exit;
	int			player_up;
	int			player_left;
	int			player_right;
	int			player_down;
	int			player_move;
	int			player_coll;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*mlx_img;
	t_map	*map;
	t_img	*player;
	t_img	*floor;
	t_img	*wall;
	t_img	*collectable;
	t_img	*exit;
}				t_game;

/*init_game*/
int				isber(char *file);
t_game			*game_init(char *filename);
void			game_map_init(t_game *game, char *filename);
void			map_init(t_game *game, char *filename);
/*check_map*/
void			map_isvalid(t_game *game, char *file);
char			**ft_map_copy(char *original);
void			free_map_copy(char **map_copy, int rows);
void			scan_player(t_game *game, char **map_copy);
void			move_on_paths(int x, int y, t_game *game, char **map_copy);
void			check_valid_path(t_game *game, char *file);
/*map*/
void			parsing_map(t_game *game, char *file);
void			map_read(t_game *game, char *file);
void			map_height(t_game *game, char *file);
void			map_width(t_game *game, char *file);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
/*init_texture*/
void			load_texture(t_game *game, t_img **img, char *path);
void			init_texture(t_game *game);
/*key hook*/
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				destroy_hook(int keycode, t_game *game);
/*move*/
void			move_up(t_game *game, int x, int y);
void			move_down(t_game *game, int x, int y);
void			move_left(t_game *game, int x, int y);
void			move_right(t_game *game, int x, int y);
/*update*/
void			draw(t_game *game);
void			update(t_game *game);
/*exit*/
void			ft_exit(char *errmsg, int errnum);
void			map_destroy(t_map *map);
void			destroy_game(t_game *game, char *errmsg, int errnum);
void			destroy_image(t_game *game);

#endif
