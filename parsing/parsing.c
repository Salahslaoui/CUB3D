/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:56:57 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/18 22:32:40 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	sides_map(char **map, int y)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map  && map[0] && map[0][i])
	{
		if (map[0][i] == '1' || map[0][i] == '\n' || map[0][i] == ' ')
			i++;
		else
			return(1);
	}
	i = 0;
	while (y > 0 && map[y - 1][i])
	{
		if (map[y - 1][i] == '1' || map[y - 1][i] == '\n' || map[y - 1][i] == ' ')
			i++;
		else
			return (1);
	}
	i = 0;
	while (map[i])
	{
		while (map[i][j] == ' ')
			j++;
		while (map[i][len])
			len++;
		if ((map[i][j] != '1' && map[i][j] != '\n') || (map[i][len - 1] != '1' && map[i][len - 1] != '\n'))
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
	// write(1, &map[1][25], 1);
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'N' && map[i - 1][j] != 'E' && map[i - 1][j] != 'W' && 
		map[i - 1][j] != 'S' && map[i - 1][j] != '0')
		return (1);
	if (j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != 'N' && map[i][j - 1] != 'S' && 
		map[i][j - 1] != 'W' && map[i][j - 1] != 'E' && map[i][j - 1] != '0')
		return (1);
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'N' && map[i + 1][j] != 'W' && map[i + 1][j] != 'E' && 
		map[i + 1][j] != 'S' && map[i + 1][j] != '0')
		return (1);
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'N' && map[i][j + 1] != 'E' && map[i][j + 1] != 'W' && 
		map[i][j + 1] != 'S' && map[i][j + 1] != '0')
		return (1);
	return (0);
}

int	check_map(char **map, int y)
{
	int	count;
	int	first;
	int	i;
	int	j;

	count = 0;
	first = 0;
	i = 1;
	j = 0;
	if (sides_map(map, y) == 1)
		return (1);
	while (map[i - 1] && map[i])
	{
		while (map[i][j])
		{
			while (map[i][j] == ' ')
				j++;
			first = j;
			// if (map[i][first] != '1' && map[i][first] != '\n')
			// 	return (write(1, &map[i][j], 1), 1);
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'S')
				count++;
			if (count > 1)
				return (1);
			if (map[i][j] == '0')
			{
				if (check_map2(map, i, j, y) == 1)
					return (1);
			}
			else if(map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != 'N' && map[i][j] != 'S' && 
				map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != ' ')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	filling_map(t_data *utils, int len, int j, t_list *lst)
{
	int	i;

	i = 0;
	while (lst && (ft_strcmp(lst->content, "\n") == 0 || space_skip(lst->content) == 1))
	{
		lst = lst->next;
		j--;
	}
	utils->map = malloc(sizeof(char *) * (j + 1));
	while (lst)
	{
		utils->map[i] = malloc(len + 1);
		ft_strcpy(lst->content, utils->map[i]);
		lst = lst->next;
		i++;
	}
	utils->map[i] = NULL;
	i = 0;
	if (!utils->map[i] || check_map(utils->map, j) == 1)
		return (1);
	utils->height = j;
	utils->weight = len;
	return (0);
}

void	free_it(t_list *lst, t_data *utils)
{
	(void)utils;
	t_list	*fr;

	fr = lst;
	while (fr)
	{
		free(fr->content);
		fr = fr->next;
	}
	free(fr);
	free(utils->NO);
	free(utils->SO);
	free(utils->WE);
	free(utils->EA);
	// free(utils->C_rgb)
}

void	*parsing_map(t_data *utils, int *fd)
{
	t_list	*lst;
	// t_list	*node;
	int		len;
	int		i;
	int		j;

	i = 0;
	lst = NULL;
	if (get_content(&lst, fd, utils) == 1)
		return (write(2, "parse error\n", 13), exit(1), free_it(lst, utils), NULL);
	len = lines_lenght(lst, &j);
	if (filling_map(utils, len, j, lst) == 1)
		return (write(2, "parse error\n", 13), exit(1), NULL);
	free_it(lst, utils);
	return (NULL);
}
