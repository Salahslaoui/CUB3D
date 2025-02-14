/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:02:47 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/14 09:19:20 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_rgb(char **ptr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (ptr[i])
	{
		while (ptr[i][j])
		{
			if (ptr[i][j] == ' ')
			{
				j++;
				k++;
				continue ;
			}
			if (ptr[i][j] != '\n' && (ptr[i][j] < '0' || ptr[i][j] > '9'))
				return (1);
			j++;
		}
		if (calcul(&j, ptr, &i, k) == 1)
			return (1);
	}
	return (0);
}

void	free_splt(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	var_init(t_data *utils, char **ptr)
{
	if (check_rgb(ptr) == 1)
		return (1);
	utils->r = ft_atoi(ptr[0]);
	utils->g = ft_atoi(ptr[1]);
	utils->b = ft_atoi(ptr[2]);
	if (utils->r > 255 || utils->g > 255 || utils->b > 255)
		return (1);
	return (0);
}

int	check_verg(char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		if (str[i] == ',' && space_skip_2(str + i + 1))
			return (1);
		i++;
	}
	if (j > 2)
		return (1);
	return (0);
}

int	rgb_parse(char *str, t_data *utils)
{
	char	**ptr;
	char	*save;
	int		a;

	save = str;
	a = 255;
	if ((*str == 'C' || *str == 'F') && (*(str + 1) == ' '))
		str += 2;
	else
		return (1);
	if (*str == ',')
		return (1);
	ptr = ft_split(str, ',');
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || ptr[3])
		return (free_splt(ptr), 1);
	if (var_init(utils, ptr) == 1 || check_verg(str) == 1 || ptr_c(ptr) == 1)
		return (free_splt(ptr), 1);
	if (*(str - 2) == 'C')
		utils->c_rgb = (utils->r << 24) | (utils->g << 16)
			| (utils->b << 8) | (a);
	if (*(str - 2) == 'F')
		utils->f_rgb = (utils->r << 24) | (utils->g << 16)
			| (utils->b << 8) | (a);
	return (free_splt(ptr), 0);
}
