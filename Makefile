##
## EPITECH PROJECT, 2024
## my_radar
## File description:
## Makefile
##

SRC     =	src/main.c				\
                src/main_loop.c				\
		src/is_flying.c				\
		src/print_usage.c			\
		src/init/init_window.c			\
		src/init/init_entities.c       		\
		src/init/init_plane.c			\
		src/init/init_corners.c			\
		src/init/init_tower.c			\
		src/init/set_img.c			\
		src/init/create_circle.c		\
		src/quadtree/check_intersection.c	\
		src/draw/draw_tower.c			\
		src/draw/draw_plane.c			\
		src/draw/draw_entities.c		\
		src/draw/draw_quadtree.c		\
		src/draw/draw_bg.c			\
		src/move/get_movement.c			\
		src/move/move_plane.c			\
		src/quadtree/quadtree.c			\
		src/destroy_entities.c			\

OBJ	=       $(SRC:.c=.o)

LIB_PATH        =       lib/my/

NAME    =       SkyRadar

CFLAGS 	=	-Wall -Wextra

FLAG    =      	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIB     =       -L. -lmy -lm

all :  build_lib cc

build_lib:
	make -C $(LIB_PATH)

cc :    $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAG) $(LIB)

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re:     fclean all
