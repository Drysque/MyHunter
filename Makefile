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
		src/check_args.c	\
		src/create_my_window.c	\
		src/create_my_ressources.c	\
		src/init_my_ressources.c	\
		src/update_my_bird.c	\
		src/update_my_cursor.c	\
		src/check_shot.c	\
		src/destroy_my_ressources.c	\
		src/close_my_window.c

MAIN	=	src/main.c

TESTSRC	=	tests/test_my_hunter.c

NAME	=	my_hunter

CRIT	=	unit_tests

CSFML	=	-l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

CRITFLAGS	=	--coverage -lcriterion

GCOVR	=	*.gc*

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(CSFML) $(CFLAGS)

tests_run: re
	 $(CC) -o $(CRIT) $(SRC) $(TESTSRC) $(CRITFLAGS) $(CSFML) $(CFLAGS)
	 ./$(CRIT)

clean:
	$(RMF) $(GCOVR)

fclean:	clean
	$(RMF) $(NAME)
	$(RMF) $(CRIT)

re:	fclean all
