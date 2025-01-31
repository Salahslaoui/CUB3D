/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:11:43 by sslaoui           #+#    #+#             */
/*   Updated: 2024/11/25 11:36:01 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../cub3d.h"

#  define BUFFER_SIZE 10

char		*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_get_line(char **static_var);
int		read_function(int fd, char **Var);

#endif