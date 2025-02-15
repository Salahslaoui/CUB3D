/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:59:50 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/14 09:19:20 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	parse1(char *str, t_data *utils)
{
	if ((*str == '0' || *str == '1')
		&& (!utils->no || !utils->ea || !utils->we || !utils->so))
		return (1);
	if ((*str == '0' || *str == '1')
		&& (utils->c_rgb == -1 || utils->f_rgb == -1))
		return (1);
	return (0);
}

int	checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
			&& str[i] != 'E' && str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	parse_dir(char *str, int *i, int in, t_data *utils)
{
	int	j;

	in = direction_fill(str, utils, i);
	j = dir_fill(str, utils, i);
	if (in)
	{
		if (in == 2)
			return (2);
		else if (in == 1)
			return (1);
	}
	else if (j)
	{
		if (j == 2)
			return (2);
		else if (j == 1)
			return (1);
	}
	return (0);
}

int	parse(char *str, int *i, t_data *utils, int in)
{
	int	res;

	res = parse_dir(str, i, in, utils);
	if (res)
	{
		if (res == 2)
			;
		else if (res == 1)
			return (1);
	}
	else if (space_detect(str)
		&& (!utils->no || !utils->ea || !utils->we || !utils->so))
		return (1);
	else if (space_detect(str)
		&& (utils->c_rgb == -1 || utils->f_rgb == -1))
		return (1);
	else if (space_skip(str) == 1 || ft_strcmp(str, "\n") == 0)
		return (0);
	else if (checker(str) == 1)
		return (0);
	else
		return (1);
	return (0);
}

int	get_content(int *fd, t_data *utils)
{
	char	*str;
	int		j;
	int		in;

	str = NULL;
	j = 0;
	in = 0;
	*fd = open(utils->name, O_RDONLY, 0755);
	if (*fd == -1)
	{
		ft_put_error("Error:\nOpening file failed!\n");
		exit (1);
	}
	str = get_next_line(*fd);
	if (!str)
	{
		close(*fd);
		ft_put_error("Error:\nReading from file failed!\n");
		exit (1);
	}
	if (line_check(str, utils, in, *fd) == 1)
		return (close(*fd), 1);
	return (close(*fd), 0);
}
