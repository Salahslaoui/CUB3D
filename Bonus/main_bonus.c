/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:17 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:48:59 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_init_all_bonus(t_data *data)
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
	t_graph		mlx;
	int			fd;
	t_player	pl;

	if (ac != 2)
		return (ft_put_error_bonus("Error:\nInvalid number of arguments\n"), 1);
	if (check_name_bonus(av[1]))
		return (ft_put_error_bonus("Error:\nInvalid file \".cub\"\n"), 1);
	ft_init_all_bonus(&utils);
	utils.player = &pl;
	utils.mlx = &mlx;
	utils_init_bonus(&utils, av[1]);
	if (ft_strncmp_bonus(parsing_map_bonus(&utils, &fd), "error", 5) == 0)
		return (free_map_bonus(utils.map), 1);
	player_detection_bonus(utils.map, &pl);
	if ((int)pl.pl_x == 0 || (int)pl.pl_y == 0)
		return (free_map_bonus(utils.map), free_it_bonus(utils.lst, &utils), \
		ft_put_error_bonus("Error:\nYou should to add player!\n"), 1);
	ray_casting_bonus(&utils, &mlx);
	ft_exit_bonus(&utils, NULL, 0);
}
