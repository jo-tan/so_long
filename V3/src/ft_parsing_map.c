#include "so_long.h"

static void	free_matrix(t_game *game, char *file, int **m, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	game->map->map = 0;
	free(file);
	destroy_game(game, "map_parsing(): malloc()", errno);
}

static void	get_coord(t_game *game, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		game->map->p_player.x = k % (game->map->columns + 1);
		game->map->p_player.y = k / (game->map->columns + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		game->map->p_exit.x = k % (game->map->columns + 1);
		game->map->p_exit.y = k / (game->map->columns + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		game->map->p_collectable[*obj].x = k % (game->map->columns + 1);
		game->map->p_collectable[*obj].y = k / (game->map->columns + 1);
		file[k] = '0';
		(*obj)++;
	}
}

void	parsing_map(t_game *game, char *file)
{
	int	i;
	int	j;
	int	k;
	int	obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < game->map->rows)
	{
		game->map->map[j] = (int *)malloc(sizeof(int) * game->map->columns);
		if (game->map->map[j] == 0)
			free_matrix(game, file, game->map->map, j);
		i = 0;
		while (i < game->map->columns)
		{
			get_coord(game, file, k, &obj);
			game->map->map[j][i++] = file[k++] - (IMG_WIDTH + 8);
		}
		k++;
	}
}
