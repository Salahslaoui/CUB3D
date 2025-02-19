/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:21:14 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:39:49 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	space_skip_bonus(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	space_skip_2_bonus(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i] || str[i] == '\n')
		return (1);
	return (0);
}

int	ptr_c_bonus(char **ptr)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (ptr[i])
	{
		l = 0;
		j = 0;
		while (ptr[i][j] && ptr[i][j] == ' ')
			j++;
		if (!ptr[i][j])
			return (1);
		while (ptr[i][j] >= '0' && ptr[i][j] <= '9')
		{
			l = 1;
			j++;
		}
		while (ptr[i][j] && ptr[i][j] == ' ')
			j++;
		if (ptr[i][j] >= '0' && ptr[i][j] <= '9')
			return (1);
		i++;
	}
	return (0);
}
