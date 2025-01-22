/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:33:37 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/22 19:58:52 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_check_wall(t_data *data, double x, double y)
{
	int i = y / SQUER;
	int j = x / SQUER;
	if (x >= data->weight * SQUER || y >= data->height * SQUER || \
	x < 0 || y < 0)
		return (1);
	int q = data->player->pl_x / SQUER;
	int w = data->player->pl_y / SQUER;
	if ((data->map[i][q] && data->map[i][q] == '1') || \
	(data->map[w][j] && data->map[w][j] == '1'))
		return (1);
	if (data->map && data->map[i] && data->map[i][j] && data->map[i][j] == '1')
		return (1);
	return (0);
}

double deg_to_rad(double degree)
{
	return (degree * (M_PI / 180));
}

double normalaize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	else if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void ft_release_keys(t_data *data)
{
	t_player *player = data->player;
	
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP))
		player->walk_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN) || \
		mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
		player->walk_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
		player->turn_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
		player->turn_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_W))
		player->walk_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_D))
		player->walk_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_A))
		player->walk_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
		player->turn_dir = 0;
}

int wallcheckers(t_data *data, int x, int y)
{
	int i = floor(y / SQUER);
	int j = floor(x / SQUER);
	if (data->map[i][j] == '1')
		return (1);
	return (0);
}
