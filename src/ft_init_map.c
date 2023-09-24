/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:24 by jo-tan            #+#    #+#             */
/*   Updated: 2023/09/24 12:22:47 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_game *game, char *file);
void	map_height(t_game *game, char *file);
void	map_width(t_game *game, char *file);

void	map_read(t_game *game, char *file)
{
	map_width(game, file);
	map_height(game, file);
	map_isvalid(game, file);
	check_valid_path(game, file);
	game->map->p_collectable = (t_position *)malloc(sizeof(t_position)
			* game->map->n_collectable);
	if (game->map->p_collectable == 0)
	{
		free(file);
		destroy_game(game, "map_read(): malloc() collectable", errno);
	}
	game->map->map = (int **)malloc(sizeof(int *) * game->map->rows);
	if (game->map->map == 0)
	{
		free(file);
		destroy_game(game, "map_read(): malloc() map", errno);
	}
	parsing_map(game, file);
}

void	map_height(t_game *game, char *file)
{
	int	i;
	int	j;

	game->map->rows = 1;
	i = game->map->columns + 1;
	while (i < (int)ft_strlen(file) && file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (game->map->columns != j)
		{
			free(file);
			destroy_game(game, "map format is invalid", 0);
		}
		i += game->map->columns + 1;
		game->map->rows++;
	}
}

void	map_width(t_game *game, char *file)
{
	game->map->columns = 0;
	while (file[game->map->columns] && file[game->map->columns] != '\n')
		game->map->columns++;
	if (game->map->columns == 0 || file[game->map->columns] == 0)
	{
		free(file);
		destroy_game(game, "map file is invalid", 0);
	}
}
