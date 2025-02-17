/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:16:15 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:27:45 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

t_list	*ft_lstnew_bonus(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = ft_strdup_bonus(content);
	lst->next = NULL;
	return (lst);
}
