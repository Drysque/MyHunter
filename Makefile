##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for My Hunter
##

CC	=	gcc

RMF     =       rm -f

CFLAGS	=	-I./include/

SRC	=	Create_My_Window.c

MAIN	=	main.c

CSFML	=	-l csfml-graphics -l csfml-system -l csfml-window

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	$(CC) $(MAIN) $(SRC) $(CSFML) $(CFLAGS)

clean:	;

fclean:	clean
	$(RMF) $(NAME)

re:	fclean all
