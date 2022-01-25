##
## EPITECH PROJECT, 2021
## cpoolday10 task01
## File description:
## Makefile
##

SRC =		fct_vaput.c		\
		fct_vaput_base.c		\
		fct_vaput_dec.c		\
		my_putchar.c		\
		my_strstr.c		\
		my_isneg.c		\
		my_strcmp.c		\
		my_put_nbr.c		\
		my_strncmp.c		\
		my_swap.c		\
		my_strupcase.c		\
		my_putstr.c		\
		my_strlowcase.c		\
		my_strlen.c		\
		my_strcapitalize.c	\
		my_getnbr.c		\
		my_str_isalpha.c	\
		my_sort_int_array.c	\
		my_str_isnum.c		\
		my_compute_power_rec.c	\
		my_str_islower.c	\
		my_compute_square_root.c\
		my_str_isupper.c	\
		my_is_prime.c		\
		my_str_isprintable.c	\
		my_find_prime_sup.c	\
		my_showstr.c		\
		my_strcpy.c		\
		my_showmem.c		\
		my_strncpy.c		\
		my_strcat.c		\
		my_revstr.c		\
		my_strncat.c 	\
		memset.c		\
		my_put_error.c		\
		my_printf.c 		\
		my_get_base.c

OBJ =		$(SRC:.c=.o)

NAME =		libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp -f $(NAME) ../
	mkdir -p ../../include/
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../libmy.a
	rm -f $(NAME)

re:	fclean all
