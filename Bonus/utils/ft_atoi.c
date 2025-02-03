/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:40:33 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/03 12:24:46 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	convets_string(const char *str, long long *s, int sign)
{
	long long	res;

	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			res = *s;
			*s = *s * 10 + (*str++ - 48);
			if (*s / 10 != res && sign == 1)
				return (-1);
			else if (*s / 10 != res && sign == -1)
				return (0);
		}
		else
			break ;
	}
	return (*s * sign);
}

int	ft_atoi(const char *str)
{
	long long	n;
	int			sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	n = 0;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	return (convets_string(str, &n, sign));
}
