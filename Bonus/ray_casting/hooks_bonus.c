/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:29:09 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/17 13:49:36 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	handle_mouse_movement(t_data *data)
{
	int			prev_mouse_x;
	int			mouse_x;
	int			mouse_y;
	double		sensitivity;
	int			delta_x;

	prev_mouse_x = WEIGHT / 2;
	sensitivity = 0.001;
	mlx_get_mouse_pos(data->mlx->mlx, &mouse_x, &mouse_y);
	mlx_set_cursor_mode(data->mlx->mlx, MLX_MOUSE_HIDDEN);
	delta_x = mouse_x - prev_mouse_x;
	data->player->rot_angel += delta_x * sensitivity;
	data->player->rot_angel = normalaize_angle_bonus(data->player->rot_angel);
	mlx_set_mouse_pos(data->mlx->mlx, WEIGHT / 2, HEIGHT / 2);
	prev_mouse_x = WEIGHT / 2;
}

static void	up_down_moves(t_data *data, t_player *player, int walk)
{
	double		movespeed;
	int			x;
	int			y;

	movespeed = walk * player->rot_speed;
	x = player->pl_x + cos(player->rot_angel) * walk * player->speed;
	y = player->pl_y + sin(player->rot_angel) * walk * player->speed;
	if (!ft_check_wall_bonus(data, x, y))
	{
		player->pl_x += cos(player->rot_angel) * walk * player->speed;
		player->pl_y += sin(player->rot_angel) * walk * player->speed;
	}
}

static void	lift_right_arrows(t_player *player, int ang)
{
	player->rot_angel += (player->rot_speed * ang);
	if (player->rot_angel > 2 * M_PI)
		player->rot_angel -= 2 * M_PI;
	if (player->rot_angel < 0)
		player->rot_angel += 2 * M_PI;
}

static void	right_lift_moves(t_data *data, t_player *player, int walk)
{
	double		move_x;
	double		move_y;

	move_x = player->pl_x + cos(player->rot_angel + M_PI / 2) * walk * \
	player->speed;
	move_y = player->pl_y + sin(player->rot_angel + M_PI / 2) * walk * \
	player->speed;
	if (!ft_check_wall_bonus(data, move_x, move_y))
	{
		player->pl_x = move_x;
		player->pl_y = move_y;
	}
}

void	ft_handek_actions_bonus(void *param)
{
	t_data		*data;

	data = (t_data *)param;
	data->player->strafe_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP) || \
		mlx_is_key_down(data->mlx->mlx, MLX_KEY_W))
		up_down_moves(data, data->player, 1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN) || \
		mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
		up_down_moves(data, data->player, -1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
		lift_right_arrows(data->player, 1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
		lift_right_arrows(data->player, -1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_D))
		right_lift_moves(data, data->player, 1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_A))
		right_lift_moves(data, data->player, -1);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_ESCAPE))
		ft_exit_bonus(data, NULL, 0);
	cast_all_rays_bonus(data, data->player);
	randring3d_bonus(data, data->player);
	put_mini_map_bonus(data, data->mlx, data->player, -1);
	handle_mouse_movement(data);
}
