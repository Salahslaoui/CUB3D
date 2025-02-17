/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:32 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/17 13:50:11 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	check_png_ext(char *str)
{
	int		len;

	if (!str)
		return (1);
	len = ft_strlen_bonus(str);
	if (ft_strcmp_bonus(str + len - 4, ".png"))
		return (1);
	return (0);
}

void	ft_load_images_bonus(t_data *data, t_graph *mlx)
{
	if (check_png_ext(data->so) || check_png_ext(data->no) || \
		check_png_ext(data->we) || check_png_ext(data->ea))
		ft_exit_bonus(data, "Error:\nFile \".png\" not found!\n", 1);
	mlx->south = mlx_load_png(data->so);
	if (!mlx->south)
		ft_exit_bonus(data, "Error:\nLoading images failed!1 not size\n", 1);
	if (!mlx->south || mlx->south->width != TEXT_WIDTH || \
	mlx->south->height != TEXT_HEIGH)
		ft_exit_bonus(data, "Error:\nLoading images failed!1\n", 1);
	mlx->north = mlx_load_png(data->no);
	if (!mlx->north || mlx->north->width != TEXT_WIDTH || \
	mlx->north->height != TEXT_HEIGH)
		ft_exit_bonus(data, "Error:\nLoading images failed!2\n", 1);
	mlx->west = mlx_load_png(data->we);
	if (!mlx->west || mlx->west->width != TEXT_WIDTH || \
	mlx->west->height != TEXT_HEIGH)
		ft_exit_bonus(data, "Error:\nLoading images failed!3\n", 1);
	mlx->east = mlx_load_png(data->ea);
	if (!mlx->east || mlx->east->width != TEXT_WIDTH || \
	mlx->east->height != TEXT_HEIGH)
		ft_exit_bonus(data, "Error:\nLoading images failed!4\n", 1);
}
