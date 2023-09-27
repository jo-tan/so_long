/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:48:07 by jo-tan            #+#    #+#             */
/*   Updated: 2023/09/27 10:11:17 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		isber(char *file);

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
	mlx_hook(game->win, KeyPress, 1L << 0, key_press, game);
	mlx_hook(game->win, KeyRelease, 1L << 1, key_release, game);
	mlx_hook(game->win, DestroyNotify, 0, destroy_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
