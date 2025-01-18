/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:59:50 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/18 01:45:11 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parse1(char *str, int *i, t_data *utils, int *in)
{
	(void)i;
	(void)str;
	(void)in;
	if ((*str == '0' || *str == '1') && (!utils->NO || !utils->EA || !utils->WE || !utils->SO))
		return (1);
	if ((*str == '0' || *str == '1') && (utils->C_rgb == -1 || utils->F_rgb == -1))
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
			&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && 
			str[i] != 'E' && str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	parse(char *str, int *i, t_data *utils, int *in)
{
	(void)in;
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		if (utils->NO)
			return (1);
		utils->NO = ft_strdup(str);
		(*i)++;
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		if (utils->SO)
			return (1);
		utils->SO = ft_strdup(str);
		(*i)++;
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		if (utils->EA)
			return (1);
		utils->EA = ft_strdup(str);
		(*i)++;
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		if (utils->WE)
			return (1);
		utils->WE = ft_strdup(str);
		(*i)++;
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
		// else
		// {
		// 	free(str);
		// 	str = NULL;
		// }
	}
	else if ((*str == '0' || *str == '1') && (!utils->NO || !utils->EA || !utils->WE || !utils->SO))
		return (1);
	else if ((*str == '0' || *str == '1') && (utils->C_rgb == -1 || utils->F_rgb == -1))
		return (1);
	else if (space_skip(str) == 1 || ft_strcmp(str, "\n") == 0)
		return (0);
	else if (checker(str) == 1)
		return (0);
	else
		return (1);
	return (0);
}

int	get_content(t_list **lst, int *fd, t_data *utils)
{
	t_list	*node;
	char	*ptr;
	char 	*str;
	int		i;
	int		j;
	int		in;

	i = 0;
	j = 0;
	in = 0;
	*fd = open(utils->name, O_RDONLY, 0777);
	if (*fd == - 1)
		return (1);
	str = get_next_line(*fd);
	ptr = str;
	while (str)
	{
		while (*ptr == ' ')
			ptr++;
		if (*ptr == '\t')
			return (free(str), 1);
		if (parse(str, &j, utils, &in) == 1)
			return (free(str), 1);
		if (*ptr == '1' || *ptr == '0' || ft_strcmp(str, "\n") == 0 || space_skip(ptr) == 1)
		{
			node = ft_lstnew(str);
			ft_lstadd_back(lst, node);
		}
		free(str);
		i++;
		str = get_next_line(*fd);
		ptr = str;
	}
	return(0);
}

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
