/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:31:37 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/22 19:58:16 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_put_player(t_data *data, mlx_image_t *image)
{
	int i = 0;
	int j = 0;
	i =  data->player->pl_y - data->player->redius;
	while (i >= 0 && i <  data->player->pl_y + data->player->redius)
	{
		j = data->player->pl_x - data->player->redius;
		while (j >= 0 && j < data->player->pl_x + data->player->redius)
		{
			if (pow(j - data->player->pl_x, 2) + pow(i -  data->player->pl_y, 2) <= pow(data->player->redius, 2))
				mlx_put_pixel(image, j, i, 0xFF6700FF);
			j++;
		}
		i++;
	}
}

void ft_put_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i >= 0 && i < data->height * SQUER)
	{
		j = 0;
		while (j >= 0 && j < (data->weight - 1) * SQUER)
		{
			if (data->map[i / SQUER][j / SQUER] == '1')
				mlx_put_pixel(data->mlx->image, j, i, 0x3A6EA5FF);
			else
				mlx_put_pixel(data->mlx->image, j, i, 0xEBEBEBFF);
			j++;
		}
		i++;
	}
	ft_put_player(data, data->mlx->image);
}
