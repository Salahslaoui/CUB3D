/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:03 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/31 16:32:52 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	//you should to free all allocated mumbers her;
	if (data->map)
		free_map(data->map);
	if (data->view)
		free(data->view);
	if (data->mlx->mlx)
		mlx_terminate(data->mlx->mlx);
	ft_put_error(error);
	exit (exit_value);
}
