#include "so_long.h"
void	game_map_init(t_game *game, char *filename);
void	map_init(t_game *game, char *filename);

void	game_map_init(t_game *game, char *filename)
{
	game->map = (t_map *)(malloc(sizeof(t_map)));
	if (game->map == 0)
		destroy_game(game, "map_init(): malloc failed", errno);
	game->map->map = 0;
	game->map->p_collectable = 0;
	game->map->n_collectable = 0;
	game->map->n_exit = 0;
	game->map->n_player = 0;
	game->map->c_collectable = 0;
	game->map->c_exit = 0;
	game->map->player_down = 0;
	game->map->player_left = 0;
	game->map->player_right = 0;
	game->map->player_up = 0;
	game->map->player_move = 0;
	game->map->player_coll = 0;
	map_init(game, filename);
}

static void	file_parse(t_game *game, char **file, char buf[], int fd)
{
	char	*tmp;

	tmp = ft_strjoin(*file, buf);
	free(*file);
	*file = tmp;
	if (file == 0)
	{
		close(fd);
		destroy_game(game, "map_int(): ft_strjoin", errno);
	}
}

static void	read_file(t_game *game, char **file, char buf[], int fd)
{
	int	read_fd;

	read_fd = 1;
	while (read_fd != 0)
	{
		read_fd = read (fd, buf, 1024);
		if (read_fd == -1)
		{
			free(*file);
			close(fd);
			destroy_game(game, "read_file(): read()", errno);
		}
		else
		{
			buf[read_fd] = 0;
			file_parse(game, file, buf, fd);
		}
	}
}

static char	*file_init(t_game *game, int fd)
{
	char	*file;

	file = ft_calloc(1, 1);
	if (file == 0)
	{
		close(fd);
		destroy_game(game, "map_init(): ft_calloc()", errno);
	}
	return (file);
}

void	map_init(t_game *game, char *filename)
{
	int		fd;
	char	*file;
	char	buf[1024 + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		destroy_game(game, filename, errno);
	file = file_init(game, fd);
	read_file(game, &file, buf, fd);
	close(fd);
	map_read(game, file);
	free(file);
}
