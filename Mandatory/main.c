/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:17 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/03 11:14:04 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void ft_init_all(t_data *data)
{
	data->no = NULL;
	data->ea = NULL;
	data->so = NULL;
	data->we = NULL;
	data->map = NULL;
	data->lst = NULL;
	data->name = NULL;
	data->view = NULL;
}

void leaks(){system("leaks cub3D");}

int main(int ac, char **av)
{
	atexit(leaks);
	t_data	utils;
	t_player	pl;
	t_graph	mlx;
	int	fd;

	if (ac != 2)
		return printf("bad arg!"), 1;
	ft_init_all(&utils);
	utils.player = &pl;
	utils.mlx = &mlx;
	utils_init(&utils, av[1]);
	if(ft_strncmp(parsing_map(&utils, &fd),"error",5) == 0)
		return (free_map(utils.map), 1); // change returne with exit
	player_detection(utils.map, &pl);
	if ((int)pl.pl_x == 0 || (int)pl.pl_y == 0)
		return (free_map(utils.map), free_it(utils.lst, &utils), \
		ft_put_error("Error:\nYou should to add player!\n"), 1);
	ray_casting(&utils, &mlx);
	ft_exit(&utils, NULL, 0);
}
