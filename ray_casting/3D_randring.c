/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_randring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:24:29 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/22 19:57:50 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	rgb_convert(unsigned int cl)
{
	unsigned int R;
	unsigned int G;
	unsigned int B;
	unsigned int A;

	R = (cl >> 16) & 0xFF;
	G = (cl >> 8) & 0xFF;
	B = (cl) & 0xFF;
	A = (cl >> 24) & 0xFF;
	return ((B << 24) | (G << 16) | (R << 8) | (A));
}

void PutLine(t_data *data, int x, double w_height)
{
	long			i;
	int			dist;
	int			offx;
	int			offy;
	unsigned int	*tex_pxl;
	unsigned int	text;

	if (data->view[x].wasHitVert == true)
		offx = (int)data->view[x].destinationY % TAIL;
	else
		offx = (int)data->view[x].destinationX % TAIL;
	i = data->view[x].Up - 1;
	while (++i < data->view[x].Down)
	{
		dist = i + (w_height / 2) - (HEIGHT / 2);
		offy = dist * ((float)TEXT_WIDTH/ w_height);
		tex_pxl = (unsigned int *)data->mlx->la->pixels;
		text = rgb_convert(tex_pxl[(SQUER * offy) + offx]);
			mlx_put_pixel(data->mlx->project, x, i, text);
	}
}

void ft_fill_project(t_data *data, t_graph *mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WEIGHT)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(mlx->project, j, i, 0x2f3e46FF);
			else
				mlx_put_pixel(data->mlx->project, j, i, 0xcad2c5FF);
		}
		i++;
	}
}

void ft_init_la_ptr(t_rays *ray, t_data *data)
{
	if (ray->wasHitVert == true)
	{
		if (ray->ray_ang > M_PI_2 && ray->ray_ang < 3 * M_PI_2)
			data->mlx->la = data->mlx->N;
		else
			data->mlx->la = data->mlx->S;
	}
	else
	{
		if (ray->ray_ang > 0 && ray->ray_ang < M_PI)
			data->mlx->la = data->mlx->E;
		else
			data->mlx->la = data->mlx->W;	
	}
}

void	Randring3D(t_data *data, t_player *player)
{
	double		wallheight;
	double		distanceprojection;
	int			i;

	ft_fill_project(data, data->mlx);
	i = -1;
	while (++i < RAY_NBR)
	{
		distanceprojection = (WEIGHT / 2) / tan(deg_to_rad(FOV_ANG) / 2);
		wallheight = (SQUER / (data->view[i].distance * \
		cos(data->view[i].ray_ang - player->rot_angel))) * \
		distanceprojection;
		data->view[i].Up = (HEIGHT / 2) - (wallheight / 2);
		if (data->view[i].Up < 0)
			data->view[i].Up = 0;
		data->view[i].Down = ((HEIGHT / 2) - \
		(wallheight / 2)) + wallheight;
		if (data->view[i].Down > HEIGHT)
			data->view[i].Down = HEIGHT;
		ft_init_la_ptr(&data->view[i], data);
		PutLine(data, i, wallheight);
	}
}
