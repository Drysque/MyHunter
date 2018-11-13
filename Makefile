##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for My Hunter
##

CC	=	gcc

RMF     =       rm -f

SRC	=	;

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RMF) $(OBJ)

fclean:	clean
	$(RMF) $(NAME)

re:	fclean all
