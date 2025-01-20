##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## task01
##

SRC	=	my_putchar.c	\
		my_isneg.c	\
		my_put_nbr.c	\
		my_swap.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_getnbr.c	\
		my_sort_in_array.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_is_prime.c	\
		my_find_prime_sup.c	\
		my_strcpy.c	\
		my_strncpy.c	\
		my_revstr.c	\
		my_strstr.c	\
		my_strcmp.c	\
		my_strncmp.c	\
		my_strupcase.c	\
		my_strlowcase.c	\
		my_strcapitalize.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isupper.c	\
		my_str_isprintable.c	\
		my_showstr.c 	\
		my_showmem.c 	\
		my_strcat.c	\
		my_strncat.c	\
                conv_to_hex.c   \
                conv_to_octal.c \
                mini_printf.c   \
                print_diff_base.c \
                init_func.c     \
                print_basics.c  \
                my_put_float.c  \
                print_float_nbr.c \
                my_scient_write.c \
                my_scient_write_upper.c \
                my_put_unsigned_nbr.c   \
                conv_ptr.c      \
                my_is_nbr.c     \
                init_specifier.c        \
                print_character.c       \
                print_plus.c    \
                my_floatscient.c        \
                my_put_float_without.c  \
		my_params_to_array.c	\
		check_nbr.c	\
		my_show_word_array.c	\
		my_str_to_word_array.c	\



OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME_H	=	my.h

CFLAGS	=	-Wall -Wextra -Werror


all :		$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../../
		cp $(NAME_H) ../../include

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../../$(NAME)
	rm -f ../../$(NAME_H)

re:	fclean all

.PHONY: all clean fclean re
