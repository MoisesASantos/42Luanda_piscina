# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosantos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 10:48:37 by mosantos          #+#    #+#              #
#    Updated: 2024/11/06 10:48:54 by mosantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)
LIB_NAME = libft.a

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	@echo "Criando a biblioteca $@..."
	@ar rcs $@ $^
	@echo "Biblioteca $@ criada com sucesso."

%.o: $(SRC_DIR)/%.c
	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removendo arquivos objeto..."
	@rm -f $(OBJ_FILES)

fclean: clean
	@echo "Removendo a biblioteca $@..."
	@rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
