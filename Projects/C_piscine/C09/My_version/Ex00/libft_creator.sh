/bin/bash

cc -Wall -Werror -Wextr ft_putchar.c ft_putstr.c ft_strcmp.c ft_swap.c ft_strlen.c

ar rcs libtf.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_swap.o ft_strlen.o

rm -f *.o
