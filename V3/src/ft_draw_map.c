#include "so_long.h"

void	draw(t_game *game);

static void	draw_square(t_game *game, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < IMG_HEIGHT)
	{
		i = 0;
		while (i < IMG_WIDTH)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(game->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_env(t_game *game, int i, int j)
{
	int	k;

	if (game->map->p_exit.x == i && game->map->p_exit.y == j)
		draw_square(game, game->exit, i * IMG_WIDTH, j * IMG_HEIGHT);
	k = -1;
	while (++k < game->map->n_collectable)
		if (game->map->p_collectable[k].x == i && game->map->p_collectable[k].y == j)
			draw_square(game, game->collectable, i * IMG_WIDTH, j * IMG_HEIGHT);
	if (game->map->p_player.x == i && game->map->p_player.y == j)
		draw_square(game, game->player, i * IMG_WIDTH, j * IMG_HEIGHT);
}

static void	draw_map(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map->rows)
	{
		i = 0;
		while (i < game->map->columns)
		{
			if (game->map->map[j][i] == 1)
				draw_square(game, game->wall, i * IMG_WIDTH, j * IMG_HEIGHT);
			else
				draw_square(game, game->floor, i * IMG_WIDTH, j * IMG_HEIGHT);
			draw_env(game, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_game *game)
{
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->mlx_img, 0, 0);
}
