/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:47:08 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:45:04 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	sides_map_bonus(char **map, int y)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	if (top_buttom_bonus(map, y, i) == 1)
		return (1);
	while (map[i])
	{
		while (map[i][j] == ' ')
			j++;
		if (j > 0 && !map[i][j])
			return (0);
		while (map[i][len])
			len++;
		if ((map[i][j] != '1' && map[i][j] != '\n') || \
			(len >= 2 && map[i][len - 2] != '1' && map[i][len - 2] != '\n'))
			return (1);
		i++;
		len = 0;
		j = 0;
	}
	return (0);
}

int	check_map2_bonus(char **map, int i, int j, int y)
{
	int	k;

	k = 0;
	if (i == y)
		return (0);
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'N' && \
	map[i - 1][j] != 'E' && map[i - 1][j] != 'W' && \
		map[i - 1][j] != 'S' && map[i - 1][j] != '0')
		return (1);
	if (j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != 'N' && \
		map[i][j - 1] != 'S' && \
		map[i][j - 1] != 'W' && map[i][j - 1] != 'E' && map[i][j - 1] != '0')
		return (1);
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'N' && \
		map[i + 1][j] != 'W' && map[i + 1][j] != 'E' && \
		map[i + 1][j] != 'S' && map[i + 1][j] != '0')
		return (1);
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'N' && \
		map[i][j + 1] != 'E' && map[i][j + 1] != 'W' && \
		map[i][j + 1] != 'S' && map[i][j + 1] != '0')
		return (1);
	return (0);
}

int	player_check_bonus(t_data *utils, int i, int j)
{
	if (utils->map[i][j + 1] != '1' && utils->map[i][j + 1] != '0')
		return (1);
	if (utils->map[i][j - 1] != '1' && utils->map[i][j - 1] != '0')
		return (1);
	if (utils->map[i + 1][j] != '1' && utils->map[i + 1][j] != '0')
		return (1);
	if (utils->map[i - 1][j] != '1' && utils->map[i - 1][j] != '0')
		return (1);
	return (0);
}

int	map_check_bonus(t_data *utils, int y, int i, int *j)
{
	char	m;

	if (!utils->map[i][*j])
		return (0);
	m = utils->map[i][*j];
	utils->first = *j;
	if (m == 'N' || m == 'E' || m == 'W' || m == 'S')
	{
		if (player_check_bonus(utils, i, *j) == 1)
			return (1);
		utils->count++;
	}
	if (utils->count > 1)
		return (1);
	if (m == '0')
	{
		if (check_map2_bonus(utils->map, i, *j, y) == 1)
			return (1);
	}
	else if (m != '1' && m != '\n' && m != 'N' && m != 'S' && \
		m != 'W' && m != 'E')
		return (1);
	(*j)++;
	return (0);
}

int	check_map_bonus(t_data *utils, int y)
{
	int	count;
	int	first;
	int	i;
	int	j;

	count = 0;
	first = 0;
	i = 1;
	j = 0;
	if (sides_map_bonus(utils->map, y) == 1)
		return (1);
	while (utils->map[i - 1] && utils->map[i])
	{
		while (utils->map[i][j])
		{
			while (utils->map[i][j] == ' ')
				j++;
			if (map_check_bonus(utils, y, i, &j) == 1)
				return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}
