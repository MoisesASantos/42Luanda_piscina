# Compilador
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Arquivos
NAME = hello
OBJS = hello.o hellofunction.o

# Regra principal
all: $(NAME)

# Como construir o executável
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# Como compilar cada .c em .o
hello.o: hello.c hello.h
	$(CC) $(CFLAGS) -c hello.c -o hello.o

hellofunction.o: hellofunction.c hello.h
	$(CC) $(CFLAGS) -c hellofunction.c -o hellofunction.o

# Limpa arquivos objeto
clean:
	rm -f *.o

# Limpa tudo (objetos + executável)
fclean: clean
	rm -f $(NAME)

# Recompila do zero
re: fclean all

