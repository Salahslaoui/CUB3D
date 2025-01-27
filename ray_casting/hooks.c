/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:29:09 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/27 16:13:46 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	up_down_moves(t_data *data, t_player *player, int walk)
{
	double		movespeed;
	int			x;
	int			y;

	movespeed = walk * player->rot_speed;
	x = player->pl_x + cos(player->rot_angel) * walk * player->speed;
	y = player->pl_y + sin(player->rot_angel) * walk * player->speed;
	if (!ft_check_wall(data, x, y))
	{
		player->pl_x += cos(player->rot_angel) * walk * player->speed;
		player->pl_y += sin(player->rot_angel) * walk * player->speed;
	}
}

void	lift_right_arrows(t_player *player, int ang)
{
	player->rot_angel += (player->rot_speed * ang);
	if (player->rot_angel > 2 * M_PI)
		player->rot_angel -= 2 * M_PI;
	if (player->rot_angel < 0)
		player->rot_angel += 2 * M_PI;
}

void	right_lift_moves(t_data *data, t_player *player, int walk)
{
	double		move_x;
	double		move_y;

	move_x = player->pl_x + cos(player->rot_angel + M_PI / 2) * walk * \
	player->speed;
	move_y = player->pl_y + sin(player->rot_angel + M_PI / 2) * walk * \
	player->speed;
	if (!ft_check_wall(data, move_x, move_y))
	{
		player->pl_x = move_x;
		player->pl_y = move_y;
	}
}

void	ft_handek_actions(void *param)
{
	t_data		*data;
	t_player	*player;

	data = (t_data *)param;
	player = data->player;
	player->strafe_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP) || \
		mlx_is_key_down(data->mlx->mlx, MLX_KEY_W))
		up_down_moves(data, player, 1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN) || \
		mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
		up_down_moves(data, player, -1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
		lift_right_arrows(player, 1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
		lift_right_arrows(player, -1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_D))
		right_lift_moves(data, player, 1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_A))
		right_lift_moves(data, player, -1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_ESCAPE))
		exit (0);
	cast_all_rays(data, player);
	randring3d(data, player);
}
