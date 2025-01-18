/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:15:03 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/24 18:40:42 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdint.h>
# define TEXTUE_H 64
# define TEXTUE_W 64
void fill_texture(t_data *data)
{
	data->texture.walltexture = (uint32_t *)malloc(sizeof(uint32_t) * TEXTUE_H);
	for (int i = 0; i < TEXTUE_H; i++)
	{
		data->texture.walltexture[i] = malloc(sizeof(uint32_t) * TEXTUE_W);
		for (int j = 0; j < TEXTUE_W; j++)
				data->texture.walltexture[i][j] = (j == 0 || j % 8 == 0) ? 0x7E1891FF : 0xFCC737FF;
	}
}