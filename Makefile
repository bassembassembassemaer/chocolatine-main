##
## EPITECH PROJECT, 2025
## Makefile my_printf
## File description:
## Makefile my_printf
##

.PHONY: all clean fclean re tests_run unit_tests

SRC = src/my_printf.c \
      src/arguments_detect/conversions.c \
      src/arguments_detect/error_detect.c \
      src/arguments_detect/flags.c \
      src/arguments_detect/length_operators.c \
      src/arguments_detect/precision.c \
      src/arguments_detect/width.c \
      src/aux/convert_base.c \
      src/aux/my_compute_power_rec.c \
      src/aux/my_getnbr.c \
      src/aux/my_putchar.c \
      src/aux/my_putstr.c \
      src/aux/my_revstr.c \
      src/aux/my_strcat.c \
      src/aux/my_strcmp.c \
      src/aux/my_strcpy.c \
      src/aux/my_strdup.c \
      src/aux/my_strlen.c \
      src/aux/my_strncat.c \
      src/func/for_conversions_bis.c \
      src/func/for_conversions.c \
      src/func/for_flags.c \
      src/func/e_conv.c \
      src/func/g_conv.c \
      src/func/putnbr.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)
	$(REMOVE) unit_tests
	$(REMOVE) a.out
	$(REMOVE) *.gcno
	$(REMOVE) *.gcda

re: fclean $(NAME)

unit_tests: fclean $(NAME)
	cc -o unit_tests $(SRC) tests/tests.c --coverage -lcriterion -L./ -lmy -g3

tests_run: unit_tests
	./unit_tests
