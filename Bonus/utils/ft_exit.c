/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:03 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/03 08:50:56 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free(map);
	map = NULL;
}

void	ft_put_error(char *error)
{
	int		i;

	i = -1;
	if (!error)
		return ;
	while (error && error[++i])
		write(2, &error[i], 1);
}

void	ft_exit(t_data *data, char *error, int exit_value)
{
	ft_put_error(error);
	if (data->map)
		free_map(data->map);
	if (data->view)
		free(data->view);
	if (data->mlx->mlx)
		mlx_terminate(data->mlx->mlx);
	if (data->NO)
		free(data->NO);
	if (data->SO)
		free(data->SO);
	if (data->WE)
		free(data->WE);
	if (data->EA)
		free(data->EA);
	exit (exit_value);
}
