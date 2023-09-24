/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:52:28 by jo-tan            #+#    #+#             */
/*   Updated: 2023/09/22 17:52:38 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*game_init(char *filename);

static void	renderer_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == 0)
		destroy_game(game, "mlx_init(): can't load mlx", 0);
	game->win = mlx_new_window(game->mlx, game->map->columns * IMG_WIDTH,
			game->map->rows * IMG_HEIGHT, "so_long");
	if (game->win == 0)
		destroy_game(game, "mlx_new_window(): can't create a window", 0);
	game->mlx_img = mlx_new_image(game->mlx, game->map->columns * IMG_WIDTH,
			game->map->rows * IMG_HEIGHT);
	if (game->mlx_img == 0)
		destroy_game(game, "mlx_new_image(): can't create an image", 0);
}

t_game	*game_init(char *filename)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == 0)
		destroy_game(0, "game_init(): malloc()", errno);
	game->map = 0;
	game->mlx = 0;
	game->win = 0;
	game->mlx_img = 0;
	game->player = 0;
	game->exit = 0;
	game->collectable = 0;
	game->wall = 0;
	game->floor = 0;
	game_map_init(game, filename);
	renderer_init(game);
	init_texture(game);
	return (game);
}
