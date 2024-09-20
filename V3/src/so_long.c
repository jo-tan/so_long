#include "so_long.h"

void	ft_exit(char *errmsg, int errnum);
void	map_destroy(t_map *map);
void	destroy_game(t_game *game, char *errmsg, int errnum);
int	isber(char *file);

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

void	destroy_game(t_game *game, char *errmsg, int errnum)
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
		if (game->mlx_img != 0)
			mlx_destroy_image(game->mlx, game->mlx_img);
		if (game->win != 0)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx != 0)
			mlx_destroy_display(game->mlx);
		if (game->map != 0)
			map_destroy(game->map);
		free(game);
	}
	ft_exit(errmsg, errnum);
}

int	isber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		ft_exit("invalid number of arguments. Hint: ./so_long maps/map.ber", 0);
	if (isber(av[1]) == 0)
		ft_exit("invalid argument (<map>.ber)", 0);
	game = game_init(av[1]);
	draw(game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, destroy_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
