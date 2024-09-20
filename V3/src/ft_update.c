#include "so_long.h"

void	update(t_game *game);

static void	had_move(t_game *game, int x, int y)
{
	if (game->map->p_player.x != x || game->map->p_player.y != y)
	{
		game->map->player_move++;
		ft_putnbr_fd(game->map->player_move, 1);
		ft_putendl_fd("", 1);
	}
}

static void	iscollectable(t_game *game)
{
	int	k;

	k = 0;
	while (k < game->map->n_collectable)
	{
		if (game->map->p_collectable[k].x == game->map->p_player.x
			&& game->map->p_collectable[k].y == game->map->p_player.y)
		{
			game->map->p_collectable[k].x = -1;
			game->map->p_collectable[k].y = -1;
			game->map->player_coll++;
		}
		k++;
	}
}

void	update(t_game *game)
{
	int	x;
	int	y;

	x = game->map->p_player.x;
	y = game->map->p_player.y;
	if (game->map->player_up != 0)
		move_up(game, x, y);
	else if (game->map->player_down != 0)
		move_down(game, x, y);
	else if (game->map->player_left != 0)
		move_left(game, x, y);
	else if (game->map->player_right != 0)
		move_right(game, x, y);
	had_move(game, x, y);
	iscollectable(game);
	draw(game);
	if (game->map->p_exit.x == game->map->p_player.x
		&& game->map->p_exit.y == game->map->p_player.y)
		if (game->map->n_collectable == game->map->player_coll)
			destroy_game(game, 0, 0);
}
