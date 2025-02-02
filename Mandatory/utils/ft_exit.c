/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:03 by ozahdi            #+#    #+#             */
/*   Updated: 2025/02/02 21:43:34 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
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
