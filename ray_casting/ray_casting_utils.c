/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:33:37 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/03 12:02:20 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_check_wall(t_data *data, double x, double y)
{
	int i = y / SQUER;
	int j = x / SQUER;
	if (x >= data->weight * SQUER || y >= data->height * SQUER || x < 0 || y < 0)
		return 1;
	int q = data->player->pl_x / SQUER;
	int w = data->player->pl_y / SQUER;
	if ((data->map[i][q] && data->map[i][q] == '1') || (data->map[w][j] && data->map[w][j] == '1'))
		return 1;
	if (data->map && data->map[i] && data->map[i][j] && data->map[i][j] == '1')
		return 1;
	return 0;
}

double degree_radian(double degree, int type)
{
	if (!type) // type == 0 => degree to rad
		return (degree * (M_PI / 180));
	return (degree * (180 / M_PI));
}

double normalaize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	else if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return angle;
}

void ft_release_keys(t_data *data)
{
	t_player *player = data->player;
	
	//if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_ESCAPE))
	//	exit (0);
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP))
		player->walk_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
		player->walk_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
		player->turn_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
		player->turn_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_W))
		player->walk_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_D))
		player->walk_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_A))
		player->walk_dir = 0;
		//player->turn_dir = 0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
		player->turn_dir = 0;
}

//static void bresenham_con(t_data *data, int x, int y, t_bres *bres)
//{
//	while (true)
//	{
//		mlx_put_pixel(data->mlx->image, x, y, 0xFF6700FF);
//		bres->e2 = 2 * bres->err;
//		if (bres->e2 > -bres->dy)
//		{
//			bres->err -= bres->dy;
//			x += bres->sx;
//		}
//		if (bres->e2 < bres->dx)
//		{
//			bres->err += bres->dx;
//			y += bres->sy; 
//		}
//		if ( x < 0 || y < 0 || x > data->weight * SQUER || y > data->height * SQUER || (x == data->player->d_x && y == data->player->d_y))
//			break ;
//	}
//}
//void bresenham(t_data *data, int x, int y)
//{
//	t_bres bres;

//	data->bres = &bres;
//	if (x < 0 || y < 0)
//		return ;
//	bres.dx = abs((int)data->player->d_x - x);
//	bres.dy = abs((int)data->player->d_y - y);
//	bres.sx = 1;
//	bres.sy = 1;
//	if (data->player->d_x > x)
//		bres.sx = -1;
//	if (data->player->d_y > y)
//		bres.sy = -1;
//	bres.err = bres.dx - bres.dy;
//	bresenham_con(data, x, y, &bres);
//    ft_release_keys(data);
//}

int wallcheckers(t_data *data, int x, int y)
{
	int i = floor(y / SQUER);
	int j = floor(x / SQUER);
	if (data->map[i][j] == '1')
		return 1;
	return 0;
}

void bresenham(int y0, int x0, int y1, int x1, t_data *exec)
{
    int dx;
    int dy;
    int sx ;
    int sy ;
    int err;
    int e2;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    if (x0 < x1)
        sx = 1;
    else 
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    err = dx - dy;
    if (x0 < 0 || y0 < 0)
	return;
    while (1)
    {
        mlx_put_pixel(exec->mlx->image, x0, y0, 0xFF6700FF);
        e2 = 2 * err;
        if (e2 > -dy)
        {
          	err -= dy;
          	x0 += sx;
        }
        if (e2 < dx)
         {
          	err += dx;
          	y0 += sy; 
        }
        if ((x0 < 0 || y0 < 0 || x0 > exec->weight * 32 || y0 > exec->height * 32 ||  (x0 == x1 && y0 == y1)))
            break;
    }
    ft_release_keys(exec);
}

//new line to new commit