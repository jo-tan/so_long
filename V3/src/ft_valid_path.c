#include "so_long.h"
char	**ft_map_copy(char *original);
void	free_map_copy(char **map_copy, int rows);
void	scan_player(t_game *game, char **map_copy);
void	move_on_paths(int x, int y, t_game *game, char **map_copy);
void	check_valid_path(t_game *game, char *file);

void	scan_player(t_game *game, char **map_copy)
{
	game->map->p_player.y = 0;
	game->map->p_player.x = 0;
	while (game->map->p_player.y < game->map->rows)
	{
		while (game->map->p_player.x < game->map->columns)
		{
			if (map_copy[game->map->p_player.y][game->map->p_player.x] == 'P')
				break ;
			game->map->p_player.x++;
		}
		if (map_copy[game->map->p_player.y][game->map->p_player.x] == 'P')
			break ;
		game->map->p_player.x = 0;
		game->map->p_player.y++;
	}
}

void	move_on_paths(int x, int y, t_game *game, char **map_copy)
{
	char	type;

	type = map_copy[y][x];
	if (y< 0 || y >= game->map->rows
		|| x < 0 || x >= game->map->columns
			|| map_copy[y][x] == '1')
		return;
	if (type == 'C')
	{
		game->map->c_collectable -= 1;
		map_copy[y][x] = '1';
	}
	if (type == 'E')
	{
		game->map->c_exit -= 1;
		map_copy[y][x] = '1';
	}
	if (type == '0' || type == 'P')
		map_copy[y][x] = '1';
	move_on_paths(x - 1, y, game, map_copy);
	move_on_paths(x + 1, y, game, map_copy);
	move_on_paths(x, y - 1, game, map_copy);
	move_on_paths(x, y + 1, game, map_copy);
}

char **ft_map_copy(char *original)
{
	char **copy;

	return (copy = ft_split(original, '\n'));
}

void	free_map_copy(char **map_copy, int rows)
{
	int i;

	i = 0;
	while (i < rows)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

void	check_valid_path(t_game *game, char *file)
{
	char	**map_copy;

	map_copy = ft_map_copy(file);
	game->map->c_collectable = game->map->n_collectable;
	game->map->c_exit = game->map->n_exit;
	scan_player(game, map_copy);
	move_on_paths(game->map->p_player.x, game->map->p_player.y, game, map_copy);
	if (game->map->c_collectable != 0 || game->map->c_exit >= game->map->n_exit)
	{
		free_map_copy(map_copy, game->map->rows);
		free(file);
		destroy_game(game, "This map has no valid path.", errno);
	}
	free_map_copy(map_copy, game->map->rows);
}
