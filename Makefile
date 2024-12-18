SRC = test.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_strcmp.c \
	  utils/ft_lstadd_back_bonus.c utils/ft_lstnew_bonus.c utils/ft_split.c utils/ft_atoi.c \
	  utils/ft_strncmp.c main.c plug.c graph/ray.c \

SRCP = 

OBJ = $(SRC:.c=.o)

OBJP = $(SRCP:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

NAME = cub3d

NAME2 = libplug.so

all :  $(NAME2) $(NAME)


$(NAME2): $(OBJP)
	$(CC) $(FLAGS) -shared $(OBJP) -Lmlx -lmlx -framework OpenGL -framework AppKit -o libplug.so 
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%o: %c cub3d.h
	$(CC) $(FLAGS) -Imlx -fPIC -c $< -o $@

clean :
	rm -rf $(OBJ) $(OBJP)
fclean : clean
	rm -rf $(NAME) $(NAME2)

re : fclean all
