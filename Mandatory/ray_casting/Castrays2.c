/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Castrays2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:37:20 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/26 16:39:06 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rayfacing(t_rays *ray, t_facing *facing)
{
	facing->facing_down = 0;
	facing->facing_left = 0;
	facing->facing_right = 0;
	facing->facing_up = 0;
	if (ray->ray_ang > 0 && ray->ray_ang < M_PI)
		facing->facing_down = 1;
	else
		facing->facing_up = 1;
	if (ray->ray_ang >= (M_PI / 2) && ray->ray_ang <= (3 * M_PI) / 2)
		facing->facing_left = 1;
	else
		facing->facing_right = 1;
}

static void	init_horizontal_intersection(t_data *data, t_rays *ray, \
t_facing *facing)
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
	ray->nexthtouch_x = ray->xintercept;
	ray->nexthtouch_y = ray->yintercept;
}

void	horizontal_intersection(t_data *data, t_rays *ray, t_facing *facing)
{
	int			var;

	var = 0;
	init_horizontal_intersection(data, ray, facing);
	if (facing->facing_up)
		var = 1;
	while (ray->nexthtouch_x >= 0 && ray->nexthtouch_y >= 0 && \
	ray->nexthtouch_x <= ((data->weight - 1) * SQUER) && \
	ray->nexthtouch_y <= ((data->height - 1) * SQUER))
	{
		if (wallcheckers(data, ray->nexthtouch_x, ray->nexthtouch_y - var))
		{
			ray->horz_wallhit = true;
			ray->horz_wallhitx = ray->nexthtouch_x;
			ray->horz_wallhity = ray->nexthtouch_y;
			break ;
		}
		else
		{
			ray->nexthtouch_x += ray->xstep;
			ray->nexthtouch_y += ray->ystep;
		}
	}
}

static void	init_vertical_intersection(t_data *data, \
t_rays *ray, t_facing *facing)
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
	ray->nextvtouch_x = ray->xintercept;
	ray->nextvtouch_y = ray->yintercept;
}

void	vertical_intersection(t_data *data, t_rays *ray, t_facing *facing)
{
	int		var;

	var = 0;
	init_vertical_intersection(data, ray, facing);
	if (facing->facing_left)
		var = 1;
	while (ray->nextvtouch_x >= 0 && ray->nextvtouch_y >= 0 && \
	ray->nextvtouch_x <= ((data->weight - 1) * SQUER) && \
	ray->nextvtouch_y <= ((data->height - 1) * SQUER))
	{
		if (wallcheckers(data, ray->nextvtouch_x - var, ray->nextvtouch_y))
		{
			ray->vert_wallhit = true;
			ray->vert_wallhitx = ray->nextvtouch_x;
			ray->vert_wallhity = ray->nextvtouch_y;
			break ;
		}
		else
		{
			ray->nextvtouch_x += ray->xstep;
			ray->nextvtouch_y += ray->ystep;
		}
	}
}
