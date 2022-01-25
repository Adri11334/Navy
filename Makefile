##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=	src/maps/check_file.c		\
			src/maps/display_boats.c	\
			src/maps/gen_map.c			\
			src/maps/player_boats.c		\
			src/maps/player_shoot.c		\
			src/signals/init.c			\
			src/signals/navy.c			\
			src/signals/position.c		\
			src/signals/gameloop.c		\
			src/signals/utils.c			\

TEST_SRC	=

TEST_OBJ	=	$(TEST_SRC:.c=.o)

MAIN_SRC	=	src/main.c

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)		\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

LDLIB	=	-lmy
LIBMY	=	libmy.a

CPPFLAGS	+=	-I./include/
CFLAGS		+=
LDFLAGS		+= -L ./lib

all:	$(NAME)

$(NAME):	$(LIBMY) $(OBJ) $(MAIN_OBJ)
	gcc -o $(NAME) $(OBJ) $(MAIN_OBJ) $(CPPFLAGS) $(LIB) $(LDLIB) $(LDFLAGS)

$(LIBMY):
	make -C lib/my/

unit_tests:		fclean
unit_tests:		$(LIBMY)
unit_tests:		CFLAGS		+= --coverage
unit_tests:		LDFLAGS		+= --coverage -lcriterion
unit_tests:		$(TEST_OBJ) $(OBJ)
	gcc -o $@ $(SRC) $(TEST_SRC) $(LIB) $(LDLIB)  $(LDFLAGS) $(CPPFLAGS)
	./$@

debug:	CPPFLAGS += -g
debug:	NAME = debug
debug:
	all
	valgrind ./debug

gcovr:
	gcovr --exclude tests
	gcovr --exclude tests --branches

clean:
	make clean -C./lib/my/
	rm -f $(OBJ) $(MAIN_OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	make fclean -C ./lib/my/
	rm -f unit_tests
	rm -f $(TEST_OBJ)
	rm -f $(NAME)
	rm -f *.gc*

re:	fclean all

.PHONY:	all clean fclean re debug
