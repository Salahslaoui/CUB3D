/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:33:37 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/17 14:31:47 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_check_wall_bonus(t_data *data, double x, double y)
{
	int		i;
	int		j;
	int		q;
	int		w;

	i = y / SQUER;
	j = x / SQUER;
	if (x >= data->weight * SQUER || y >= data->height * SQUER || \
	x < 0 || y < 0)
		return (1);
	q = data->player->pl_x / SQUER;
	w = data->player->pl_y / SQUER;
	if ((data->map[i][q] && (data->map[i][q] == '1' || data->map[i][q] == '2')) || \
	(data->map[w][j] && (data->map[w][j] == '1' || data->map[w][j] == '2')))
		return (1);
	if (data->map && data->map[i] && data->map[i][j] && (data->map[i][j] == '1' || data->map[i][j] == '2'))
		return (1);
	return (0);
}

double	deg_to_rad_bonus(double degree)
{
	return (degree * (M_PI / 180));
}

double	normalaize_angle_bonus(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	else if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	wallcheckers_bonus(t_data *data, int x, int y)
{
	int			i;
	int			j;

	i = floor(y / SQUER);
	j = floor(x / SQUER);
	if (!data->map[i][j] || data->map[i][j] == '1' || data->map[i][j] == '2')
		return (1);
	return (0);
}
