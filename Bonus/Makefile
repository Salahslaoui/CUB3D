# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 09:15:18 by ozahdi            #+#    #+#              #
#    Updated: 2025/02/08 20:59:41 by ozahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_B		=	main_bonus.c\
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				utils/ft_strcmp.c utils/ft_lstadd_back_bonus.c utils/ft_lstnew_bonus.c\
				utils/ft_split.c utils/ft_atoi.c utils/ft_strncmp.c utils/ft_strshr.c utils/ft_strtrim.c\
				ray_casting/hooks.c ray_casting/mini_map_bonus.c ray_casting/ray_casting.c \
				ray_casting/ray_casting_utils.c ray_casting/Castrays.c ray_casting/Castrays2.c ray_casting/3D_randring.c\
				parsing/checker.c parsing/parsing.c parsing/rgb_check.c parsing/utils.c parsing/parsing2.c \
				parsing/map_check.c parsing/alloc_map.c  ray_casting/loading_images.c utils/ft_exit.c\

FLAGS		=	-Wall -Wextra -Werror
CC			=	cc
OBJ_B		=	$(SRC_B:.c=.o)
NAME			=	cub3D_bonus
MLX_FLAGS		=	-I ../MLX42/include -L ../MLX42/build \
				-L/Users/$(USER)/.brew/opt/glfw/lib -lMLX42 -lglfw
MLX_P		=	../MLX42/build

all			:	mlx $(NAME)

mlx			:	$(MLX_P) $(MLX_P)/libmlx42.a

$(MLX_P)		:
			cmake -S ../MLX42 -B $(MLX_P)
$(MLX_P)/libmlx42.a :
				make -C $(MLX_P)

$(NAME)		:	$(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(MLX_FLAGS) -o $(NAME)

%.o			:	%.c cub3d_bonus.h
			$(CC) $(FLAGS) -c $< -o $@

clean		:
			rm -rf $(OBJ_B)
fclean		:	clean
			rm -rf $(NAME)

re			:	fclean all