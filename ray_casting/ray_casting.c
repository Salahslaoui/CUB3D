/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:27 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/22 19:58:58 by ozahdi           ###   ########.fr       */
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

void ft_init_data(t_data *data)
{
	t_player *player;

	player = data->player;
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->rot_angel = M_PI / 2;
	rotation_angel(data, player);
	player->redius = floor(SQUER / 7);
	player->speed = 15;
	player->rot_speed = 2 * (M_PI / 180);
	player->pl_x = player->pl_x * SQUER + floor(SQUER / 2);
	player->pl_y = player->pl_y * SQUER + floor(SQUER / 2);
	player->d_x = cos(deg_to_rad(player->rot_angel)) * player->speed;
	player->d_y = sin(deg_to_rad(player->rot_angel)) * player->speed;
}

void rander_2d_map(t_data *data, t_graph *mlx)
{
	mlx->mlx = mlx_init(WEIGHT, HEIGHT, "CUB3D", false);
	mlx->project = mlx_new_image(mlx->mlx, WEIGHT, HEIGHT);
	mlx->N = mlx_load_png("wall2.png");
	mlx->W = mlx_load_png("wall1.png");
	mlx->E = mlx_load_png("sss.png");
	mlx->S = mlx_load_png("pic.png");
	mlx_image_to_window(data->mlx->mlx, data->mlx->project, 0, 0);
	CastAllRays(data, data->player);
	Randring3D(data, data->player);
	mlx_loop_hook(data->mlx->mlx,ft_handek_actions, data);
	mlx_loop(mlx->mlx);
}

void ray_casting(t_data *data, t_graph *mlx)
{
	ft_init_data(data);
	data->view = malloc(sizeof(t_rays) * RAY_NBR);
	rander_2d_map(data, mlx);
}
