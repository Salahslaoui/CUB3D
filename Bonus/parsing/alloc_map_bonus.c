/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:53:59 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:46:25 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	map_alloc_bonus(t_data *utils, t_list *lst, int len, int *i)
{
	while (lst)
	{
		if (ft_strcmp_bonus(lst->content, "\n") == 0)
			return (ft_free_map_i_bonus(utils, *i), 1);
		utils->map[*i] = malloc(len + 1);
		if (!utils->map[*i])
		{
			ft_put_error_bonus("Error:\nMemory allocation failed!\n");
			return (ft_free_map_i_bonus(utils, *i), 1);
		}
		ft_strcpy_bonus(lst->content, utils->map[*i]);
		lst = lst->next;
		(*i)++;
	}
	return (0);
}

int	str_space_bonus(char **str)
{
	if (!str)
		return (0);
	while (*str && **str == ' ')
		(*str)++;
	return (1);
}

int	space_detect_bonus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_map_i_bonus(t_data *data, int end)
{
	int		i;

	i = 0;
	while (i < end)
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
	data->map = NULL;
}

int	check_name_bonus(char *str)
{
	int		len;

	if (!str)
		return (1);
	len = ft_strlen_bonus(str);
	if (ft_strcmp_bonus(str + len - 4, ".cub"))
		return (1);
	return (0);
}
