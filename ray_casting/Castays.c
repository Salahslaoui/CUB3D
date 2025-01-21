/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Castays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:31:59 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/20 01:52:15 by sslaoui          ###   ########.fr       */
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

void HorizontalIntersection(t_data *data, t_rays *ray, t_facing *facing)
{
	double		nextHTouchX;
	double		nextHTouchY;
	
	ray->horz_wallhitx = 0;
	ray->horz_wallhity = 0;
	ray->horz_wallhit = false;
	ray->yintercept = floor(data->player->pl_y / SQUER) * SQUER;
	if (facing->facing_down == 1)
		ray->yintercept += SQUER;
	ray->xintercept = data->player->pl_x + ((ray->yintercept - data->player->pl_y) / tan(ray->ray_ang));
	ray->ystep = SQUER;
	if (facing->facing_up)
		ray->ystep *= -1;
	ray->xstep = SQUER / tan(ray->ray_ang);
	if (facing->facing_left && ray->xstep > 0)
		ray->xstep *= -1;
	if (facing->facing_right && ray->xstep < 0)
		ray->xstep *= -1;
	nextHTouchX = ray->xintercept;
	nextHTouchY = ray->yintercept;
	int var = 0;
	if (facing->facing_up)
		var = 1;
	while (nextHTouchX >= 0 && nextHTouchY >= 0 && nextHTouchX <= ((data->weight - 1) * SQUER) && nextHTouchY <= ((data->height - 1) * SQUER))
	{
		if (wallcheckers(data, nextHTouchX, nextHTouchY - var))
		{
			ray->horz_wallhit = true;
			ray->horz_wallhitx = nextHTouchX;
			ray->horz_wallhity = nextHTouchY;
			break;
		}
		else
		{
			nextHTouchX += ray->xstep;
			nextHTouchY += ray->ystep;
		}
	}
}
void VerticalIntersection(t_data *data, t_rays *ray, t_facing *facing)
{
	double		nextVTouchX;
	double		nextVTouchY;
	
	ray->vert_wallhitx = 0;
	ray->vert_wallhity = 0;
	ray->vert_wallhit = false;

	ray->xintercept = floor(data->player->pl_x / SQUER) * SQUER;
	if (facing->facing_right == 1)
		ray->xintercept += SQUER;
	ray->yintercept = data->player->pl_y + ((ray->xintercept - data->player->pl_x) * tan(ray->ray_ang));
	ray->xstep = SQUER;
	if (facing->facing_left)
		ray->xstep *= -1;
	ray->ystep = SQUER * tan(ray->ray_ang);
	if (facing->facing_up && ray->ystep > 0)
		ray->ystep *= -1;
	if (facing->facing_down && ray->ystep < 0)
		ray->ystep *= -1;
	nextVTouchX = ray->xintercept;
	nextVTouchY = ray->yintercept;
	int var = 0;
	if (facing->facing_left)
		var = 1;
	while (nextVTouchX >= 0 && nextVTouchY >= 0 && nextVTouchX <= ((data->weight - 1) * SQUER) && nextVTouchY <= ((data->height - 1) * SQUER))
	{
		if (wallcheckers(data, nextVTouchX - var, nextVTouchY))
		{
			ray->vert_wallhit = true;
			ray->vert_wallhitx = nextVTouchX;
			ray->vert_wallhity = nextVTouchY;
			break;
		}
		else
		{
			nextVTouchX += ray->xstep;
			nextVTouchY += ray->ystep;
		}
	}
}

double GetDistence(double x0, double y0, double x1, double y1)
{
	double value = pow((x1 - x0), 2) + pow((y1 - y0), 2);
	return (sqrt(value));
}

void Cast(t_data *data, int ColumId)
{
	t_facing		facing;
	float		Hdistance = 214748364777777;
	float		Vdistance = 214748364777777;
	
	data->view[ColumId].facing = &facing;
	data->view[ColumId].wasHitVert = false;
	RayFacing(&data->view[ColumId], &facing);
	HorizontalIntersection(data, &data->view[ColumId], &facing);
	VerticalIntersection(data, &data->view[ColumId], &facing);
	t_player	*player = data->player;
	if (data->view[ColumId].horz_wallhit == true)
		Hdistance = GetDistence(player->pl_x, player->pl_y, data->view[ColumId].horz_wallhitx, data->view[ColumId].horz_wallhity);
	if (data->view[ColumId].vert_wallhit == true)
		Vdistance = GetDistence(player->pl_x, player->pl_y, data->view[ColumId].vert_wallhitx, data->view[ColumId].vert_wallhity);
	data->view[ColumId].destinationX = data->view[ColumId].vert_wallhitx;
	data->view[ColumId].destinationY = data->view[ColumId].vert_wallhity;
	data->view[ColumId].distance = Vdistance;
	if (Hdistance <= Vdistance)
	{
		data->view[ColumId].destinationX = data->view[ColumId].horz_wallhitx;
		data->view[ColumId].destinationY = data->view[ColumId].horz_wallhity;
		data->view[ColumId].distance = Hdistance;
	}
	if (Hdistance > Vdistance)
		data->view[ColumId].wasHitVert = true;	
}


void CastAllRays(t_data *data, t_player *player)
{
	int ColumId = 0;
	float	ang;
	float	plus;
	//int		i;

	plus = degree_radian(FOV_ANG, 0) / RAY_NBR;
	ang = player->rot_angel - (degree_radian(FOV_ANG, 0) / 2);
	while (ColumId < RAY_NBR)
	{
		//data->view[ColumId].ray_ang = (player->rot_angel - (degree_radian(FOV_ANG, 0) / 2)) + (ColumId * plus);
		data->view[ColumId].ray_ang = ang;
		data->view[ColumId].ray_ang = NormalizeAngle(data->view[ColumId].ray_ang);
		Cast(data, ColumId);
		ang += degree_radian(FOV_ANG, 0) / RAY_NBR;
		ColumId++;
	}
	//i = -1;
	//while (++i < (RAY_NBR))
	//	bresenham(player->pl_y, player->pl_x, data->view[i].destinationY, data->view[i].destinationX, data);
}
