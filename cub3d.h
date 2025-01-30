/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:11 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/30 12:45:10 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libc.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"

# define TEXT_HEIGH 64
# define TEXT_WIDTH 64
# define HEIGHT 900
# define WEIGHT 1600
# define SQUER 64
# define TAIL 64
# define FOV_ANG 60
# define RAY_NBR 1600

typedef struct s_texture
{
	uint32_t		*colorbuffer;
	uint32_t		*walltexture;
}	t_texture;

typedef struct s_facing
{
	int			facing_down;
	int			facing_up;
	int			facing_right;
	int			facing_left;
}	t_facing;

typedef struct s_rays
{
	bool				horz_wallhit;
	bool				vert_wallhit;
	bool				wasHitVert;
	float			ray_ang;
	float			distance;
	float				xstep;
	float				ystep;
	float				xintercept;
	float				yintercept;
	float				horz_wallhitx;
	float				horz_wallhity;
	float				vert_wallhitx;
	float				vert_wallhity;
	float				destinationX;
	float				destinationY;
	int 					wall_hight;
	t_facing			*facing;
}	t_rays;

typedef struct s_graph
{
	mlx_t		*mlx;
	mlx_image_t	*project;
	mlx_image_t	*image;
	mlx_texture_t	*la;
	mlx_texture_t	*N;
	mlx_texture_t	*W;
	mlx_texture_t	*S;
	mlx_texture_t	*E;
	mlx_image_t	*textute;
}	t_graph;

typedef struct s_player
{
	double			pl_x;
	double			pl_y;
	double			d_x;
	double			d_y;
	int			redius;
	int			turn_dir;
	int			walk_dir;
	float		rot_angel;
	int			speed;
	double		rot_speed;
	int			hitbox;
	int			si_pl;
}	t_player;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

typedef struct s_data
{
	t_graph		*mlx;
	t_list		*lst;
	t_rays		*view;
	t_texture		texture;
	bool			update;
	char			*name;
	char			*NO;
	char			*EA;
	char			*SO;
	char			*WE;
	char			**map;
	t_player		*player;
	int			R;
	int			count;
	int			first;
	int			G;
	int			B;
	int			a;
	int			i;
	int 			F_rgb;
	int 			C_rgb;
	int			height;
	int			weight;
} t_data;

						// UTILS
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strshr(char *s, char c);
int		space_skip(char *str);
int		lines_lenght(t_list *lst, int *l_len);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(char const *s, char c);
void	ft_strcpy(const char *src, char *dst);
void	player_detection(char **map, t_player *pl);
void	utils_init(t_data *utils, char *av);
void	fill_space(char *str);
char	*ft_strtrim(char *s1, char *set);
void	init_dt(char **ptr, char *str, int *i, int *j);
void	free_it(t_list *lst, t_data *utils);
int		calcul(int *j, char **ptr, int *i, int k);

						//PARSE
void	*parsing_map(t_data *utils, int *fd);
int		filling_map(t_data *utils, int len, int j, t_list *lst);
int		check_map(t_data *map, int y);
int		check_map2(char **map, int i, int j, int y);
int		sides_map(char **map, int y);
int		check_rgb(char **ptr);
int		rgb_parse(char *str, t_data *utils);
int		get_content(int *fd, t_data *utils);
int		parse(char *str, int *i, t_data *utils, int in);
int		checker(char *str);
int		parse1(char *str, t_data *utils);
int	top_buttom(char **map, int y, int i);
int	map_check(t_data *utils, int y, int i, int *j);
int	dir_fill(char *str, t_data *utils, int *i);
int	direction_fill(char *str, t_data *utils, int *i);
int	line_check(char *str, t_data *utils, int in, int fd);


void ray_casting(t_data *data, t_graph *mlx);
int ft_check_wall(t_data *data, double x, double y);
double degree_radian(double degree, int type);
double normalaize_angle(double angle);
void ft_release_keys(t_data *data);
void bresenham(int y0, int x0, int y1, int x1, t_data *exec);
void ft_put_player(t_data *data, mlx_image_t *image);
void ft_put_map(t_data *data);
void ft_handek_actions(void *param);
void CastAllRays(t_data *data, t_player *player);
int wallcheckers(t_data *data, int x, int y);
void	Randring3D(t_data *data, t_player *player);

#endif