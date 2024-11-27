SRC = test.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_strcmp.c \
	  utils/ft_lstadd_back_bonus.c utils/ft_lstnew_bonus.c utils/ft_split.c utils/ft_atoi.c \
	  utils/ft_strncmp.c plug.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = cub3d

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework Cocoa -framework OpenGL -framework IOKit -o $@
%o: %c cub3d.h
	$(CC) $(FLAGS) -c -fPIC $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : fclean all
