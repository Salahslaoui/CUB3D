/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:03 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/27 21:43:02 by ozahdi           ###   ########.fr       */
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
	ft_put_error(error);
	(void)data;
	exit (exit_value);
}
