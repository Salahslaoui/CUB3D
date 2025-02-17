/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:45:34 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:44:28 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_dt_bonus(char **ptr, char *str, int *i, int *j)
{
	*ptr = str;
	*i = 0;
	*j = 0;
}

char	*adjust_str_bonus(char *str, t_data *utils)
{
	char	*ptr;
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			return (ft_put_error_bonus("Error\nthe map is invalid"),
				free_it_bonus(utils->lst, utils), exit(1), NULL);
		i++;
	}
	ptr = ft_strtrim_bonus(str + 3, "\n");
	tmp = ptr;
	ptr = ft_strtrim_bonus(ptr, " ");
	free(tmp);
	return (ptr);
}

int	line_check_bonus(char *str, t_data *utils, int in, int fd)
{
	char	*ptr;
	t_list	*node;
	int		i;
	int		j;

	ptr = NULL;
	init_dt_bonus(&ptr, str, &i, &j);
	while (str)
	{
		while (*ptr == ' ')
			ptr++;
		if (*ptr == '\t' || parse_bonus(str, &j, utils, in) == 1)
			return (free(str), 1);
		if (*ptr == '1' || *ptr == '0' || ft_strcmp_bonus(str, "\n") == 0
			|| space_skip_bonus(ptr) == 1)
		{
			node = ft_lstnew_bonus(str);
			ft_lstadd_back_bonus(&utils->lst, node);
		}
		free(str);
		i++;
		str = get_next_line_bonus(fd);
		ptr = str;
	}
	return (0);
}

int	dir_fill_bonus(char *str, t_data *utils, int *i)
{
	while (str && *str == ' ')
		str++;
	if (ft_strncmp_bonus(str, "WE ", 3) == 0)
	{
		if (utils->we)
			return (1);
		utils->we = adjust_str_bonus(str, utils);
		(*i)++;
		return (2);
	}
	else if (ft_strncmp_bonus(str, "C ", 2) == 0 || ft_strncmp_bonus(str, "F ", 2) == 0)
	{
		if (ft_strncmp_bonus(str, "C ", 2) == 0 && utils->c_rgb != -1)
			return (1);
		if (ft_strncmp_bonus(str, "F ", 2) == 0 && utils->f_rgb != -1)
			return (1);
		(*i)++;
		if (rgb_parse_bonus(str, utils) == 1)
			return (1);
		return (2);
	}
	return (0);
}

int	direction_fill_bonus(char *str, t_data *utils, int *i)
{
	if (str_space_bonus(&str) && ft_strncmp_bonus(str, "NO ", 3) == 0)
	{
		if (utils->no)
			return (1);
		utils->no = adjust_str_bonus(str, utils);
		(*i)++;
		return (2);
	}
	else if (ft_strncmp_bonus(str, "SO ", 3) == 0)
	{
		if (utils->so)
			return (1);
		utils->so = adjust_str_bonus(str, utils);
		(*i)++;
		return (2);
	}
	else if (ft_strncmp_bonus(str, "EA ", 3) == 0)
	{
		if (utils->ea)
			return (1);
		utils->ea = adjust_str_bonus(str, utils);
		(*i)++;
		return (2);
	}
	return (0);
}
