/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Castrays_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:31:59 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/17 13:38:29 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

double	normalize_angle_bonus(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

double	get_distence_bonus(double x0, double y0, double x1, double y1)
{
	double		value;

	value = pow((x1 - x0), 2) + pow((y1 - y0), 2);
	return (sqrt(value));
}

void	cast_bonus(t_data *data, int i, float Hdistance, float Vdistance)
{
	t_facing		facing;

	data->view[i].facing = &facing;
	data->view[i].washitvert = false;
	rayfacing_bonus(&data->view[i], &facing);
	horizontal_intersection_bonus(data, &data->view[i], &facing);
	vertical_intersection_bonus(data, &data->view[i], &facing);
	if (data->view[i].horz_wallhit == true)
		Hdistance = get_distence_bonus(data->player->pl_x, data->player->pl_y, \
		data->view[i].horz_wallhitx, data->view[i].horz_wallhity);
	if (data->view[i].vert_wallhit == true)
		Vdistance = get_distence_bonus(data->player->pl_x, data->player->pl_y, \
		data->view[i].vert_wallhitx, data->view[i].vert_wallhity);
	data->view[i].destinationx = data->view[i].vert_wallhitx;
	data->view[i].destinationy = data->view[i].vert_wallhity;
	data->view[i].distance = Vdistance;
	if (Hdistance <= Vdistance)
	{
		data->view[i].destinationx = data->view[i].horz_wallhitx;
		data->view[i].destinationy = data->view[i].horz_wallhity;
		data->view[i].distance = Hdistance;
	}
	if (Hdistance > Vdistance)
		data->view[i].washitvert = true;
}

void	cast_all_rays_bonus(t_data *data, t_player *player)
{
	int		index;
	float	ang;

	index = 0;
	ang = player->rot_angel - (deg_to_rad_bonus(FOV_ANG) / 2);
	while (index < RAY_NBR)
	{
		data->view[index].ray_ang = ang;
		data->view[index].ray_ang = normalize_angle_bonus(data->view[index].ray_ang);
		cast_bonus(data, index, 214748364777777, 214748364777777);
		ang += deg_to_rad_bonus(FOV_ANG) / RAY_NBR;
		index++;
	}
}
