/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:35:32 by sslaoui           #+#    #+#             */
/*   Updated: 2024/11/25 11:16:33 by sslaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char **static_var)
{
	char	*tmp;
	char	*line;
	int		i;

	i = ft_strchr(*static_var, '\n') - *static_var;
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
	i = ft_strchr(*static_var, '\n') - *static_var;
	*static_var = ft_substr(*static_var, i + 1, ft_strlen(*static_var) - i + 1);
	return (free(tmp), line);
}

int	read_function(int fd, char **static_var)
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
	*static_var = ft_strjoin(*static_var, buffer);
	free(tmp);
	free(buffer);
	return (buffersize);
}

char	*get_next_line(int fd)
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
	if (str && ft_strchr(str, '\n'))
		return (ft_get_line(&str));
	while (read_function(fd, &str) && !ft_strchr(str, '\n'))
		count++;
	if (str && ft_strchr(str, '\n'))
		return (ft_get_line(&str));
	if (str && *str)
		return (tmp = ft_strjoin(str, ""), free(str), str = NULL, tmp);
	tmp = str;
	str = NULL;
	return (free(tmp), str);
}