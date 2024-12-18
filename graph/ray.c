/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:19:28 by sslaoui           #+#    #+#             */
/*   Updated: 2024/12/06 19:04:41 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (x * (data->bpp/8) + y * data->line_length);
	*(unsigned int *)dst = color;
}

void	render_cub(t_data *img, int	i, int	j, int x, int y, int z)
{
	i = x * 32;
	j = z * 32;
	while (i < (x + 1) * 32)
	{
		while (j < (z + 1) * 32)
		{
			put_pixel(img, j, i, y);
			j++;
		}
		j = z * 32;
		i++;
	}
	// *j = 0;
}

void	render_player(t_data *img, int i, int j, int x, int y, int z)
{
	int count;

	count = 0;
	i = x * 32;
	j = z * 32;
	while (i < (x + 1) * 32)
	{
		while (j < (z + 1) * 32)
		{
			put_pixel(img, j, i, y);
			j++;
		}
		j = z * 32;
		i++;
	}
	i = x * 32;
	j = z * 32;
}

void	rendering_2d(t_data *img, t_map *utils)
{
	(void)img;
	(void)utils;
	int	i;
	int	b;
	int	j;
	int	x;
	int	y;
	int	z;

	z = 0;
	i = 0;
	b = 0;
	j = 0;
	x = 0;
	y = 0;
	while (utils->map[i])
	{
		while (utils->map[i][j])
		{
			if (utils->map[i][j] == ' ')
			{
				j++;
				continue;
			}
			else if (utils->map[i][j] == 'N' || utils->map[i][j] == 'E' || utils->map[i][j] == 'W' || utils->map[i][j] == 'S')
				render_player(img, x, y, i, 0x000000FF, j);
			else if (utils->map[i][j] == '1')
				render_cub(img, x, y, i, 0x00FF0000, j);
			else if (utils->map[i][j] == '0')
				render_cub(img, x, y, i, 0x000000FF, j);
			j++;
			b++;
		}
		j = 0;
		i++;
	}
}

// int	key_hook(int keycode, t_map *utils)
// {
// 	void	*handle;
// 	void	(*plug_ptr)(t_map *utils);

// 	if (keycode == 1)
// 	{
// 		system("make");
// 		handle = dlopen("libplug.so", RTLD_NOW);
// 		// plug_hello();
// 		plug_ptr = dlsym(handle, "plug_hello");
// 		plug_ptr(&utils);
// 		printf("\n%p ----- %p\n", handle, plug_ptr);
// 		dlclose(handle);
// 	}
// }

int	key_par(int keycode, t_map *utils)
{
	(void)utils;
	keycode = ' ';
	if (keycode == ' ')
	{
		system("make");
		utils->handle = dlopen("libplug.so", RTLD_NOW);
		utils->plug_ptr = dlsym(utils->handle, "plug_hello");
		printf("%p\n", utils->plug_ptr);
		utils->plug_ptr(utils);
		printf("\n%p ----- %p\n", utils->handle, utils->plug_ptr);
		dlclose(utils->handle);
		sleep(1);
	}
	return (0);
}

int	hook(t_map *utils)
{
	mlx_hook(utils->mlx_win, 2, 0, key_par, utils);
	mlx_clear_window(utils->mlx, utils->mlx_win);
	rendering_2d(utils->img, utils);
	mlx_put_image_to_window(utils->mlx, utils->mlx_win, utils->img->img, 0, 0);
	return (0);
}

void	pixels_rendering(t_map *utils)
{
	// (void)utils;
	t_data	img;
	int	t_cub;
	int	key;

	key = 0;
	utils->img = &img;
	t_cub = 32;
	utils->mlx = mlx_init();
	utils->mlx_win = mlx_new_window(utils->mlx, 1920, 1080, "CUB3D");
	img.img = mlx_new_image(utils->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	// mlx_key_hook(mlx_win, );
	// put_pixel(&img, 5, 5, 0x00FF0000);
	// put_pixel(&img, 6, 5, 0x00FF0000);
	// put_pixel(&img, 7, 5, 0x00FF0000);
	// put_pixel(&img, 8, 5, 0x00FF0000);
	// put_pixel(&img, 9, 5, 0x00FF0000);
	// put_pixel(&img, 10, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop_hook(utils->mlx, hook, utils);
	mlx_loop(utils->mlx);
}
