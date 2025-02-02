/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:45:34 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/02 21:47:05 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_dt(char **ptr, char *str, int *i, int *j)
{
	*ptr = str;
	*i = 0;
	*j = 0;
}

char	*adjust_str(char *str, t_data *utils)
{
	char	*ptr;
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			return (printf("Error\nthe map is invalid"),
				free_it(utils->lst, utils), exit(1), NULL);
		i++;
	}
	ptr = ft_strtrim(str + 3, "\n");
	tmp = ptr;
	ptr = ft_strtrim(ptr, " ");
	free(tmp);
	return (ptr);
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
		if (utils->we)
			return (1);
		utils->we = adjust_str(str, utils);
		(*i)++;
		return (2);
	}
	else if (ft_strncmp(str, "C ", 2) == 0 || ft_strncmp(str, "F ", 2) == 0)
	{
		if (ft_strncmp(str, "C ", 2) == 0 && utils->c_rgb != -1)
			return (1);
		if (ft_strncmp(str, "F ", 2) == 0 && utils->f_rgb != -1)
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
		if (utils->no)
			return (1);
		utils->no = adjust_str(str, utils);
		(*i)++;
		return (2);
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		if (utils->so)
			return (1);
		utils->so = adjust_str(str, utils);
		(*i)++;
		return (2);
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		if (utils->ea)
			return (1);
		utils->ea = adjust_str(str, utils);
		(*i)++;
		return (2);
	}
	return (0);
}
