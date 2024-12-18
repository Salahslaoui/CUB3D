/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:11 by sslaoui           #+#    #+#             */
/*   Updated: 2024/12/06 18:41:28 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

typedef struct s_player
{
	int	si_pl;
	int	pl_x;
	int	pl_y;
	int	height;
	int	weight;
	int	hitbox;
}	t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	void		*handle;
	void		(*plug_ptr)(struct s_map *utils);
	char		*NO;
	char		*EA;
	char		*SO;
	char		*WE;
	char		**map;
	t_player	*pl;
	t_data		*img;
	void		*mlx;
	void		*mlx_win;
	int			R;
	int			G;
	int			B;
	int			a;
	int 		F_rgb;
	int 		C_rgb;
} t_map;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <dlfcn.h>
#include "get_next_line/get_next_line.h"

						// UTILS
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
int	ft_strcmp(char *s1, char *s2);
t_list	*ft_lstnew(void *content);
void	plug_hello(t_map *utils);
int	ft_atoi(const char *str);


						//PARSING
void	utils_init(t_map *utils);
void	player_detection(char **map, t_player *pl);
void	*parsing_map(t_map *utils, int *fd);




						//GRAPH
void	pixels_rendering(t_map *utils);








#endif