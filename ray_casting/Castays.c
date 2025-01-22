/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Castays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:31:59 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/22 19:56:47 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double NormalizeAngle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return angle;
}

void RayFacing(t_rays *ray, t_facing *facing)
{
	facing->facing_down = 0;
	facing->facing_left = 0;
	facing->facing_right = 0;
	facing->facing_up = 0;
	if (ray->ray_ang > 0 && ray->ray_ang < M_PI)
		facing->facing_down = 1;
	else
		facing->facing_up = 1;
	if(ray->ray_ang >= (M_PI / 2) && ray->ray_ang <= (3 * M_PI) / 2)
		facing->facing_left = 1;
	else
		facing->facing_right = 1;
}

void init_horizontal_intersection(t_data *data, t_rays *ray, t_facing *facing)
{
	ray->horz_wallhitx = 0;
	ray->horz_wallhity = 0;
	ray->horz_wallhit = false;
	ray->yintercept = floor(data->player->pl_y / SQUER) * SQUER;
	if (facing->facing_down == 1)
		ray->yintercept += SQUER;
	ray->xintercept = data->player->pl_x + \
	((ray->yintercept - data->player->pl_y) / tan(ray->ray_ang));
	ray->ystep = SQUER;
	if (facing->facing_up)
		ray->ystep *= -1;
	ray->xstep = SQUER / tan(ray->ray_ang);
	if (facing->facing_left && ray->xstep > 0)
		ray->xstep *= -1;
	if (facing->facing_right && ray->xstep < 0)
		ray->xstep *= -1;
	ray->nextHTouchX = ray->xintercept;
	ray->nextHTouchY = ray->yintercept;
}

void horizontal_intersection(t_data *data, t_rays *ray, t_facing *facing)
{
	int			var;
	
	var = 0;
	init_horizontal_intersection(data, ray, facing);
	if (facing->facing_up)
		var = 1;
	while (ray->nextHTouchX >= 0 && ray->nextHTouchY >= 0 && \
	ray->nextHTouchX <= ((data->weight - 1) * SQUER) && \
	ray->nextHTouchY <= ((data->height - 1) * SQUER))
	{
		if (wallcheckers(data, ray->nextHTouchX, ray->nextHTouchY - var))
		{
			ray->horz_wallhit = true;
			ray->horz_wallhitx = ray->nextHTouchX;
			ray->horz_wallhity = ray->nextHTouchY;
			break;
		}
		else
		{
			ray->nextHTouchX += ray->xstep;
			ray->nextHTouchY += ray->ystep;
		}
	}
}

void init_vertical_intersection(t_data *data, t_rays *ray, t_facing *facing)
{
	ray->vert_wallhitx = 0;
	ray->vert_wallhity = 0;
	ray->vert_wallhit = false;
	ray->xintercept = floor(data->player->pl_x / SQUER) * SQUER;
	if (facing->facing_right == 1)
		ray->xintercept += SQUER;
	ray->yintercept = data->player->pl_y + \
	((ray->xintercept - data->player->pl_x) * tan(ray->ray_ang));
	ray->xstep = SQUER;
	if (facing->facing_left)
		ray->xstep *= -1;
	ray->ystep = SQUER * tan(ray->ray_ang);
	if (facing->facing_up && ray->ystep > 0)
		ray->ystep *= -1;
	if (facing->facing_down && ray->ystep < 0)
		ray->ystep *= -1;
	ray->nextVTouchX = ray->xintercept;
	ray->nextVTouchY = ray->yintercept;
}

void vertical_intersection(t_data *data, t_rays *ray, t_facing *facing)
{
	int		var;

	var = 0;
	init_vertical_intersection(data, ray, facing);
	if (facing->facing_left)
		var = 1;
	while (ray->nextVTouchX >= 0 && ray->nextVTouchY >= 0 && \
	ray->nextVTouchX <= ((data->weight - 1) * SQUER) && \
	ray->nextVTouchY <= ((data->height - 1) * SQUER))
	{
		if (wallcheckers(data, ray->nextVTouchX - var, ray->nextVTouchY))
		{
			ray->vert_wallhit = true;
			ray->vert_wallhitx = ray->nextVTouchX;
			ray->vert_wallhity = ray->nextVTouchY;
			break;
		}
		else
		{
			ray->nextVTouchX += ray->xstep;
			ray->nextVTouchY += ray->ystep;
		}
	}
}

double get_distence(double x0, double y0, double x1, double y1)
{
	double value = pow((x1 - x0), 2) + pow((y1 - y0), 2);
	return (sqrt(value));
}

void Cast(t_data *data, int i,float Hdistance, float Vdistance)
{
	t_facing		facing;
	
	data->view[i].facing = &facing;
	data->view[i].wasHitVert = false;
	RayFacing(&data->view[i], &facing);
	horizontal_intersection(data, &data->view[i], &facing);
	vertical_intersection(data, &data->view[i], &facing);
	t_player	*player = data->player;
	if (data->view[i].horz_wallhit == true)
		Hdistance = get_distence(player->pl_x, player->pl_y, \
		data->view[i].horz_wallhitx, data->view[i].horz_wallhity);
	if (data->view[i].vert_wallhit == true)
		Vdistance = get_distence(player->pl_x, player->pl_y, \
		data->view[i].vert_wallhitx, data->view[i].vert_wallhity);
	data->view[i].destinationX = data->view[i].vert_wallhitx;
	data->view[i].destinationY = data->view[i].vert_wallhity;
	data->view[i].distance = Vdistance;
	if (Hdistance <= Vdistance)
	{
		data->view[i].destinationX = data->view[i].horz_wallhitx;
		data->view[i].destinationY = data->view[i].horz_wallhity;
		data->view[i].distance = Hdistance;
	}
	if (Hdistance > Vdistance)
		data->view[i].wasHitVert = true;	
}


void CastAllRays(t_data *data, t_player *player)
{
	int		index;
	float	ang;
	float	plus;

	index = 0;
	plus = deg_to_rad(FOV_ANG) / RAY_NBR;
	ang = player->rot_angel - (deg_to_rad(FOV_ANG) / 2);
	while (index < RAY_NBR)
	{
		data->view[index].ray_ang = ang;
		data->view[index].ray_ang = NormalizeAngle(data->view[index].ray_ang);
		Cast(data, index, 214748364777777, 214748364777777);
		ang += deg_to_rad(FOV_ANG) / RAY_NBR;
		index++;
	}
}
