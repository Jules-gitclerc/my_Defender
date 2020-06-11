##
## EPITECH PROJECT, 2019
## my_defender
## File description:
## Makefile
##

CC = gcc

SRCS = ./src/main.c \
	   ./src/enemy/tools_enemy.c \
	   ./src/enemy/ia_enemy.c \
	   ./src/enemy/gest_enemy.c \
	   ./src/enemy/clock_enemy.c \
	   ./src/vague/set_vague.c \
	   ./src/map/create_map.c \
	   ./src/tower/gest_tower.c \
	   ./src/tower/tools_tower.c \
	   ./src/menu/menu.c \
	   ./src/menu/tools_menu.c \
	   ./src/gest_score/read_score.c \
	   ./src/menu/load_stick.c \
	   ./src/menu/tools_load_stick.c \
	   ./src/map/portal.c \
	   ./src/map/heart.c \
	   ./src/map/coins.c \
	   ./src/tower/cost_tower.c \
	   ./src/tower/anime_tower.c \
	   ./src/tower/gest_event_tower.c \
	   ./src/tower/gestion_coord_bad_tower.c \
	   ./src/tower/fire_tower.c \
	   ./src/game/ges_gmae_board.c \
	   ./src/vague/tools_wave.c \
	   ./src/tower/fill_calc.c \
	   ./src/menu/pause.c \
	   ./src/menu/tools_pause.c \
	   ./src/menu/game_over.c \
	   ./src/tower/ges_ball.c \
	   ./src/tower/tools_ball.c \
	   ./src/destroy.c \
	   ./src/tireh.c \
	   ./src/tower/set_circle.c

LIBPATH = ./lib/my/

OBJ = $(SRCS:.c=.o)

NAME = my_defender

RM = rm -f

LIBFLAGS = -L lib/my -lmy

CFLAGS = -g -W -Wall -Wextra -I include/ -Ilib/my/ -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio -l m

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBPATH) all
	$(CC) $(OBJ) $(CFLAGS) $(LIBFLAGS) -o $(NAME)

clean :
	$(RM) $(NAME)
	$(RM) $(OBJ)

fclean : clean
	make -C $(LIBPATH) fclean

re : clean fclean all

.PHONY: all clean fclean re
