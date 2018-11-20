##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for My Hunter
##

CC	=	gcc

RMF     =       rm -f

CFLAGS	=	-I./include/

SRC	=	src/my_hunter.c	\
		src/create_my_window.c	\
		src/create_my_ressources.c	\
		src/update_my_bird.c	\
		src/update_my_cursor.c	\
		src/check_shot.c	\
		src/destroy_my_ressources.c	\
		src/close_my_window.c

MAIN	=	src/main.c

CSFML	=	-l csfml-graphics -l csfml-system -l csfml-window

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(CSFML) $(CFLAGS)

clean:	;

fclean:	clean
	$(RMF) $(NAME)

re:	fclean all
