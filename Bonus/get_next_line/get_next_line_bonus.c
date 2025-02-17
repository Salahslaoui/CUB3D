/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:35:32 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:47:28 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*ft_get_line_bonus(char **static_var)
{
	char	*tmp;
	char	*line;
	int		i;

	i = ft_strchr_bonus(*static_var, '\n') - *static_var;
	line = malloc(i + 2);
	if (!line)
	{
		if (*static_var)
			return (free(*static_var), *static_var = NULL, NULL);
		return (NULL);
	}
	i = 0;
	while ((*static_var)[i] != '\n')
	{
		line[i] = (*static_var)[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	tmp = *static_var;
	i = ft_strchr_bonus(*static_var, '\n') - *static_var;
	*static_var = ft_substr_bonus(*static_var, \
	i + 1, ft_strlen_bonus(*static_var) - i + 1);
	return (free(tmp), line);
}

int	read_function_bonus(int fd, char **static_var)
{
	char	*buffer;
	char	*tmp;
	ssize_t	buffersize;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(*static_var), *static_var = NULL, 0);
	buffersize = read(fd, buffer, BUFFER_SIZE);
	buffer[buffersize] = '\0';
	tmp = *static_var;
	*static_var = ft_strjoin_bonus(*static_var, buffer);
	free(tmp);
	free(buffer);
	return (buffersize);
}

char	*get_next_line_bonus(int fd)
{
	static char	*str;
	char		*buffer;
	char		*tmp;
	int			count;

	count = 0;
	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX || read(fd, buffer, 0) < 0)
	{
		if (str)
			return (free(str), str = NULL);
		return (NULL);
	}
	if (str && ft_strchr_bonus(str, '\n'))
		return (ft_get_line_bonus(&str));
	while (read_function_bonus(fd, &str) && !ft_strchr_bonus(str, '\n'))
		count++;
	if (str && ft_strchr_bonus(str, '\n'))
		return (ft_get_line_bonus(&str));
	if (str && *str)
		return (tmp = ft_strjoin_bonus(str, ""), free(str), str = NULL, tmp);
	tmp = str;
	str = NULL;
	return (free(tmp), str);
}
