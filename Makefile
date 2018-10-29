NAME = Wolf3d
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEAD = Wolf3d.h keys.h

SRC = main.c set_up_mlx_stuff.c init_info.c end_program.c keyboard.c mouse.c need_update.c move_player.c fill_skybox.c image.c read_maps.c raycast.c draw_walls.c color.c xpm_to_charmap.c char_map_to_local.c char_map_to_local2.c load_textures.c 

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

$(NAME) : Wolf3d.h
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft ./minilibx2/libmlx.a -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	make -C libft/ clean
	$(RM) $(OBJ) *.gch

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
