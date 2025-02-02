/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:27 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/02 21:49:14 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	rotation_angel(t_data *data, t_player *player)
{
	if (data->map[(int)player->pl_y][(int)player->pl_x] == 'N')
		player->rot_angel = (3 * M_PI) / 2;
	else if (data->map[(int)player->pl_y][(int)player->pl_x] == 'W')
		player->rot_angel = M_PI;
	else if (data->map[(int)player->pl_y][(int)player->pl_x] == 'E')
		player->rot_angel = 0;
	else if (data->map[(int)player->pl_y][(int)player->pl_x] == 'S')
		player->rot_angel = M_PI / 2;
}

void	ft_init_data(t_data *data)
{
	t_player		*player;

	player = data->player;
	player->turn_dir = 0;
	player->walk_dir = 0;
	rotation_angel(data, player);
	player->redius = floor(SQUER / 7);
	player->speed = 4;
	player->rot_speed = 2 * (M_PI / 180);
	player->pl_x = player->pl_x * SQUER + floor(SQUER / 2);
	player->pl_y = player->pl_y * SQUER + floor(SQUER / 2);
	player->d_x = cos(deg_to_rad(player->rot_angel)) * player->speed;
	player->d_y = sin(deg_to_rad(player->rot_angel)) * player->speed;
	data->view = NULL;
	data->mlx->mlx = NULL;
	data->mlx->project = NULL;
	data->mlx->east = NULL;
	data->mlx->west = NULL;
	data->mlx->north = NULL;
	data->mlx->south = NULL;
}

void	ft_load_images(t_data *data, t_graph *mlx)
{
	mlx->south = mlx_load_png(data->so);
	if (!mlx->south)
		ft_exit(data, "Error:\nLoading images failed!\n", 1);
	mlx->north = mlx_load_png(data->no);
	if (!mlx->north)
		ft_exit(data, "Error:\nLoading images failed!\n", 1);
	mlx->west = mlx_load_png(data->we);
	if (!mlx->west)
		ft_exit(data, "Error:\nLoading images failed!\n", 1);
	mlx->east = mlx_load_png(data->ea);
	if (!mlx->east)
		ft_exit(data, "Error:\nLoading images failed!\n", 1);
}

void	init_mlx_ptrs(t_data *data)
{
	t_graph		*mlx;

	mlx = data->mlx;
	mlx->mlx = mlx_init(WEIGHT, HEIGHT, "CUB3D", false);
	if (!mlx->mlx)
		ft_exit(data, "Cub3D: Error: Window creation failed!\n", 1);
	mlx->project = mlx_new_image(mlx->mlx, WEIGHT, HEIGHT);
	if (!mlx->project)
		ft_exit(data, "Cub3D: Error: Image creation failed!\n", 1);
	if (mlx_image_to_window(data->mlx->mlx, data->mlx->project, 0, 0) == -1)
		ft_exit(data, "Cub3D: Error: Puting image to window failed!\n", 1);
	ft_load_images(data, mlx);
}

void	rander_2d_map(t_data *data, t_graph *mlx)
{
	init_mlx_ptrs(data);
	cast_all_rays(data, data->player);
	randring3d(data, data->player);
	mlx_loop_hook(data->mlx->mlx, ft_handek_actions, data);
	mlx_loop(mlx->mlx);
}

void	ray_casting(t_data *data, t_graph *mlx)
{
	ft_init_data(data);
	data->view = malloc(sizeof(t_rays) * RAY_NBR);
	if (!data->view)
		ft_exit(data, "Cub3d: Error: Memory allocation failed!\n", 1);
	rander_2d_map(data, mlx);
}
