/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_randring_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:24:29 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/17 14:30:00 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

unsigned int	rgb_convert_bonus(unsigned int cl)
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
	unsigned int		a;

	r = (cl >> 16) & 0xFF;
	g = (cl >> 8) & 0xFF;
	b = (cl) & 0xFF;
	a = (cl >> 24) & 0xFF;
	return ((b << 24) | (g << 16) | (r << 8) | (a));
}

void	putline_bonus(t_data *data, int x, double w_height)
{
	long			i;
	int				dist;
	unsigned int	*tex_pxl;
	unsigned int	text;

	if (data->view[x].washitvert == true)
		data->view[x].offx = (int)data->view[x].destinationy % TAIL;
	else
		data->view[x].offx = (int)data->view[x].destinationx % TAIL;
	i = data->view[x].up - 1;
	while (++i < data->view[x].down)
	{
		dist = i + (w_height / 2) - (HEIGHT / 2);
		data->view[x].offy = dist * ((float)TEXT_WIDTH / w_height);
		tex_pxl = (unsigned int *)data->mlx->la->pixels;
		text = rgb_convert_bonus(tex_pxl[(SQUER * data->view[x].offy) + \
		data->view[x].offx]);
		mlx_put_pixel(data->mlx->project, x, i, text);
	}
}

void	ft_fill_project_bonus(t_data *data, t_graph *mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WEIGHT)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(mlx->project, j, i, data->c_rgb);
			else
				mlx_put_pixel(data->mlx->project, j, i, data->f_rgb);
			j++;
		}
		i++;
	}
}

void	ft_init_la_ptr_bonus(t_rays *ray, t_data *data)
{
	if (ray->washitvert == true)
	{
		if (ray->ray_ang > M_PI_2 && ray->ray_ang < 3 * M_PI_2)
			data->mlx->la = data->mlx->west;
		else
			data->mlx->la = data->mlx->east;
	}
	else
	{
		if (ray->ray_ang > 0 && ray->ray_ang < M_PI)
			data->mlx->la = data->mlx->south;
		else
			data->mlx->la = data->mlx->north;
	}
}

static void put_door(t_data *data, int x, int wallheight)
{
	int i = data->view[x].up - 1;
	(void)wallheight;
	while (++i < data->view[x].down)
	{
		mlx_put_pixel(data->mlx->project, x, i, 0x854836FF);
	}
}

void	randring3d_bonus(t_data *data, t_player *player)
{
	double		wallheight;
	double		distanceprojection;
	int			i;

	(void)player;
	ft_fill_project_bonus(data, data->mlx);
	i = -1;
	while (++i < RAY_NBR)
	{
		distanceprojection = (WEIGHT / 2) / tan(deg_to_rad_bonus(FOV_ANG) / 2);
		wallheight = (SQUER / (data->view[i].distance * \
		cos(data->view[i].ray_ang - player->rot_angel))) * \
		distanceprojection;
		data->view[i].up = (HEIGHT / 2) - (wallheight / 2);
		if (data->view[i].up < 0)
			data->view[i].up = 0;
		data->view[i].down = ((HEIGHT / 2) - \
		(wallheight / 2)) + wallheight;
		if (data->view[i].down > HEIGHT)
			data->view[i].down = HEIGHT;
		ft_init_la_ptr_bonus(&data->view[i], data);
		if (data->map[(int)(data->view[i].destinationy / SQUER)][(int)(data->view[i].destinationx / SQUER)] != '2')
			putline_bonus(data, i, wallheight);
		else
			put_door(data, i, wallheight);
	}
}
