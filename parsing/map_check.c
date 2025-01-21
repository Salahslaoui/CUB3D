/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:47:08 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/21 19:47:09 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	space_skip(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\n' || !str[i])
		return (1);
	return (0);
}

int	sides_map(char **map, int y)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	if (top_buttom(map, y, i) == 1)
		return (1);
	while (map[i])
	{
		while (map[i][j] == ' ')
			j++;
		while (map[i][len])
			len++;
		if ((map[i][j] != '1' && map[i][j] != '\n') || \
			(map[i][len - 1] != '1' && map[i][len - 1] != '\n'))
			return (1);
		i++;
		len = 0;
		j = 0;
	}
	return (0);
}

int	check_map2(char **map, int i, int j, int y)
{
	int	k;

	k = 0;
	if (i == y)
		return (0);
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'N' && \
	map[i - 1][j] != 'E' && map[i - 1][j] != 'W' && 
		map[i - 1][j] != 'S' && map[i - 1][j] != '0')
		return (1);
	if (j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != 'N' && \
		map[i][j - 1] != 'S' && 
		map[i][j - 1] != 'W' && map[i][j - 1] != 'E' && map[i][j - 1] != '0')
		return (1);
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'N' && \
		map[i + 1][j] != 'W' && map[i + 1][j] != 'E' && 
		map[i + 1][j] != 'S' && map[i + 1][j] != '0')
		return (1);
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'N' && \
		map[i][j + 1] != 'E' && map[i][j + 1] != 'W' && 
		map[i][j + 1] != 'S' && map[i][j + 1] != '0')
		return (1);
	return (0);
}

int	map_check(t_data *utils, int y, int i, int *j)
{
	char m;

	while (utils->map[i][*j] == ' ')
		(*j)++;
	m = utils->map[i][*j];
	utils->first = *j;
	if (m == 'N' || m == 'E' || m == 'W' || m == 'S')
		utils->count++;
	if (utils->count > 1)
		return (1);
	if (m == '0')
	{
		if (check_map2(utils->map, i, *j, y) == 1)
			return (1);
	}
	else if(m != '1' && m != '\n' && m != 'N' && m != 'S' && 
		m != 'W' && m != 'E' && m != ' ')
		return (1);
	(*j)++;
	return (0);
}

int	check_map(t_data *utils, int y)
{
	int	count;
	int	first;
	int	i;
	int	j;

	count = 0;
	first = 0;
	i = 1;
	j = 0;
	if (sides_map(utils->map, y) == 1)
		return (1);
	while (utils->map[i - 1] && utils->map[i])
	{
		while (utils->map[i][j])
		{
			if (map_check(utils, y, i, &j) == 1)
				return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}
