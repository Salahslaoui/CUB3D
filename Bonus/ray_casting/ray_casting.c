/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:27 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/03 09:10:21 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
	data->view = NULL;
	data->mlx->mlx = NULL;
	data->mlx->project = NULL;
	data->mlx->E = NULL;
	data->mlx->W = NULL;
	data->mlx->N = NULL;
	data->mlx->S = NULL;
}

void ft_load_images(t_data *data, t_graph *mlx)
{
	mlx->S = mlx_load_png(data->SO);
	if (!mlx->S)
		ft_exit(data, "Error:\nLoading images failed!\n", 1);
	mlx->N = mlx_load_png(data->NO);
	if (!mlx->N)
		ft_exit(data, "Error:\nLoading images failed!\n", 1);
	mlx->W = mlx_load_png(data->WE);
	if (!mlx->W)
		ft_exit(data, "Error:\nLoading images failed!\n", 1);
	mlx->E = mlx_load_png(data->EA);
	if (!mlx->E)
		ft_exit(data, "Error:\nLoading images failed!\n", 1);
}

void	init_mlx_ptrs(t_data *data)
{
	t_graph		*mlx;

	mlx = data->mlx;
	mlx->mlx = mlx_init(WEIGHT, HEIGHT, "CUB3D", false);
	if (!mlx->mlx)
		ft_exit(data, "Error:\nWindow creation failed!\n", 1);
	mlx_set_mouse_pos(data->mlx->mlx, WEIGHT / 2, HEIGHT / 2);
	mlx->project = mlx_new_image(mlx->mlx, WEIGHT, HEIGHT);
	if (!mlx->project)
		ft_exit(data, "Error:\nImage creation failed!\n", 1);
	mlx->mini_map =  mlx_new_image(mlx->mlx, MINI_W, MINI_H);
	if (!mlx->mini_map)
		ft_exit(data, "Error: Image creation failed!\n", 1);
	if (mlx_image_to_window(data->mlx->mlx, data->mlx->project, 0, 0) == -1)
		ft_exit(data, "Error:\nPuting image to window failed!\n", 1);
	if (mlx_image_to_window(data->mlx->mlx, data->mlx->mini_map, 0, 0) == -1)
		ft_exit(data, "Error:\nPuting image to window failed!\n", 1);
	ft_load_images(data, mlx);
}

void	rander_2d_map(t_data *data, t_graph *mlx)
{
	init_mlx_ptrs(data);
	cast_all_rays(data, data->player);
	randring3d(data, data->player);
	put_mini_map(data, mlx, data->player);
	mlx_loop_hook(data->mlx->mlx, ft_handek_actions, data);
	mlx_loop(mlx->mlx);
}

void	ray_casting(t_data *data, t_graph *mlx)
{
	ft_init_data(data);
	data->view = malloc(sizeof(t_rays) * RAY_NBR);
	if (!data->view)
		ft_exit(data, "Error:\nMemory allocation failed!\n", 1);
	rander_2d_map(data, mlx);
}
