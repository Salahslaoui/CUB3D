/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:56:26 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:48:07 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

size_t	ft_strlen_bonus(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_bonus(const char *s1)
{
	char			*str;
	unsigned int	i;

	i = ft_strlen_bonus(s1);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] && i < ft_strlen_bonus(s1))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
		return (ft_strdup_bonus(s2));
	if (!s2)
		return (ft_strdup_bonus(s1));
	i = 0;
	str = (char *)malloc(ft_strlen_bonus(s1) + ft_strlen_bonus(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr_bonus(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned long int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen_bonus(s) || !len)
	{
		str = ft_strdup_bonus("");
		if (!str)
			return (NULL);
		return (str);
	}
	if (ft_strlen_bonus(s) - start < len)
		len = ft_strlen_bonus(s) - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr_bonus(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i))
	{
		if ((char)c == *(s + i))
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
