SRC			=	Mandatory/main.c\
				Mandatory/get_next_line/get_next_line.c Mandatory/get_next_line/get_next_line_utils.c \
				Mandatory/utils/ft_strcmp.c Mandatory/utils/ft_lstadd_back.c Mandatory/utils/ft_lstnew.c\
				Mandatory/utils/ft_split.c Mandatory/utils/ft_atoi.c Mandatory/utils/ft_strncmp.c Mandatory/utils/ft_strshr.c Mandatory/utils/ft_strtrim.c\
				Mandatory/ray_casting/hooks.c Mandatory/ray_casting/ray_casting.c Mandatory/ray_casting/ray_casting_utils.c \
				Mandatory/ray_casting/Castrays.c Mandatory/ray_casting/Castrays2.c Mandatory/ray_casting/3D_randring.c\
				Mandatory/parsing/checker.c Mandatory/parsing/parsing.c Mandatory/parsing/rgb_check.c Mandatory/parsing/utils.c Mandatory/parsing/parsing2.c \
				Mandatory/parsing/map_check.c Mandatory/parsing/alloc_map.c Mandatory/utils/ft_exit.c Mandatory/ray_casting/loading_images.c Mandatory/parsing/utils2.c\

SRC_B		=	Bonus/main_bonus.c\
				Bonus/get_next_line/get_next_line_bonus.c Bonus/get_next_line/get_next_line_utils_bonus.c \
				Bonus/utils/ft_strcmp_bonus.c Bonus/utils/ft_lstadd_back_bonus.c Bonus/utils/ft_lstnew_bonus.c\
				Bonus/utils/ft_split_bonus.c Bonus/utils/ft_atoi_bonus.c Bonus/utils/ft_strncmp_bonus.c Bonus/utils/ft_strshr_bonus.c Bonus/utils/ft_strtrim_bonus.c\
				Bonus/ray_casting/hooks_bonus.c Bonus/ray_casting/ray_casting_bonus.c Bonus/ray_casting/ray_casting_utils_bonus.c \
				Bonus/ray_casting/Castrays_bonus.c Bonus/ray_casting/Castrays2_bonus.c Bonus/ray_casting/3D_randring_bonus.c\
				Bonus/parsing/checker_bonus.c Bonus/parsing/parsing_bonus.c Bonus/parsing/rgb_check_bonus.c Bonus/parsing/utils_bonus.c Bonus/parsing/parsing2_bonus.c \
				Bonus/parsing/map_check_bonus.c Bonus/parsing/alloc_map_bonus.c Bonus/utils/ft_exit_bonus.c Bonus/ray_casting/loading_images_bonus.c Bonus/parsing/utils2_bonus.c\
				Bonus/ray_casting/mini_map_bonus.c \

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
OBJ			=	$(SRC:.c=.o)
OBJB			=	$(SRC_B:.c=.o)
NAME			=	cub3D
BONUS		=	cub3D_bonus
MLX_FLAGS		=	-I ./MLX42/include -L ./MLX42/build -L/Users/$(USER)/.brew/opt/glfw/lib -lMLX42 -lglfw
MLX_P		=	./MLX42/build

all			:	mlx $(NAME)

bonus		:	mlx $(BONUS)

mlx			:	$(MLX_P) $(MLX_P)/libmlx42.a

$(MLX_P)		:
			cmake -S ./MLX42 -B $(MLX_P)
$(MLX_P)/libmlx42.a :
				make -C $(MLX_P)

Bonus/%.o			:	Bonus/%.c Bonus/cub3d_bonus.h
			$(CC) $(FLAGS) -c $< -o $@

Mandatory/%.o			:	Mandatory/%.c Mandatory/cub3d.h
			$(CC) $(FLAGS) -c $< -o $@

$(NAME)		:	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(BONUS)		:	$(OBJB)
			$(CC) $(FLAGS) $(OBJB) $(MLX_FLAGS) -o $(BONUS)


clean		:
			rm -rf $(OBJ) $(OBJB)
fclean		:	clean
			rm -rf $(NAME) $(BONUS)

re			:	fclean all