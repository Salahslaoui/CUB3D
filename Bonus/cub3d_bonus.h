/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:11 by sslaoui           #+#    #+#             */
/*   Updated: 2025/02/17 13:30:38 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include "../MLX42/include/MLX42/MLX42.h"

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
	int				wall_hight;
	double			nextvtouch_x;
	double			nextvtouch_y;
	double			nexthtouch_x;
	double			nexthtouch_y;
	int				offx;
	int				offy;
	bool			horz_wallhit;
	bool			vert_wallhit;
	bool			washitvert;
	t_facing		*facing;
	long			up;
	long			down;
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
	double			d_x;
	double			d_y;
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
	int			count;
	int			first;
	long		r;
	long		g;
	long		b;
	long		a;
	int			i;
	long		f_rgb;
	long		c_rgb;
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

void	ft_lstadd_back_bonus(t_list **lst, t_list *new);
char	**ft_split_bonus(char const *s, char c);
void	ft_strcpy_bonus(const char *src, char *dst);
void	player_detection_bonus(char **map, t_player *pl);
void	utils_init_bonus(t_data *utils, char *av);
void	fill_space_bonus(char *str);
char	*ft_strtrim_bonus(char *s1, char *set);
void	init_dt_bonus(char **ptr, char *str, int *i, int *j);
void	free_it_bonus(t_list *lst, t_data *utils);
void	free_map_bonus(char **map);
void	ft_put_error_bonus(char *error);
void	*parsing_map_bonus(t_data *utils, int *fd);
void	ft_free_map_i_bonus(t_data *data, int end);
void	ray_casting_bonus(t_data *data, t_graph *mlx);
void	ft_put_player_bonus(t_data *data, mlx_image_t *image);
void	ft_put_map_bonus(t_data *data);
void	ft_handek_actions_bonus(void *param);
void	cast_all_rays_bonus(t_data *data, t_player *player);
void	randring3d_bonus(t_data *data, t_player *player);
void	ft_exit_bonus(t_data *data, char *error, int exit_value);
void	rayfacing_bonus(t_rays *ray, t_facing *facing);
void	horizontal_intersection_bonus(t_data *data, t_rays *ray, t_facing *facing);
void	vertical_intersection_bonus(t_data *data, t_rays *ray, t_facing *facing);
void	put_mini_map_bonus(t_data *data, t_graph *mlx, t_player *player, int i);
char	*get_next_line_bonus(int fd);
char	*ft_strdup_bonus(const char *s1);
char	*ft_strjoin_bonus(char *s1, char *s2);
char	*ft_substr_bonus(char const *s, unsigned int start, size_t len);
char	*ft_strchr_bonus(const char *s, int c);
char	*ft_get_line_bonus(char **static_var);
void	ft_load_images_bonus(t_data *data, t_graph *mlx);
int		ft_atoi_bonus(const char *str);
int		ft_strcmp_bonus(char *s1, char *s2);
int		ft_strncmp_bonus(const char *s1, const char *s2, size_t n);
int		ft_strshr_bonus(char *s, char c);
int		space_skip_bonus(char *str);
int		lines_lenght_bonus(t_list *lst, int *l_len);
t_list	*ft_lstnew_bonus(void *content);
int		calcul_bonus(int *j, char **ptr, int *i, int k);
int		filling_map_bonus(t_data *utils, int len, int j, t_list *lst);
int		check_map_bonus(t_data *map, int y);
int		check_map2_bonus(char **map, int i, int j, int y);
int		sides_map_bonus(char **map, int y);
int		check_rgb_bonus(char **ptr);
int		rgb_parse_bonus(char *str, t_data *utils);
int		get_content_bonus(int *fd, t_data *utils);
int		parse_bonus(char *str, int *i, t_data *utils, int in);
int		checker_bonus(char *str);
int		parse1_bonus(char *str, t_data *utils);
int		map_alloc_bonus(t_data *utils, t_list *lst, int len, int *i);
int		str_space_bonus(char **str);
int		space_detect_bonus(char *str);
int		top_buttom_bonus(char **map, int y, int i);
int		map_check_bonus(t_data *utils, int y, int i, int *j);
int		dir_fill_bonus(char *str, t_data *utils, int *i);
int		direction_fill_bonus(char *str, t_data *utils, int *i);
int		line_check_bonus(char *str, t_data *utils, int in, int fd);
size_t	ft_strlen_bonus(const char *s);
int		ft_check_wall_bonus(t_data *data, double x, double y);
double	deg_to_rad_bonus(double degree);
double	normalaize_angle_bonus(double angle);
int		wallcheckers_bonus(t_data *data, int x, int y);
int		read_function_bonus(int fd, char **static_var);
int		check_name_bonus(char *str);
int		space_skip_2_bonus(char *str);
int		ptr_c_bonus(char **ptr);

#endif