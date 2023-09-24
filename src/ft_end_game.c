/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:31:34 by jo-tan            #+#    #+#             */
/*   Updated: 2023/09/24 12:31:39 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *errmsg, int errnum);
void	map_destroy(t_map *map);
void	destroy_game(t_game *game, char *errmsg, int errnum);
void	destroy_image(t_game *game);

void	ft_exit(char *errmsg, int errnum)
{
	if (errmsg == 0 && errnum == 0)
		ft_putendl_fd("GAME END", 0);
	if (errmsg != 0 || errnum != 0)
		ft_putendl_fd("ERROR", 2);
	if (errmsg != 0)
		ft_putstr_fd(errmsg, 2);
	if (errmsg != 0 && errnum != 0)
		ft_putstr_fd(": ", 2);
	if (errnum != 0)
		ft_putstr_fd(strerror(errnum), 2);
	if (errmsg != 0 || errnum != 0)
	{
		ft_putendl_fd("", 2);
		exit (EXIT_FAILURE);
	}
	exit (EXIT_SUCCESS);
}

void	map_destroy(t_map *map)
{
	int	i;

	if (map != 0)
	{
		if (map->p_collectable != 0)
			free(map->p_collectable);
		if (map->map != 0)
		{
			i = 0;
			while (i < map->rows)
				free(map->map[i++]);
			free(map->map);
		}
		free(map);
	}
}

void	destroy_image(t_game *game)
{
	if (game != 0)
	{
		if (game->exit != 0)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->collectable != 0)
			mlx_destroy_image(game->mlx, game->collectable);
		if (game->wall != 0)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->floor != 0)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->player != 0)
			mlx_destroy_image(game->mlx, game->player);
	}
}

void	destroy_game(t_game *game, char *errmsg, int errnum)
{
	if (game != 0)
	{
		destroy_image(game);
		if (game->map != 0)
			map_destroy(game->map);
		if (game->mlx_img != 0)
			mlx_destroy_image(game->mlx, game->mlx_img);
		if (game->win != 0)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx != 0)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
	ft_exit(errmsg, errnum);
}
