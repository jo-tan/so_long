#include "so_long.h"

void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);

void	move_up(t_game *game, int x, int y)
{
	if (game->map->map[y - 1][x] == 0)
		game->map->p_player.y -= 1;
}

void	move_down(t_game *game, int x, int y)
{
	if (game->map->map[y + 1][x] == 0)
		game->map->p_player.y += 1;
}

void	move_left(t_game *game, int x, int y)
{
	if (game->map->map[y][x - 1] == 0)
		game->map->p_player.x -= 1;
}

void	move_right(t_game *game, int x, int y)
{
	if (game->map->map[y][x + 1] == 0)
		game->map->p_player.x += 1;
}
