/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:20:04 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/14 09:19:20 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static char	*ftt_strchr(const char *s, int c)
{
	char	a;
	int		i;

	i = 0;
	a = (char )c;
	while (s[i] != '\0')
	{
		if (a == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == a)
		return ((char *)&s[i]);
	if (!s[i])
		return ((char *)&s[i]);
	return (NULL);
}

static void	ft_free(char **res)
{
	unsigned int	l;

	l = 0;
	while (res[l])
	{
		free(res[l]);
		l++;
	}
	free(res);
}

static int	ft_skip_and_lenght(char const *s, unsigned int *index, char c)
{
	unsigned int	i;

	while (s[*index] && s[*index] == c)
		(*index)++;
	i = 0;
	while (s[*index + i] && s[*index + i] != c)
		i++;
	return (i);
}

static char	**ft_allocate(char **res, char const *s, unsigned int j, char c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	index;

	index = 0;
	k = 0;
	while (k < j)
	{
		i = ft_skip_and_lenght(s, &index, c);
		res[k] = (char *)malloc(i + 1);
		if (!res[k])
			return (ft_free(res), NULL);
		i = 0;
		while (s[index + i] && s[index + i] != c)
		{
			res[k][i] = s[index + i];
			i++;
		}
		res[k][i] = '\0';
		k++;
		index += i;
	}
	res[k] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	const char		*str;
	unsigned int	j;
	unsigned int	index;
	char			**res;

	str = (const char *)s;
	j = 0;
	if (!s)
		return (NULL);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			j++;
		str = (char *)ftt_strchr(str, c);
	}
	index = 0;
	res = (char **)malloc((j + 1) * (sizeof(char *)));
	if (!res)
		return (NULL);
	res = ft_allocate(res, s, j, c);
	return (res);
}
