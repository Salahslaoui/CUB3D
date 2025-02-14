/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:00:56 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/14 09:19:20 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	fill_space(char *str)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = ' ';
}

void	utils_init(t_data *utils, char *av)
{
	utils->c_rgb = -1;
	utils->f_rgb = -1;
	utils->name = av;
	utils->player->pl_x = 0;
	utils->player->pl_y = 0;
	utils->count = 0;
	utils->first = 0;
	utils->i = 0;
}

void	player_detection(char **map, t_player *pl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				pl->pl_x = j;
				pl->pl_y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_strcpy(const char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	lines_lenght(t_list *lst, int *l_len)
{
	int	i;
	int	j;

	j = 0;
	*l_len = 0;
	while (lst)
	{
		i = 0;
		while (((char *)lst->content)[i])
			i++;
		if (i > j)
			j = i;
		lst = lst->next;
		(*l_len)++;
	}
	return (j);
}
