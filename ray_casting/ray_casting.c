/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:27 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/18 22:35:23 by sslaoui          ###   ########.fr       */
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
	player->turn_dir = 0; // -1 left or 1 right
	player->walk_dir = 0; // -1 back or 1 front
	player->rot_angel = M_PI / 2;
	rotation_angel(data, player);
	player->redius = floor(SQUER / 7);
	player->speed = 15;
	player->rot_speed = 2 * (M_PI / 180);
	player->pl_x = player->pl_x * SQUER + floor(SQUER / 2);
	player->pl_y = player->pl_y * SQUER + floor(SQUER / 2);
	player->d_x = cos(degree_radian(player->rot_angel, 0)) * player->speed;
	player->d_y = sin(degree_radian(player->rot_angel, 0)) * player->speed;
}

void rander_2d_map(t_data *data, t_graph *mlx)
{
	mlx->mlx = mlx_init(WEIGHT, HEIGHT, "CUB3D", false);
	mlx->project = mlx_new_image(mlx->mlx, WEIGHT, HEIGHT);
	//mlx->image = mlx_new_image(mlx->mlx, (data->weight - 1) * SQUER, data->height * SQUER);
	// if (data->view[i].wasHitVert == true)
	// {
	// 	// if (data->view[i].ray_ang > 0 && data->view[i].ray_ang < M_PI)
	// 		mlx->la = mlx_load_png("/Users/ozahdi/Desktop/cub2d/wall1.png");
	// 	// else
	// 	// 	mlx->la = mlx_load_png("/Users/ozahdi/Desktop/cub2d/wall2.png");
	// }
	// else
	// {
	// 	// if (data->view[i].ray_ang > M_PI / 2 && data->view[i].ray_ang < 3 * M_PI_2)
	// 	// 	mlx->la = mlx_load_png("/Users/ozahdi/Desktop/cub2d/sss.png");
	// 	// else
	// 		mlx->la = mlx_load_png("/Users/ozahdi/Desktop/cub2d/pic2.png");	
	// }
	mlx->N = mlx_load_png("/Users/sslaoui/Desktop/Cub3d/wall2.png");
	mlx->W = mlx_load_png("/Users/sslaoui/Desktop/Cub3d/wall1.png");
	mlx->E = mlx_load_png("/Users/sslaoui/Desktop/Cub3d/sss.png");
	mlx->S = mlx_load_png("/Users/sslaoui/Desktop/Cub3d/pic.png");
	// printf("----------------------------------\n");
	// mlx->textute = mlx_texture_to_image(mlx->mlx, mlx->la);
	mlx_image_to_window(data->mlx->mlx, data->mlx->project, 0, 0);
	//mlx_image_to_window(data->mlx->mlx, data->mlx->image, 0, 0);
	//ft_fill_project(data, data->mlx);
	//ft_put_map(data);
	CastAllRays(data, data->player);
	Randring3D(data, data->player);
	mlx_loop_hook(data->mlx->mlx,ft_handek_actions, data);
	mlx_loop(mlx->mlx);
}

void ray_casting(t_data *data, t_graph *mlx)
{
	ft_init_data(data);
	rander_2d_map(data, mlx);
}