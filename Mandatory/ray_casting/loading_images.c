/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:32 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/03 12:06:24 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
