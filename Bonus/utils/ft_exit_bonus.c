/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:03 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/17 13:51:20 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_map_bonus(char **map)
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

void	ft_put_error_bonus(char *error)
{
	int		i;

	i = -1;
	if (!error)
		return ;
	while (error && error[++i])
		write(2, &error[i], 1);
}

void	ft_exit_bonus(t_data *data, char *error, int exit_value)
{
	ft_put_error_bonus(error);
	if (data->map)
		free_map_bonus(data->map);
	if (data->view)
		free(data->view);
	if (data->mlx->mlx)
		mlx_terminate(data->mlx->mlx);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	exit (exit_value);
}
