/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:31:37 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/14 09:53:13 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	put_player(t_graph *mlx, double player_y, double player_x)
{
	int			x;
	int			y;
	int			i;
	int			j;

	x = (MINI_W / 2) - 2;
	y = (MINI_H / 2) - 2;
	i = player_y - 2;
	while (i < player_y + 2)
	{
		x = (MINI_W / 2) - 2;
		j = player_x - 2;
		while (j < player_x + 2)
		{
			mlx_put_pixel(mlx->mini_map, x, y, 0xBE3144FF);
			x++;
			j++;
		}
		i++;
		y++;
	}
}

void	put_mini_map(t_data *data, t_graph *mlx, t_player *player, int i)
{
	double		player_x;
	double		player_y;
	int			j;
	int			h;
	int			w;

	player_x = ((player->pl_x / SQUER) * MINI_S) - (MINI_W / 2);
	player_y = ((player->pl_y / SQUER) * MINI_S) - (MINI_H / 2);
	while (++i < MINI_H)
	{
		j = -1;
		while (++j < MINI_W)
		{
			h = (player_y + i) / MINI_S;
			w = (player_x + j) / MINI_S;
			if (h >= data->height || h < 0 || w < 0 || w >= data->weight)
				mlx_put_pixel(mlx->mini_map, j, i, 0xF2EFE7FF);
			else if (data->map[h][w] == '1')
				mlx_put_pixel(mlx->mini_map, j, i, 0x23486AFF);
			else
				mlx_put_pixel(mlx->mini_map, j, i, 0xF2EFE7FF);
		}
	}
	put_player(mlx, player_y, player_x);
}
