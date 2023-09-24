/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:04 by jo-tan            #+#    #+#             */
/*   Updated: 2023/09/22 17:49:10 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_game *game);
int	destroy_hook(int keycode, t_game *game);

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		destroy_game(game, 0, 0);
	if (keycode == 119)
		game->map->player_up = 1;
	if (keycode == 115)
		game->map->player_down = 1;
	if (keycode == 97)
		game->map->player_left = 1;
	if (keycode == 100)
		game->map->player_right = 1;
	update(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->map->player_up = 0;
	if (keycode == 115)
		game->map->player_down = 0;
	if (keycode == 97)
		game->map->player_left = 0;
	if (keycode == 100)
		game->map->player_right = 0;
	update(game);
	return (0);
}

int	destroy_hook(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	destroy_game(0, 0, 0);
	return (0);
}
