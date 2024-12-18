/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:17 by sslaoui           #+#    #+#             */
/*   Updated: 2024/12/07 00:43:38 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <libc.h>

int	check_rgb(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		while (ptr[i][j])
		{
			if (ptr[i][j] != '\n' && (ptr[i][j] < '0' || ptr[i][j] > '9'))
				return (1);
			j++;
		}
		if (j > 3)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

int	rgb_parse(char *str, t_map *utils)
{
	char	**ptr;
	int		a;

	a = 255;
	if ((*str == 'C' || *str == 'F') && (*(str + 1) == ' '))
		str += 2;
	else
		return (1);
	if (*str == ',')
		return (1);
	ptr = ft_split(str, ',');
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || ptr[3])
		return (1);
	if (check_rgb(ptr) == 1)
		return (1);
	utils->R = ft_atoi(ptr[0]);
	utils->G = ft_atoi(ptr[1]);
	utils->B = ft_atoi(ptr[2]);
	if (utils->R > 255 || utils->G > 255 || utils->B > 255)
		return (1);
	if (*(str - 2) == 'C')
		utils->C_rgb = (utils->R << 24) | (utils->G << 16) | (utils->B << 8) | (a);
	if (*(str - 2) == 'F')
		utils->F_rgb = (utils->R << 24) | (utils->G << 16) | (utils->B << 8) | (a);
	return (0);
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

int	parse1(char *str, int *i, t_map *utils, int *in)
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

int	parse(char *str, int *i, t_map *utils, int *in)
{
	(void)in;
	if (ft_strncmp(str, "NO ", 3) == 0)
	{
		utils->NO = str;
		(*i)++;
	}
	else if (ft_strncmp(str, "SO ", 3) == 0)
	{
		utils->SO = str;
		(*i)++;
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		utils->EA = str;
		(*i)++;
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		utils->WE = str;
		(*i)++;
	}
	else if (ft_strncmp(str, "C ", 2) == 0 || ft_strncmp(str, "F ", 2) == 0)
	{
		(*i)++;
		if (rgb_parse(str, utils) == 1)
			return (1);
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

int	get_content(t_list **lst, int *fd, t_map *utils)
{
	t_list	*node;
	char	*ptr;
	(void) utils;
	char 	*str;
	int		i;
	int		j;
	int		in;

	i = 0;
	j = 0;
	in = 0;
	*fd = open("map.cub", O_RDONLY, 0777);
	if (*fd == - 1)
		return (1);
	str = get_next_line(*fd);
	ptr = str;
	while (str)
	{
		while (*ptr == ' ')
			ptr++;
		if (*ptr == '\t')
			return (1);
		if (parse(str, &j, utils, &in) == 1)
			return (1);
		if (*ptr == '1' || *ptr == '0' || ft_strcmp(str, "\n") == 0 || space_skip(ptr) == 1)
		{
			node = ft_lstnew(str);
			ft_lstadd_back(lst, node);
		}
		i++;
		str = get_next_line(*fd);
		ptr = str;
	}
	return(0);
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
		if (map[0][i] == '1' || map[0][i] == '\n')
			i++;
		else
			return(1);
	}
	i = 0;
	while (y > 0 && map[y - 1][i])
	{
		if (map[y - 1][i] == '1' || map[y - 1][i] == '\n')
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

int	filling_map(t_map *utils, int len, int j, t_list *lst)
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
		// fill_space(utils->map[i]);
		ft_strcpy(lst->content, utils->map[i]);
		lst = lst->next;
		i++;
	}
	utils->map[i] = NULL;
	i = 0;
	if (!utils->map[i] || check_map(utils->map, j) == 1)
		return (1);
	utils->pl->height = j;
	utils->pl->weight = len;
	return (0);
}

void	*parsing_map(t_map *utils, int *fd)
{
	t_list	*lst;
	t_list	*node;
	int		len;
	int		i;
	int		j;

	i = 0;
	lst = NULL;
	if (get_content(&lst, fd, utils) == 1)
		return (write(2, "parse error\n", 13), NULL);
	node = lst;
	len = lines_lenght(lst, &j);
	if (filling_map(utils, len, j, lst) == 1)
		return (write(2, "parse error\n", 13), NULL);
	i = 0;
	while (utils->map[i])
	{
		printf("%s", utils->map[i]);
		i++;
	}
	return (NULL);
}

void	utils_init(t_map *utils)
{
	utils->EA = NULL;
	utils->WE = NULL;
	utils->NO = NULL;
	utils->SO = NULL;
	utils->C_rgb = -1;
	utils->F_rgb = -1;
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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				pl->pl_x = i;
				pl->pl_y = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
