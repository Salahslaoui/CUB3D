/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:17 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/21 03:16:22 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	l()
{
	system("leaks cub3d");
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int main(int ac, char **av)
{
	atexit(l);
	t_data	utils;
	t_player	pl;
	t_graph	mlx;
	int	fd;

	if (ac != 2)
		return printf("bad arg!"), 1;
	utils.player = &pl;
	utils.mlx = &mlx;
	utils_init(&utils, av[1]);
	parsing_map(&utils, &fd);
	if (!utils.map)
		return (0);
	player_detection(utils.map, &pl);
	// ray_casting(&utils, &mlx);
	// if ()
	free_map(utils.map);
}
