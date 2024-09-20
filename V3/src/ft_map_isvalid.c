#include "so_long.h"

static int	isborder(t_game *game, int i)
{
	if (i < game->map->columns
		|| i > (game->map->columns + 1) * (game->map->rows - 1)
		|| i % (game->map->columns + 1) == 0
		|| i % (game->map->columns + 1) == game->map->columns - 1)
		return (1);
	return (0);
}

static void	isvalid(t_game *game, char *file, int i)
{
	if (file[i] == 'P')
		game->map->n_player++;
	else if (file[i] == 'E')
		game->map->n_exit++;
	else if (file[i] == 'C')
		game->map->n_collectable++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		destroy_game(game, "Map content is invalid", 0);
	}
}

void	map_isvalid(t_game *game, char *file)
{
	int	i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(game, i))
		{
			if (file[i] != '1')
			{
				free(file);
				destroy_game(game, "Map isn't surrounded by walls", 0);
			}
		}
		else
			isvalid(game, file, i);
	}
	if (game->map->n_player != 1
		|| game->map->n_exit != 1
		|| game->map->n_collectable < 1)
	{
		free(file);
		destroy_game(game, "Map configuration is invalid", 0);
	}
}
