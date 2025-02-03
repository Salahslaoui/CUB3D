/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:11 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/03 10:08:18 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define TEXT_HEIGH 64
# define TEXT_WIDTH 64
# define HEIGHT 900
# define WEIGHT 1600
# define SQUER 64
# define TAIL 64
# define FOV_ANG 60
# define RAY_NBR 1600
# define BUFFER_SIZE 10
# define MINI_H 180
# define MINI_W 350
# define MINI_S 20

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
	bool				washitvert;
	float			ray_ang;
	float			distance;
	float			xstep;
	float			ystep;
	float			xintercept;
	float			yintercept;
	float			horz_wallhitx;
	float			horz_wallhity;
	float			vert_wallhitx;
	float			vert_wallhity;
	float			destinationx;
	float			destinationy;
	int 				wall_hight;
	long				Up;
	long				Down;
	double		nextvtouch_x;
	double		nextvtouch_y;
	double		nexthtouch_x;
	double		nexthtouch_y;
	int			offx;
	int			offy;
	t_facing			*facing;
}	t_rays;

typedef struct s_graph
{
	mlx_t		*mlx;
	mlx_image_t	*project;
	mlx_image_t	*mini_map;
	mlx_texture_t	*la;
	mlx_texture_t	*N;
	mlx_texture_t	*W;
	mlx_texture_t	*S;
	mlx_texture_t	*E;
}	t_graph;

typedef struct s_player
{
	double			pl_x;
	double			pl_y;
	int			redius;
	int			turn_dir;
	int			walk_dir;
	float		rot_angel;
	double strafe_dir;
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
void	free_map(char **map);
int		calcul(int *j, char **ptr, int *i, int k);
void	free_map(char **map);
void	ft_put_error(char *error);

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
double deg_to_rad(double degree);
double normalaize_angle(double angle);
//void ft_release_keys(t_data *data);
//void bresenham(int y0, int x0, int y1, int x1, t_data *exec);
void ft_put_player(t_data *data, mlx_image_t *image);
void ft_put_map(t_data *data);
void ft_handek_actions(void *param);
void cast_all_rays(t_data *data, t_player *player);
int wallcheckers(t_data *data, int x, int y);
void	randring3d(t_data *data, t_player *player);
void	ft_exit(t_data *data, char *error, int exit_value);
void	rayfacing(t_rays *ray, t_facing *facing);
void	horizontal_intersection(t_data *data, t_rays *ray, t_facing *facing);
void	vertical_intersection(t_data *data, t_rays *ray, t_facing *facing);

						//Bonus
void put_mini_map(t_data *data, t_graph *mlx, t_player *player);

						//GNL
char		*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_get_line(char **static_var);
int		read_function(int fd, char **static_var);


#endif