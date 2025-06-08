# Variables
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# Directories
SRCS_DIR	= srcs
INCLUDES_DIR= includes

# Source files (assuming .c extension)
SRCS		= $(addprefix $(SRCS_DIR)/, \
			  ft_putchar.c \
			  ft_putstr.c \
			  ft_strcmp.c \
			  ft_strlen.c \
			  ft_swap.c)

# Object files
OBJS		= $(SRCS:.c=.o)

# Header files
INCLUDES	= -I$(INCLUDES_DIR)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
