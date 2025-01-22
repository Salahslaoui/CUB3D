/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:56:57 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/22 05:54:45 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	top_buttom(char **map, int y, int i)
{
	while (map && map[0] && map[0][i])
	{
		if (map[0][i] == '1' || map[0][i] == '\n' || map[0][i] == ' ')
			i++;
		else
			return (1);
	}
	i = 0;
	while (y > 0 && map[y - 1][i])
	{
		if (map[y - 1][i] == '1' || map[y - 1][i] == '\n'
			|| map[y - 1][i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	filling_map(t_data *utils, int len, int j, t_list *lst)
{
	int	i;

	i = 0;
	while (lst && (ft_strcmp(lst->content, "\n") == 0
			|| space_skip(lst->content) == 1))
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
	if (!utils->map[i] || check_map(utils, j) == 1)
		return (1);
	utils->height = j;
	utils->weight = len;
	return (0);
}

void	free_it(t_list *lst, t_data *utils)
{
	t_list	*fr;
	t_list	*sav;

	fr = lst;
	while (fr)
	{
		free(fr->content);
		sav = fr;
		fr = fr->next;
		free(sav);
	}
	free(fr);
	free(utils->NO);
	free(utils->SO);
	free(utils->WE);
	free(utils->EA);
}

void	*parsing_map(t_data *utils, int *fd)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	utils->lst = NULL;
	if (get_content(fd, utils) == 1)
		return (write(2, "parse error\n", 13),
			free_it(utils->lst, utils), NULL);
	len = lines_lenght(utils->lst, &j);
	if (filling_map(utils, len, j, utils->lst) == 1)
		return (write(2, "parse error\n", 13),
			free_it(utils->lst, utils), NULL);
	free_it(utils->lst, utils);
	return (NULL);
}
