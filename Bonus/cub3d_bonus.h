/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:11 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/04 11:10:31 by ozahdi           ###   ########.fr       */
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
# include "/Users/ozahdi/Desktop/MLX42/include/MLX42/MLX42.h"

# define TEXT_HEIGH 700
# define TEXT_WIDTH 700
# define HEIGHT 900
# define WEIGHT 1600
# define SQUER 700
# define TAIL 700
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
	long				up;
	long				down;
	t_facing			*facing;
	float				ray_ang;
	float				distance;
	float				xstep;
	float				ystep;
	float				xintercept;
	float				yintercept;
	float				horz_wallhitx;
	float				horz_wallhity;
	float				vert_wallhitx;
	float				vert_wallhity;
	float				destinationx;
	float				destinationy;
	int					wall_hight;
	double				nextvtouch_x;
	double				nextvtouch_y;
	double				nexthtouch_x;
	double				nexthtouch_y;
	int					offx;
	int					offy;
}	t_rays;

typedef struct s_graph
{
	mlx_t			*mlx;
	mlx_image_t		*project;
	mlx_image_t		*mini_map;
	mlx_texture_t	*la;
	mlx_texture_t	*north;
	mlx_texture_t	*west;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
}	t_graph;

typedef struct s_player
{
	double			pl_x;
	double			pl_y;
	int				redius;
	int				turn_dir;
	int				walk_dir;
	float			rot_angel;
	double			strafe_dir;
	int				speed;
	double			rot_speed;
	int				hitbox;
	int				si_pl;
}	t_player;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_graph		*mlx;
	t_list		*lst;
	t_rays		*view;
	int			r;
	int			count;
	int			first;
	int			g;
	int			b;
	int			a;
	int			i;
	int			f_rgb;
	int			c_rgb;
	int			height;
	int			weight;
	char		*name;
	char		*no;
	char		*ea;
	char		*so;
	char		*we;
	char		**map;
	t_player	*player;
}	t_data;

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
void	free_map(char **map);
void	ft_put_error(char *error);
void	*parsing_map(t_data *utils, int *fd);
void	ray_casting(t_data *data, t_graph *mlx);
void	ft_handek_actions(void *param);
void	cast_all_rays(t_data *data, t_player *player);
void	randring3d(t_data *data, t_player *player);
void	ft_exit(t_data *data, char *error, int exit_value);
void	rayfacing(t_rays *ray, t_facing *facing);
void	horizontal_intersection(t_data *data, t_rays *ray, t_facing *facing);
void	vertical_intersection(t_data *data, t_rays *ray, t_facing *facing);
void	put_mini_map(t_data *data, t_graph *mlx, t_player *player, int i);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_get_line(char **static_var);
void	ft_free_map_i(t_data *data, int end);
void	ft_load_images(t_data *data, t_graph *mlx);
int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strshr(char *s, char c);
int		space_skip(char *str);
int		lines_lenght(t_list *lst, int *l_len);
t_list	*ft_lstnew(void *content);
int		calcul(int *j, char **ptr, int *i, int k);
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
int		top_buttom(char **map, int y, int i);
int		map_check(t_data *utils, int y, int i, int *j);
int		dir_fill(char *str, t_data *utils, int *i);
int		direction_fill(char *str, t_data *utils, int *i);
int		line_check(char *str, t_data *utils, int in, int fd);
int		ft_check_wall(t_data *data, double x, double y);
double	deg_to_rad(double degree);
double	normalaize_angle(double angle);
int		wallcheckers(t_data *data, int x, int y);
size_t	ft_strlen(const char *s);
int		read_function(int fd, char **static_var);
int		space_detect(char *str);
int		map_alloc(t_data *utils, t_list *lst, int len, int *i);
int		str_space(char **str);

#endif