/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_randring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:24:29 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/20 21:56:25 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//void PutLine(t_data *data, float Up, float Down, int x)
//{
//	long		i;

//	i = Up - 1;
//	while (++i < Down)
//	{
//		if (data->view[x].wasHitVert == true)	
//			mlx_put_pixel(data->mlx->project, x, i, 0x84a98cFF);
//		else if (data->view[x].wasHitVert == false)
//			mlx_put_pixel(data->mlx->project, x, i, 0x52796fFF);
//	}
//}
//void ft_fill_project(t_data *data, t_graph *mlx)
//{
//	int i = 0;
//	int j = 0;
//	(void)data;
//	while (i < HEIGHT)
//	{
//		j = -1;
//		while (++j < WEIGHT)
//		{
//			if (i < HEIGHT / 2)
//				mlx_put_pixel(mlx->project, j, i, data->C_rgb);
//			else
//				mlx_put_pixel(mlx->project, j, i, data->F_rgb);
//		}
//		i++;
//	}
//}

//void	Randring3D(t_data *data, t_player *player)
//{
//	float		wallheight;
//	float		distanceprojection;
//	float			Up;
//	float			Down;
//	int			i;

//	ft_fill_project(data, data->mlx);
//	i = -1;
//	while (++i < RAY_NBR)
//	{
//		distanceprojection = (WEIGHT / 2) / tan(degree_radian(FOV_ANG, 0) / 2);
//		wallheight = (SQUER / (data->view[i].distance * cos(data->view[i].ray_ang - player->rot_angel))) * distanceprojection;
//		Up = (HEIGHT / 2) - (wallheight / 2);
//		if (Up < 0)
//			Up = 0;
//		Down = ((HEIGHT / 2) - (wallheight / 2)) + wallheight;
//		if (Down > HEIGHT)
//			Down = HEIGHT;
//		PutLine(data, Up, Down, i);
//	}
//}







//int	get_pixel_color(mlx_image_t *image, unsigned char *pixel, int x, int y)
//{
//	if (x < 0 || x >= (int)image->width || y < 0 || y >= (int)image->height)
//		return (0);
//	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
//}

//void PutLine(t_data *data, float Up, float Down, int x, float wallheight)
//{
//	long		i;

//	i = Up - 1;
//	int wall_to_pixel = (HEIGHT / 2) - (wallheight / 2);
//	if (wall_to_pixel < 0)
//		wall_to_pixel = 0;
//	int wall_to_pixel2 = (HEIGHT / 2) + (wallheight / 2);
//	if (wall_to_pixel2 > HEIGHT)
//		wall_to_pixel2 = HEIGHT;
//	int offset_x, offset_y;
//	int dst_from_top;

//	int pixel;
//	(void)Down;
//	if (data->view[x].wasHitVert)
//		offset_x = (int)data->view[x].destinationY % TAIL;
//	else
//		offset_x = (int)data->view[x].destinationX % TAIL;
//	unsigned char *color;
//	while (wall_to_pixel < wall_to_pixel2)
//	{
//		dst_from_top = wall_to_pixel + (wallheight / 2) - (HEIGHT / 2);
//		offset_y = dst_from_top * ((float)TAIL / wallheight);
//		offset_x %= TAIL;
//		offset_y %= TAIL;
//		color = &data->mlx->textute->pixels[(offset_y / 64 + offset_x) * 4];
//		pixel = get_pixel_color(data->mlx->textute, color, offset_x, offset_y);
//		//printf("[%d]\n", wall_to_pixel);
//		mlx_put_pixel(data->mlx->project, x, wall_to_pixel, pixel);
//		wall_to_pixel++;
//		//if (data->view[x].wasHitVert == true)	
//		//	mlx_put_pixel(data->mlx->project, x, i, 0x84a98cFF);
//		//else if (data->view[x].wasHitVert == false)
//		//	mlx_put_pixel(data->mlx->project, x, i, 0x52796fFF);
//	}
//}
//void ft_fill_project(t_data *data, t_graph *mlx)
//{
//	int i = 0;
//	int j = 0;
//	(void)data;
//	while (i < HEIGHT)
//	{
//		j = -1;
//		while (++j < WEIGHT)
//		{
//			if (i < HEIGHT / 2)
//				mlx_put_pixel(mlx->project, j, i, data->C_rgb);
//			else
//				mlx_put_pixel(mlx->project, j, i, data->F_rgb);
//		}
//		i++;
//	}
//}

//void	Randring3D(t_data *data, t_player *player)
//{
//	float		wallheight;
//	float		distanceprojection;
//	float			Up;
//	float			Down;
//	int			i;

//	ft_fill_project(data, data->mlx);
//	i = -1;
//	while (++i < RAY_NBR)
//	{
//		distanceprojection = (WEIGHT / 2) / tan(degree_radian(FOV_ANG, 0) / 2);
//		wallheight = (SQUER / (data->view[i].distance * cos(data->view[i].ray_ang - player->rot_angel))) * distanceprojection;
//		Up = (HEIGHT / 2) - (wallheight / 2);
//		if (Up < 0)
//			Up = 0;
//		Down = ((HEIGHT / 2) - (wallheight / 2)) + wallheight;
//		if (Down > HEIGHT)
//			Down = HEIGHT;
//		PutLine(data, Up, Down, i, wallheight);
//	}
//}




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

void PutLine(t_data *data, long Up, long Down, int x, uint32_t *wall, double w_height, mlx_image_t *los)
{
	long		i;
	long		j;
	int			dist;
	int			offx;
	int			offy;
	unsigned int *tex_pxl;
	unsigned int	text;
	(void)wall;
	(void) los;

	j = 0;
	if (data->view[x].wasHitVert == true)
		offx = (int)data->view[x].destinationY % TAIL;
	else
		offx = (int)data->view[x].destinationX % TAIL;
	i = Up - 1;
	while (++i < Down)
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
	int i = 0;
	int j = 0;
	(void)data;
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WEIGHT)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(mlx->project, j, i, 0x2f3e46FF);
			else
				mlx_put_pixel(mlx->project, j, i, 0xcad2c5FF);
		}
		i++;
	}
}

void	Randring3D(t_data *data, t_player *player)
{
	double		wallheight;
	double		distanceprojection;
	long			Up;
	long			Down;
	int			i;
	uint32_t	*walltexture;
	mlx_image_t	*los = NULL;

	walltexture = NULL;
	// walltexture = malloc(sizeof(uint32_t) * TEXT_HEIGH * TEXT_WIDTH);
	ft_fill_project(data, data->mlx);
	i = -1;
	while (++i < RAY_NBR)
	{
		distanceprojection = (WEIGHT / 2) / tan(degree_radian(FOV_ANG, 0) / 2);
		wallheight = (SQUER / (data->view[i].distance * cos(data->view[i].ray_ang - player->rot_angel))) * distanceprojection;
		Up = (HEIGHT / 2) - (wallheight / 2);
		if (Up < 0)
			Up = 0;
		Down = ((HEIGHT / 2) - (wallheight / 2)) + wallheight;
		if (Down > HEIGHT)
			Down = HEIGHT;
		if (data->view[i].wasHitVert == true)
		{
			if (data->view[i].ray_ang > M_PI_2 && data->view[i].ray_ang < 3 * M_PI_2)
				data->mlx->la = data->mlx->N;
			else
				data->mlx->la = data->mlx->S;
		}
		else
		{
			if (data->view[i].ray_ang > 0 && data->view[i].ray_ang < M_PI)
				data->mlx->la = data->mlx->E;
			else
				data->mlx->la = data->mlx->W;	
		}
		//data->mlx->textute = mlx_texture_to_image(data->mlx->mlx, data->mlx->la);
		PutLine(data, Up, Down, i, walltexture, wallheight, los);
	}
}
