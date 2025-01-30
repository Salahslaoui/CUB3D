/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:45:34 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/29 21:30:41 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_dt(char **ptr, char *str, int *i, int *j)
{
	*ptr = str;
	*i = 0;
	*j = 0;
}

int	line_check(char *str, t_data *utils, int in, int fd)
{
	char	*ptr;
	t_list	*node;
	int		i;
	int		j;

	ptr = NULL;
	init_dt(&ptr, str, &i, &j);
	while (str)
	{
		while (*ptr == ' ')
			ptr++;
		if (*ptr == '\t' || parse(str, &j, utils, in) == 1)
			return (free(str), 1);
		if (*ptr == '1' || *ptr == '0' || ft_strcmp(str, "\n") == 0
			|| space_skip(ptr) == 1)
		{
			node = ft_lstnew(str);
			ft_lstadd_back(&utils->lst, node);
		}
		free(str);
		i++;
		str = get_next_line(fd);
		ptr = str;
	}
	return (0);
}

int	dir_fill(char *str, t_data *utils, int *i)
{
	if (ft_strncmp(str, "WE ", 3) == 0)
	{
		if (utils->WE)
			return (1);
		utils->WE = ft_strtrim(str + 3, "\n");
		(*i)++;
		return (2);
	}
	else if (ft_strncmp(str, "C ", 2) == 0 || ft_strncmp(str, "F ", 2) == 0)
	{
		if (ft_strncmp(str, "C ", 2) == 0 && utils->C_rgb != -1)
			return (1);
		if (ft_strncmp(str, "F ", 2) == 0 && utils->F_rgb != -1)
			return (1);
		(*i)++;
		if (rgb_parse(str, utils) == 1)
			return (1);
		return (2);
	}
	return (0);
}

int	direction_fill(char *str, t_data *utils, int *i)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		if (utils->NO)
			return (1);
		utils->NO = ft_strtrim(str + 3, "\n");
		(*i)++;
		return (2);
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		if (utils->SO)
			return (1);
		utils->SO = ft_strtrim(str + 3, "\n");
		(*i)++;
		return (2);
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		if (utils->EA)
			return (1);
		utils->EA = ft_strtrim(str + 3, "\n");
		(*i)++;
		return (2);
	}
	return (0);
}
