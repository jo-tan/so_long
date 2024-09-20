#include "so_long.h"

void	load_texture(t_game *game, t_img **img, char *path);
void	init_texture(t_game *game);

void	load_texture(t_game *game, t_img **img, char *path)
{
    int	width;
    int	height;

	*img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (*img == 0)
	{
		destroy_game(0, "texture_init(): can't load texture", 0);
	}
	(*img)->width = width;
	(*img)->height = height;
}

void	init_texture(t_game *game)
{
	load_texture(game, &game->player, "./textures/player.xpm");
	load_texture(game, &game->exit, "./textures/exit.xpm");
	load_texture(game, &game->wall, "./textures/wall.xpm");
	load_texture(game, &game->collectable, "./textures/gas.xpm");
	load_texture(game, &game->floor, "./textures/sand.xpm");
}
