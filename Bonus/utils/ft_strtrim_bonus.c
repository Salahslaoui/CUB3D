/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:12:04 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:28:59 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	*ft_memcpy_bonus(void *dst, const void *src, size_t n)
{
	char			*ptr;
	const char		*s;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	i = 0;
	ptr = dst;
	s = (const char *)src;
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strtrim_bonus(char *s1, char *set)
{
	char			*str;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] != '\0' && ft_strchr_bonus(set, s1[start]))
		start++;
	end = ft_strlen_bonus(s1);
	while (end > start && ft_strchr_bonus(set, s1[end - 1]))
		end--;
	str = (char *)malloc(end - start + 1);
	if (!str)
		return (NULL);
	str = (char *)ft_memcpy_bonus(str, &s1[start], end - start);
	str[end - start] = '\0';
	return (str);
}
