SRC			=	main.c\
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				utils/ft_strcmp.c utils/ft_lstadd_back_bonus.c utils/ft_lstnew_bonus.c\
				utils/ft_split.c utils/ft_atoi.c utils/ft_strncmp.c utils/ft_strshr.c utils/ft_strtrim.c\
				ray_casting/hooks.c ray_casting/ray_casting.c ray_casting/ray_casting_utils.c \
				ray_casting/Castrays.c ray_casting/Castrays2.c ray_casting/3D_randring.c\
				parsing/checker.c parsing/parsing.c parsing/rgb_check.c parsing/utils.c parsing/parsing2.c \
				parsing/map_check.c parsing/alloc_map.c utils/ft_exit.c ray_casting/loading_images.c parsing/utils2.c\

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
OBJ			=	$(SRC:.c=.o)
NAME			=	cub3D
MLX_FLAGS		=	-I ../MLX42/include -L ../MLX42/build \
				-L/Users/$(USER)/.brew/opt/glfw/lib -lMLX42 -lglfw
MLX_P		=	../MLX42/build

all			:	mlx $(NAME)

mlx			:	$(MLX_P) $(MLX_P)/libmlx42.a

$(MLX_P)		:
			cmake -S ../MLX42 -B $(MLX_P)
$(MLX_P)/libmlx42.a :
				make -C $(MLX_P)

$(NAME)		:	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o			:	%.c cub3d.h
			$(CC) $(FLAGS) -c $< -o $@

clean		:
			rm -rf $(OBJ)
fclean		:	clean
			rm -rf $(NAME)

re			:	fclean all