/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:17 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/03 12:16:56 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_init_all(t_data *data)
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

int	main(int ac, char **av)
{
	t_data		utils;
	t_player	pl;
	t_graph		mlx;
	int			fd;

	if (ac != 2)
		return (ft_put_error("Error:\nInvalid number of arguments\n"), 1);
	ft_init_all(&utils);
	utils.player = &pl;
	utils.mlx = &mlx;
	utils_init(&utils, av[1]);
	if (ft_strncmp(parsing_map(&utils, &fd), "error", 5) == 0)
		return (free_map(utils.map), 1);
	player_detection(utils.map, &pl);
	if ((int)pl.pl_x == 0 || (int)pl.pl_y == 0)
		return (free_it(utils.lst, &utils), \
		ft_put_error("Error:\nYou should to add player!\n"), 1);
	ray_casting(&utils, &mlx);
	ft_exit(&utils, NULL, 0);
}
